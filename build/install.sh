#!/bin/bash
set -e
path=$(dirname "$0")
source $path/common.sh

chmod -R +w $base/www/sites/default
chmod -R +w $base/cnf

echo "Symlink settings.php into our Drupal."
ln -sf $base/cnf/settings.php $base/www/sites/default/
echo "Installing Drupal like a boss."
$drush si --account-pass=admin
source $path/update.sh
