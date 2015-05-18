<?php
/**
 * @file
 * Template for the Erives layout.
 *
 * Variables:
 * - $css_id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 * panel of the layout. This layout supports the following sections:
 */
?>

<?php // Loops through each region, using the classes provided from the include
      // file. See erives.inc
?>
<div<?php print $attributes ?>>
  <?php foreach($content as $name => $item): ?>
    <?php if (!empty($item)): ?>
        <div<?php print drupal_attributes($region_attributes_array[$name])?>>
          <div class="wrapper-inner">
            <?php print $item ?>
          </div>
        </div>
    <?php endif; ?>
  <?php endforeach; ?>
</div>
