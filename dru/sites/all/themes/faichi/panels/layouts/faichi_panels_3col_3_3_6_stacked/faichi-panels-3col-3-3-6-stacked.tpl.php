<?php
/**
 * @file
 * Panels Omega 3 Col 3-3-6 Stacked
 *
 * Copyright (c) 2010-2011 Board of Trustees, Leland Stanford Jr. University
 * This software is open-source licensed under the GNU Public License Version 2 or later
 * The full license is available in the LICENSE.TXT file at the root of this repository
 */

?>
<div class="panel-display omega-3col-3-3-6" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>

	<?php if ($content['top']): ?>
	  <div class="panel-panel grid-12 panel-region-preface">
		  <div class="inside"><?php print $content['top']; ?></div>
	  </div>
	<?php endif; ?>
  
  <div class="panel-panel grid-3 panel-region-sidebar-second">
	  <div class="inside"><?php print $content['left']; ?></div>
  </div>
  <div class="panel-panel grid-3 panel-region-sidebar-first">
	  <div class="inside"><?php print $content['middle']; ?></div>
  </div>
  <div class="panel-panel grid-6 panel-region-content">
	  <div class="inside"><?php print $content['right']; ?></div>
  </div>
  
	<?php if ($content['bottom']): ?>
	  <div class="panel-panel grid-12 panel-region-postscript">
	    <div class="inside"><?php print $content['bottom']; ?></div>
	  </div>
	<?php endif; ?>

</div>
