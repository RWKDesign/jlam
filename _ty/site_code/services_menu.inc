<div style="width: 900px; margin: 10px;">


<?php
$menu = render(drupal_get_form('services_form'));
print $menu;

function services_form() {
 
$form['services_item'] = array(
  '#type' => 'hierarchical_select',
  '#title' => t('Service:'),
  '#size' => 1,
  '#config' => array(
    'module' => 'hs_taxonomy',
    'params' => array(
      'vid' => 2,
      'exclude_tid' => NULL,
    ),
    'save_lineage'    => 0,
    'enforce_deepest' => 1,
    'entity_count'    => 0,
    'require_entity'  => 0,
    'resizable'       => 0,
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => t('Main category'),
        1 => t('Subcategory'),
        2 => t('Third level category'),
      ),
    ),
    'dropbox' => array(
      'status'   => 0,
      'title'    => t('All selections'),
      'limit'    => 0,
      'reset_hs' => 1,
    ),
    'editability' => array(
      'status'           => 0,
      'item_types'       => array(),
      'allowed_levels'   => array(
        0 => 1,
        1 => 1,
        //2 => 0,
      ),
      'allow_new_levels' => 0,
      //'max_levels'       => 3,
    ),
    // These settings cannot be configured through the UI: they can only be
    // overridden through code.
    'animation_delay'    => 400,
    'special_items'      => array(),
    'render_flat_select' => 0,
  ),
  '#default_value' => '83',
); 

return $form;
}


?>

</div>



<script type="text/javascript">

jQuery(document).ready(function() {
  setInterval(applyListener, 1000);
});

function applyListener() {
  jQuery('#edit-services-item-hierarchical-select-selects-0').change(doStuff);
}

function doStuff() {
  var aValue = jQuery('#edit-services-item-hierarchical-select-selects-0 :selected').val();
  alert ('Stuff done - value is ' + aValue);
}

</script>
