<?php
// $Id: messaging.admin.inc,v 1.1.2.13.2.3.2.13 2010/05/24 16:45:01 jareyero Exp $
/**
 * @file
 * Messaging Framework - Admin UI
 * 
 * This file includes the settings page and administration for message templates
 * 
 * By Development Seed, http://wwww.developmentseed.org
 */

/**
 * Admin settings form
 */
function messaging_admin_settings() {
  // Get plug-in information and produce big warning if none enabled.
  $method_info = messaging_method_info();
  if (!$method_info) {
    // Get message from requirements
    if ($reqs = messaging_requirements('runtime')) {
      drupal_set_message($reqs['messaging']['value'], 'error');
    }
    $form = array();
  }
  else {
    $form['methods'] = array(
      '#type' => 'fieldset',
      '#title' => t('Sending methods'),
      '#theme' => 'messaging_admin_methods_table',
    );
  
    $options = $enabled = array();
    foreach ($method_info as $method => $info) {
      $options[$method] = '';
      if ($info['enabled']) {
        $enabled[] = $method;
      }
      $method_names[$method] = $info['title'];
      $form['methods']['name'][$method]['#value'] = $info['title'];
      $form['methods']['description'][$method]['#value'] = $info['description'];
    }
    $form['methods']['messaging_method_enabled'] = array(
      '#type' => 'checkboxes',
      '#options' => $options,
      '#default_value' => $enabled,
    );
    $form['methods']['messaging_default_method'] = array(
      '#type' => 'radios',
      '#options' => $options,
      '#default_value' => variable_get('messaging_default_method', ''),
    );
    $form['#validate'][] = 'messaging_admin_settings_validate';
  }
  // We use settings form so other modules can add here their settings
  return system_settings_form($form);
}

/**
 * Preprocess method settings into variables
 */
function messaging_admin_settings_validate($form, &$form_state) {
  // Check the default method is enabled  
  $default = $form_state['values']['messaging_default_method'];
  if (!$default || empty($form_state['values']['messaging_method_enabled'][$default])) {
    form_set_error('', t('You must select on of the enabled methods as the default one.'));
  }
}

/**
 * Default sending methods settings
 */
function messaging_admin_method_settings() {
  // Sending methods settings
  if ($info = messaging_method_info()) {
    $form['methods'] = array('#theme' => 'messaging_admin_settings_table');
    foreach ($info as $method => $options) {
      $options += array('log' => 0, 'queue' => 0);
      $key = 'messaging_method_'.$method;
      // This will preserve settings for disabled modules
      $form['methods'][$key]['#tree'] = TRUE;
      $form['methods'][$key]['title'] = array(
        '#title' => t('Method'),
        '#value' => $options['title'],
      );
      // Display name
      $form['methods'][$key]['name'] = array(
        '#title' => t('Name'),
        '#type' => 'textfield',
        '#default_value' => $options['name'],
        '#size'          => 20,
      );
      // Log and queue can be enabled by 'Messaging Tool', disabled otherwise
      $form['methods'][$key]['queue'] = array('#type' => 'value', '#value' => 0);
      $form['methods'][$key]['log'] = array('#type' => 'value', '#value' => 0);
    }
  } else {
    $form['warning'] = array('#value' => t('You should enable some messaging method plug-ins for this to work.'));
  }
  $form = system_settings_form($form);
  // Refresh strings after update if translation enabled
  if (module_exists('i18nstrings')) {
    $form['#submit'][] = 'messaging_locale_refresh';
  }
  return $form;
}

/**
 * Incoming message form
 */
function messaging_admin_test_post_form() {
  global $user;

  // Availbable sending methods
  $form['method'] = array(
    '#title' => t('Send method'),
    '#type' => 'select',
    '#options' => messaging_method_list(),
    '#default_value' => messaging_method_default(),
  );
  $form['to'] = array(
    '#type' => 'textfield',
    '#title' => t('Destination'),
    '#size' => 20,
    '#autocomplete_path' => 'user/autocomplete',
    '#default_value' => $user->name,
    '#description' => t('Enter a user name or a destination address for this method.'),
  );
  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#size' => 20,
    '#default_value' => t('Test message'),
  );
  $form['body'] = array(
    '#type' => 'textarea',
    '#title' => t('Body'),
    '#default_value' => t("Hello.\n\nThis is a test message from !site_name", array('!site_name' => variable_get('site_name', 'Drupal'))),
  );
    
  $form['submit'] = array('#type' => 'submit', '#value' => t('Send'));
  
  return $form;
}

/**
 * Post test message
 */
