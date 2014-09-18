<?php

/**
 * Implements hook_preprocess_page().
 */
function ovpred_preprocess_page(&$variables) {

  // Pass the $needs_container variable to the page template
  $needs_container = true;

  // Add the base page class into page template.
  $variables['classes_array'][] = "l-page";

  // Add a "panelized" class to panelized nodes.
  if(!empty($variables['node']->panelizer)) {
    $variables['classes_array'][] = "panelized";
    $needs_container = false;

    // Add the panel layout being used.
    if($variables['node']->panelizer['default']->display->layout) {
      $variables['classes_array'][] = $variables['node']->panelizer['default']->display->layout;
    }
  }

  if (panels_get_current_page_display()) {
    $needs_container = false;
  }

  $variables['content_container'] = $needs_container;
}
