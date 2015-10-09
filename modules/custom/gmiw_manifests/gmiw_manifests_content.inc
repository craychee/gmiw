<?php

/**
 * Callback for ehs_manifests.
 */
function gmiw_manifests_content_add() {

  $values = array(
    'type' => 'basic_page',
    'uid' => 1,
    'status' => 1,
    'comment' => 0,
    'promote' => 1,
  );

  $entity = entity_create('node', $values);

  $ewrapper = entity_metadata_wrapper('node', $entity);
  $ewrapper->title->set('The Code Speaks for Itself');
  $body_content = "Judge my wit by my code.

    <a html='https://github.com/craychee/gmiw'>Here</a> is my code on github.

    'Whoa,' you are thinking. 'This isn\'t Pantheon-ready code. Where and how are you building and deploying this thing?'

    I am so impressed by your inquisitive nature. Since you asked, I have a tightly defined and enforced release strategy that leverages a CI Server to test and the build and deploy only a production artifact.
    I know you want to see what that looks like:
    <a html='https://circleci.com/gh/craychee/gmiw/tree/master'>Walla</a>.

    ";

  $ewrapper->body->set(array('value' => $body_content));
  $ewrapper->body->summary->set('I can\'t believe how awesome I am.');
  $ewrapper->save();
}
