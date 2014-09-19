<?php
/**
 * @file
 * Preprocess panels color preset and theme hook suggestions.
 */

/**
 * Implements hook_preprocess_panels_pane().
 */
function ovpred_preprocess_panels_pane(&$variables) {

  if(isset($variables['pane']->style['style'])) {
    if($variables['pane']->style['style'] === 'wrapper') {
      $variables['theme_hook_suggestions'][] = 'panels_pane__wrapper';
      $variables['attributes_array']['class'][] = $variables['pane']->style['settings']['preset_color'];
    }
  }

  return $variables;
}
