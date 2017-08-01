<?php
/**
 * @file
 * Contains the administrative functions of the digiteka module.
 */

/**
 * Implements hook_admin_settings_form().
 *
 * Used to configure Digiteka.
 */
function digiteka_admin_settings_form() {
  $form = array();

  // Service id.
  $form['digiteka_mdtk'] = array(
    '#type' => 'textfield',
    '#title' => t('Digiteka Id'),
    '#default_value' => variable_get('digiteka_mdtk'),
    '#description' => '',
  );

  // Paragraph position.
  $form['digiteka_position'] = array(
    '#type' => 'textfield',
    '#title' => t('Position'),
    '#default_value' => digiteka_position(),
    '#description' => t('The paragraph after which to automatically add Digiteka.'),
  );

  // Minimum number of pragraphs.
  $form['digiteka_min_paragraphs'] = array(
    '#type' => 'textfield',
    '#title' => t('Minimum number of paragraphs'),
    '#default_value' => digiteka_min_paragraphs(),
    '#description' => t('The minimum number of paragraphs required for Digiteka to be added automatically.'),
  );

  // Which bundles can have Digiteka.
  $form['digiteka_bundles'] = array(
    '#type' => 'textfield',
    '#title' => t('Bundles'),
    '#default_value' => digiteka_admin_bundles(),
    '#description' => t('Which bundles can have Digiteka, separated by commas.'),
  );

  $form['#submit'][] = 'digiteka_admin_settings_form_submit';
  return system_settings_form($form);
}

/**
 * Save the bundles csv as an array.
 */
function digiteka_admin_settings_form_submit($form, &$form_state) {
  if (!empty($form_state['values']['digiteka_bundles'])) {
    $bundles = explode(',', $form_state['values']['digiteka_bundles']);
    $bundles = array_map('trim', $bundles);
    $form_state['values']['digiteka_bundles'] = $bundles;
  }
}

/**
 * Load the bundles array as a csv.
 */
function digiteka_admin_bundles() {
  $bundles = digiteka_bundles();

  return implode(',', $bundles);
}
