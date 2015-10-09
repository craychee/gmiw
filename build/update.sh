#!/bin/bash
set -e
path=$(dirname "$0")
source $path/common.sh

echo "Enabling dependencies.";
$drush en $(echo gmiw | tr ':' ' ')
echo "Revert features, run manifests, and clearing caches.";
$drush fra
$drush kw-m
$drush cc drush
echo "Set basic site variables";
$drush scr $base/build/scripts/set_site_variables.php
echo "Clearing caches one last time.";
$drush cc all
