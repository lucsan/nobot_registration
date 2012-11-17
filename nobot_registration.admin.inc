<?php

/**
 * @file
 * admin interface included functions
 *
 */

/**
 * Implements hook_form().
 *
 * Admin forms return system_settings_form to drupal_get_form
 * this tells drupal it is an admin form.
 * If the default_value = variable_get variable name is the same as
 * the form element, the form does not need a submit function as everything is
 * handled by drupal.
 */
function nobot_registration_admin_form() {
  $nobot_check = variable_get('nobot_registration_nobot_check' , 0);
  $nobot_field = variable_get('nobot_registration_nobot_field', '');

  $amhuman_check = variable_get('nobot_registration_amhuman_check' , 0);
  $amhuman_field = variable_get('nobot_registration_amhuman_field', '');

  $proof_check = variable_get('nobot_registration_proof_check' , 0);
  $proof_field = variable_get('nobot_registration_proof_field', '');
  $proof_length = variable_get('nobot_registration_proof_length', 12);

  // Instructions
  $insts = "Instructions:- </br>Go to " . l("Profile fields", "admin/config/people/accounts/fields") . "</br>"
  . "Add a new  field, Save.</br>"
  . "Make sure you check - Display on form and Use field label in the field editor. Save.</br>"
  . "Return to this page and put the field name in the box below.</br>"
  . "(Note: if you are using 'Prove it' this is the minimum length the response can be.)";

  $form['nobot_registration_nobot_item'] = array(
    '#type' => 'item',
    '#title' => $insts,
    '#description' => t("You will need to do this for each of the elements you wish to use.")
  );

  // No bot
  $form['nobot_registration_nobot_check'] = array(
    '#type' => 'checkbox',
    '#title' => 'No bot check',
    '#default_value' => $nobot_check,
    '#description' => 'Check this to use the no bot checkbox on your registration form',
  );


  $form['nobot_registration_nobot_field'] = array(
    '#type' => 'textfield',
    '#title' => t("No bot checkbox field"),
    '#default_value' => $nobot_field,
    '#description' => t("This should be something like field_nobot_checkbox (boolean field, single on/off widget), The default value should not be checked."),
    '#states' => array(
      'visible' => array(
        ':input[name="nobot_registration_nobot_check"]' => array(
        'checked' => TRUE),
      ),
    ),
  );

  // Am human
  $form['nobot_registration_amhuman_check'] = array(
    '#type' => 'checkbox',
    '#title' => 'Am Human check',
    '#default_value' => $amhuman_check,
    '#description' => 'Check this to use the am human checkbox on your registration form',
  );

  $form['nobot_registration_amhuman_field'] = array(
    '#type' => 'textfield',
    '#title' => t("Am Human checkbox field"),
    '#default_value' => $amhuman_field,
    '#description' => t("This should be something like field_amhuman_checkbox (boolean field, single on/off widget), The default value should be checked."),
    '#states' => array(
      'visible' => array(
        ':input[name="nobot_registration_amhuman_check"]' => array(
        'checked' => TRUE),
      ),
    ),
  );

  // Proof

  $form['nobot_registration_proof_check'] = array(
    '#type' => 'checkbox',
    '#title' => 'Prove your human',
    '#default_value' => $proof_check,
    '#description' => 'Check this to use the prove it text on your registration form',
  );

  $form['nobot_registration_proof_field'] = array(
    '#type' => 'textfield',
    '#title' => t("Prove your human text field"),
    '#default_value' => $proof_field,
    '#description' => t("This should be something like field_proof_integer (text field)"),
    '#states' => array(
      'visible' => array(
        ':input[name="nobot_registration_proof_check"]' => array(
        'checked' => TRUE),
      ),
    ),
  );

 $form['nobot_registration_proof_length'] = array(
    '#type' => 'textfield',
    '#title' => 'Prove your human text length (minimum).',
    '#default_value' => $proof_length,
    '#description' => 'Check this to use the prove it text on your registration form',
    '#size' => 1,
    '#states' => array(
      'visible' => array(
        ':input[name="nobot_registration_proof_check"]' => array(
        'checked' => TRUE),
      ),
    ),
  );



  return system_settings_form($form);
}