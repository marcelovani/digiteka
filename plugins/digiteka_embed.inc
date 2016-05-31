<?php

/**
 * @file
 * Digiteka / Wysiwyg API integration.
 */

/**
 * Implements hook_wysiwyg_plugin().
 */
function digiteka_digiteka_embed_plugin() {
  $plugins['digiteka_embed'] = array(
    'title' => t('Digiteka'),
    'icon file' => 'digiteka.png',
    'icon title' => t('Insert Digiteka Video'),
    'settings' => array(),
  );
  return $plugins;
}
