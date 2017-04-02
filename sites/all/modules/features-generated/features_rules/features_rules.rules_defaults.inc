<?php
/**
 * @file
 * features_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function features_rules_default_rules_configuration() {
  $items = array();
  $items['rules_assign_new_users_contributor_role'] = entity_import('rules_config', '{ "rules_assign_new_users_contributor_role" : {
      "LABEL" : "Assign new users contributor role",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : { "user_insert" : [] },
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "account" ],
            "roles" : { "value" : { "4" : "4", "5" : "5", "3" : "3" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "account" ], "roles" : { "value" : { "4" : "4" } } } }
      ]
    }
  }');
  return $items;
}
