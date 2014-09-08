<?php

/**
 * Implements hook_preprocess_node().
 */
function ovpred_preprocess_node(&$variables) {
  if($variables['type'] == 'featured_content') {
    $variables['feature_link'] = $variables['field_feature_link'][LANGUAGE_NONE][0]['url'];
  }
}
