<?php
$enable = array(
  'site_frontpage' => 'node',
  'site_name' => 'Gosh, Michelle is Witty',
  'site_slogan' => "Witty things I think of that really impress me.",
  'cache_lifetime' => "900",
  'block_cache' => 1,
  'cache' => 1,
);
foreach ($enable as $var => $setting) {
  if (!is_numeric($var)) {
    // set the site variables.
    variable_set($var, $setting);
  }
}
