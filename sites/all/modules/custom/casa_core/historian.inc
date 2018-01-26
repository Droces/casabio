<?php

  namespace Drupal\Casabio\casa_core;
  
  /**
   * 
   */
  class historian {

    // of type entity_metadata_wrapper
    protected $entity = NULL;
    
    /**
     * 
     */
    function __construct(\EntityDrupalWrapper $entity = NULL) {
      if ($entity) {
        $this->setEntity($entity);
      }
    }

    /**
     * @param EntityDrupalWrapper $entity
     */
    public function setEntity(\EntityDrupalWrapper $entity) {
      // dpm($entity->raw(), '$entity->raw()');
      if (gettype($entity) !== 'object') {
        throw new \Exception('Parameter `entity` must be an object of type `EntityDrupalWrapper`', 1);
      }
      if (get_class($entity) !== 'EntityDrupalWrapper') {
        throw new \Exception('Parameter `entity` must be of type `EntityDrupalWrapper`', 1);
      }
      if (! isset($entity->field_history)) {
        throw new \Exception('Parameter `entity`, of bundle `'
          . $entity->getBundle() . '`, must have field `field_history`', 1);
      }
      $this->entity = $entity;
    }



    /**
     * @param int $time
     *   (optional) Unix timestamp
     * @param string $type
     *   Name of the event.
     * @param $uid
     *   ID of the user that triggered the event.
     * @param boolean $is_unique
     *   If this event may be added to the history more than once.
     */
    public function addEvent($time = NULL, $type, $uid, $is_unique = TRUE) {
      // dpm($this->entity->raw(), '$this->entity->raw()');

      // If event type's name was provided, get it's term id instead
      if (! is_numeric($type)) {
        $type = array_keys(taxonomy_get_term_by_name($type, 'history_event_types'))[0];
      }

      $time = $time ? $time : time();
      $history = $this->getHistory();
      if ($is_unique && $this->findEvent($type)) {
        return NULL;
      }

      // if ($this->entity->getType() === 'user') {}

      $event = [
        'datetime' => $time,
        'type' => $type,
        'user' => $uid,
      ];
      // dpm($event, '$event');
      $this->entity->field_history[] = json_encode($event);
      // dpm($this->entity->raw(), '$this->entity->raw()');

      try {
        // $this->entity->save(); // @TODO MUST FIX THIS
      }
      catch (Exception $e) {
        print 'Caught exception: ' .  $e->getMessage() . "\n";
      }
      // dpm($this->entity->raw(), '$this->entity->raw()');
    }



    /**
     * Searches through the history for a particular event and returns it.
     * 
     * @return object[]
     *   An array of history events
     */
    //  [{"datetime":1504879724,"type":107845,"user":"1"}]
    public function getHistory($decoded = TRUE) {
      $field_values = $this->entity->field_history->value();
      // dpm($field_values, '$field_values');
      foreach ($field_values as $index => $event) {
        $field_values[$index] = json_decode($event);
      }
      // dpm($field_values, '$field_values');
      return $field_values;
    }



    /**
     * Searches through the history for a particular event and returns it.
     * 
     * @param int|string $event
     * 
     * @return object
     *   An event in the format {'datetime' => , 'type' => , 'user' => }
     */
    public function findEvent($type) {
      if (! is_numeric($type)) {
        $type = array_keys(taxonomy_get_term_by_name($type, 'history_event_types'))[0];
      }

      $history = $this->getHistory();
      // dpm($history, '$history');
      foreach ($history as $event) {
        if (! property_exists($event, 'type')) {
          continue;
        }
        if ($event->type == $type) {
          return $event;
        }
      }
      return NULL;
    }



    /**
     * @todo Filter (parameter) by entity type / bundle
     * 
     * @param string $type
     *   Name of the event type
     * @param boolean $decoded
     *   If the results should just decoded into objects. If FALSE, returns a JSON string.
     * @param boolean $count
     *   If the results should just be counted instead of fetched
     */
    public static function getAllHistoryValues($type = NULL, $user_uid, $decoded = TRUE, $count = FALSE) {
      // dpm($type, '$type');
      // dpm($user_uid, '$user_uid');
      if (! is_numeric($type)) {
        $type = array_keys(taxonomy_get_term_by_name($type, 'history_event_types'))[0];
      }

      $query = db_select('field_revision_field_history', 'f')
        ->fields('f', array('entity_id', 'field_history_value'));

      if ($type) {
        $query->condition('field_history_value', '%"type":' . $type . '%', 'LIKE');
      }

      if ($user_uid) {
        $query->condition('field_history_value', '%"user":"' . $user_uid . '"%', 'LIKE');
      }

      $query = $query->execute();

      if ($count) {
        $events = $query->rowCount();
      }
      else {
        $events = $query->fetchAllKeyed();
      }
      // dpm($events, '$events');

      if (!$count && $decoded) {
        foreach ($events as $eid => $event) {
          $events[$eid] = json_decode($event);
        }
      }

      return $events;
    }
  }