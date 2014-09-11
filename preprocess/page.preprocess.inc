<?php

/**
 * Implements hook_preprocess_page().
 */
function ovpred_preprocess_page(&$variables) {

  // Add the base page class into page template.
  $variables['classes_array'][] = "l-page";

  // Add a "panelized" class to panelized nodes.
  if(!empty($variables['node']->panelizer)) {
    $variables['classes_array'][] = "panelized";

    // Add the panel layout being used.
    if($variables['node']->panelizer['default']->display->layout) {
      $variables['classes_array'][] = $variables['node']->panelizer['default']->display->layout;
    }

  }
}
