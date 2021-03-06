<?php

/**
 * Implementation of hook_ds_default_settings().
 */
function nurani_general_ds_default_settings() {
  $data = array(
    'nd' => array(
      'comment' => array(
        'full' => array(
          'fields' => array(
            'title' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'header',
              'weight' => '-100',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'footer',
              'weight' => '-96',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'header',
              'weight' => '-99',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'translation_status' => array(
              'region' => 'middle',
              'weight' => '-97',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
      'discussion' => array(
        'discussion_participants' => array(
          'fields' => array(
            'field_texts' => array(
              'region' => 'disabled',
              'weight' => '-90',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_moderators' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'above',
            ),
            'field_translators' => array(
              'region' => 'middle',
              'weight' => '-97',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'above',
            ),
            'field_scholars' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'above',
            ),
            'field_exp_comments' => array(
              'region' => 'middle',
              'weight' => '-96',
              'format' => 'countdown',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'disabled',
              'weight' => '-91',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'ds_author_link',
              'css-class' => '',
              'label_value' => 'Moderator',
              'labelformat' => 'above',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
        'full' => array(
          'fields' => array(
            'field_texts' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'field_moderators' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => 'default',
              'css-class' => '',
              'label_value' => 'Moderators',
              'labelformat' => 'above',
            ),
            'field_translators' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'default',
              'css-class' => '',
              'label_value' => 'Translators',
              'labelformat' => 'above',
            ),
            'field_scholars' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'default',
              'css-class' => '',
              'label_value' => 'Scholars',
              'labelformat' => 'above',
            ),
            'field_exp_comments' => array(
              'region' => 'disabled',
              'weight' => '-89',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'disabled',
              'weight' => '-90',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'ds_author_link',
              'css-class' => '',
              'label_value' => 'Author',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'middle',
              'weight' => '-97',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-91',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'label_value' => 'Thoughts from the Moderator',
              'labelformat' => 'above',
            ),
            'translation_status' => array(
              'region' => 'middle',
              'weight' => '-96',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
      'response' => array(
        'full' => array(
          'fields' => array(
            'title' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'header',
              'weight' => '-100',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'footer',
              'weight' => '-96',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'header',
              'weight' => '-99',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'view_text' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'glossary_references' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'translation_status' => array(
              'region' => 'middle',
              'weight' => '-97',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
      'term' => array(
        'full' => array(
          'fields' => array(
            'field_part_of_speech' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'above',
            ),
            'field_translation_term' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
              'parent' => 'group_translations',
            ),
            'field_translation_context' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
              'parent' => 'group_translations',
            ),
            'group_translations' => array(
              'region' => 'middle',
              'weight' => '-97',
              'format' => 'ds_field',
              'css-class' => '',
              'labelformat' => 'above',
            ),
            'title' => array(
              'region' => 'disabled',
              'weight' => '-91',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'glossary_references' => array(
              'region' => 'middle',
              'weight' => '-96',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
      'text' => array(
        'title_body' => array(
          'fields' => array(
            'field_description' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'nd_title_h1_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-97',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'disabled',
              'weight' => '-96',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'view_text' => array(
              'region' => 'footer',
              'weight' => '-98',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
        'text_summary' => array(
          'fields' => array(
            'field_description' => array(
              'region' => 'disabled',
              'weight' => '-95',
              'format' => 'default',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'title' => array(
              'region' => 'middle',
              'weight' => '-100',
              'format' => 'nd_title_h1_link',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'author' => array(
              'region' => 'disabled',
              'weight' => '-94',
              'format' => 'ds_author_nolink',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'links' => array(
              'region' => 'disabled',
              'weight' => '-92',
              'format' => '',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'read_more' => array(
              'region' => 'disabled',
              'weight' => '-96',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'post_date' => array(
              'region' => 'disabled',
              'weight' => '-97',
              'format' => 'nd_post_date_long',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'body' => array(
              'region' => 'middle',
              'weight' => '-99',
              'format' => 'nd_bodyfield',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'translation_status' => array(
              'region' => 'disabled',
              'weight' => '-93',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
            'text_links' => array(
              'region' => 'middle',
              'weight' => '-98',
              'format' => 'ds_eval_code',
              'css-class' => '',
              'labelformat' => 'hidden',
            ),
          ),
          'status' => 2,
          'region_styles' => array(
            'header' => '',
            'left' => '',
            'middle' => '',
            'right' => '',
            'footer' => '',
          ),
        ),
      ),
    ),
  );
  return $data;
}
