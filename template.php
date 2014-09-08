<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * ovpred theme.
 */

/**
 * Implements theme_breadcrumb().
 */
function ovpred_breadcrumb(&$variables) {
  $output = '';
  if (!empty($variables['breadcrumb'])) {
    $variables['breadcrumb'][] = drupal_get_title();
    $output = '<div id="breadcrumb" class="breadcrumb-container clearfix"><h2 class="element-invisible">You are here</h2><ul class="breadcrumb">';
    $switch = array('odd' => 'even', 'even' => 'odd');
    $zebra = 'even';
    $last = count($variables['breadcrumb']) - 1;
    $seperator = '<span class="breadcrumb-seperator">/</span>';
    foreach ($variables['breadcrumb'] as $key => $item) {
      $zebra = $switch[$zebra];
      $attributes['class'] = array('depth-' . ($key + 1), $zebra);
      if ($key == 0) {
        $attributes['class'][] = 'first';
      }
      if ($key == $last) {
        $attributes['class'][] = 'last';
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . '';
      }
      else
        $output .= '<li' . drupal_attributes($attributes) . '>' . $item . '</li>' . $seperator;
      }
    $output .= '</ul></div>';
    return $output;
  }
}

/**
 * Implements theme_preprocess_node().
 */
function ovpred_preprocess_node(&$variables) {
  // Set a $feature variable to use in templates.
  if($variables['view_mode'] == 'feature') {
    $variables['feature'] = TRUE;
  }
  else {
    $variables['feature'] = FALSE;
  }
  if($variables['type'] == 'featured_content') {
    $variables['feature_link'] = $variables['field_feature_link'][LANGUAGE_NONE][0]['url'];
  }
}