function messaging_admin_test_post_form_submit($form, $form_state) {
  global $user;

  messaging_log_start();
  
  // Convert body in array of lines
  $body = split("\n", $form_state['values']['body']);
  $body = array_map('trim', $body);
  $method = $form_state['values']['method'];

  $message = messaging_message_build(array(
    'type' => 'test',
    'subject' => $form_state['values']['subject'],
    'body' => $body,
    'method' => $method,
    'priority' => 1, // So it won't be queued
  ));
  
  // Destination may be account or plain parameter/s
  $destination = $form_state['values']['to'];
  $send_method = messaging_send_method($method);
  
  if ($account = user_load(array('name' => $destination))) {
    $vars['!name'] = theme('username', $account);
    if ($address = $send_method->get_user_address($account)) {
      drupal_set_message(t('Found address @address for user !name', array('@address' => $address) + $vars));
      $result = messaging_message_send_user($account, $message, $method);
    }
    else {
      drupal_set_message(t('Cannot find a valid address for user !name', $vars), 'error');
    }
    
  } elseif ($send_method->address_validate($destination)) {
    drupal_set_message(t('Sending message to address: @address', array('@address' => $destination)));
    $result = messaging_message_send(array($destination), $message, $method);
  }
  else {
    drupal_set_message(t('The destination is not a user name nor a valid address.'), 'error');
  }
  if (isset($result)) {
    if ($result) {
      drupal_set_message(t('The message was sent successfully.'));
    }
    else {
      drupal_set_message(t('The message sending failed.'), 'warning');
    }
  }
  // Check some conditions and let the user know
  if (!$send_method->enabled) {
    drupal_set_message(t('This sending method is disabled, thus regular messages will be discarded.'), 'warning');
  }
}

/**
 * Settings for filter and formatting for each sending method
 * 
 * This page requires 'administer filters' permission so it doesn't need further checking
 */
function messaging_admin_method_filters() {
  // Add information about input formats
  messaging_include('text.inc');
  // List of Input formats
  $format_options = $filter_options = array();
  foreach (filter_formats() as $format) {
    $format_options[$format->format] = $format->name;
  }
  $format_default = filter_resolve_format(FILTER_FORMAT_DEFAULT);
  // List of messaging filters
  $filter_info = array();
  foreach (messaging_text_filter_info() as $key => $filter) {
    $filter_options[$key] = $filter['name'];
    $filter_info[] = array($filter['name'], $filter['description']);
  }
  // We add this last for it not bo be default
  $filter_options[''] = t('No filter (Insecure)');
  $format_options[''] = t('No filter (Insecure)');
  $form['filter_info'] = array(
    '#title' => t('Available filters'),
    '#type' => 'item',
    '#value' => theme('table', array(), $filter_info),
  );
  // Sending methods settings
  if ($info = messaging_method_info()) {
    $form['methods'] = array('#theme' => 'messaging_admin_settings_table');
    foreach ($info as $method => $options) {
      $key = 'messaging_filters_'.$method;
      // This will preserve settings for disabled modules
      $form['methods'][$key]['#tree'] = TRUE;
      $form['methods'][$key]['title'] = array(
        '#title' => t('Method'),
        '#value' => $options['title'],
      );
      // Output filter applied to message body
      $form['methods'][$key]['body_format'] = array(
        '#title' => t('Format filter'),
        '#type' => 'select',
        '#default_value' => isset($options['body_format']) ? $options['body_format'] : $format_default,
        '#options' => $format_options,
      );
      // Final filter applied to message body
      $form['methods'][$key]['filter'] = array(
        '#title' => t('Final filter'),
        '#type' => 'select',
        '#default_value' => $options['filter'],
        '#options' => $filter_options,
      );
    }
  } else {
    $form['warning'] = array('#value' => t('You should enable some messaging method plug-ins for this to work.'));
  }
  
  $form = system_settings_form($form);

  return $form;
}

/**
 * Format main methods settings form
 */
function theme_messaging_admin_methods_table($elements) {
  $output = '';
  $header = array(t('Enabled'), t('Default'), t('Name'), t('Description'));
  $rows = array();
  foreach (element_children($elements['name']) as $key) {
    $rows[] = array(
      drupal_render($elements['messaging_method_enabled'][$key]),
      drupal_render($elements['messaging_default_method'][$key]),
      '<strong>' . drupal_render($elements['name'][$key]) . '</strong>',
      drupal_render($elements['description'][$key]),   
    );
  }
  $output .= theme('table', $header, $rows);
  $output .= drupal_render($elements);
  return $output;
}

/**
 * Theme settings as table
 */
function theme_messaging_admin_settings_table($elements) {
  if (isset($elements['#table_header'])) {
    $header = $elements['#table_header'];
    $extract_headers = FALSE;
  }
  else {
    $header = array();
    $extract_headers = TRUE;
  }
  $rows = array();
  foreach (element_children($elements) as $index) {
    $row = array();
    foreach (element_children($elements[$index]) as $key) {
      if ($elements[$index][$key]['#type'] == 'value') continue;
      if (isset($elements[$index][$key]['#title'])) {
        if ($extract_headers) {
          // Extract the titles from elements
          $header[] = $elements[$index][$key]['#title'];
        }   
        unset($elements[$index][$key]['#title']);
      }
      $row[] = drupal_render($elements[$index][$key]);
    }
    $rows[] = $row;
    $extract_headers = FALSE;
  }
  if ($rows) {
    $output = theme('table', $header, $rows);
  }
  else {
    $output = t('No data available');
  }
  $output .= drupal_render($elements);
  return $output;  
}