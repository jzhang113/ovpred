<?php

/**
 * Implements hook_preprocess_html().
 */
function ovpred_preprocess_html(&$variables) {

  // Include typkit assets
  drupal_add_js('http://use.typekit.net/hfk5jun.js');
  drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));

  // Add the term vocabulary as a body class for term pages
  if (arg(0) == 'taxonomy' && arg(1) == 'term') {
    $term = taxonomy_term_load(arg(2));
    $variables['classes_array'][] = 'vocabulary-' . strtolower($term->vocabulary_machine_name);
  }
}
