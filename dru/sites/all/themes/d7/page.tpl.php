
    <!-- header starts-->
    <div id="header-wrap">
      <div id="header" class="container_16">
        <div id="header-main">
          <h1 id="logo-text"><a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><span><?php print $site_name; ?></span></a></h1>
          <p id="slogan"><?php print $site_slogan ?></p>
        </div><!-- navigation -->
              <?php print render($page['header']); ?>
        <div id="nav">
          <?php if($main_menu): ?>
            <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
          <?php endif ?>
        </div>
      </div>
    </div>
    <!-- header ends here -->

    <!-- content starts -->
    <div id="content-wrapper" class="container_16">
      <?php if ($breadcrumb): ?>
        <div id="breadcrumb" class = "grid_16"><?php print $breadcrumb; ?></div>
      <?php endif; ?>
      <?php print $messages; ?>
      <!-- main -->
      <div id="main" class="grid_8">

        <a id="main-content"></a>
        <?php print render($title_prefix); ?>
        <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
        <?php print render($page['help']); ?>
        <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
        <?php print render($page['content']); ?>
        <?php print $feed_icons; ?>
      </div>
      <!-- main ends here -->

      <!-- sidebars starts here -->
      <div id="sidebars" class="grid_8">

        <!-- left sidebar starts here -->
        <div class="grid_4 alpha sidebar-left">

          <?php print render($page['sidebar_first']); ?>
        </div>
        <!-- left sidebar ends here -->

        <!-- right sidebar starts here -->
        <div class="grid_4 omega sidebar-right">

          <?php print render($page['sidebar_second']); ?>

        </div>
        <!-- right sidebar ends here -->

      </div>
      <!-- sidebars end here -->

    </div>
    <!-- content ends here -->

    <!-- footer starts here -->
    <div id="footer-wrapper" class="container_16">

      <!-- footer top starts here -->
      <div id="footer-content">

        <!-- footer left starts here -->
        <div class="grid_8" id="footer-left">
          <?php print render($page['footer_left']); ?>
        </div>
        <!-- footer left ends here -->

        <!-- footer right starts here -->
        <div class="grid_8" id="footer-right">
          <?php print render($page['footer_right']); ?>
        </div>
        <!-- footer right ends here -->

      </div>
      <!-- footer top ends here -->

      <!-- footer bottom starts here -->
      <div id="footer-bottom">
        <p class="bottom-left"><?php print render($variables['footer_message']) ; ?></p>
        <ul class="links secondary-links">
          <li><a href="index.html" title="" class="active">Home</a></li>
          <li><a href="rss.xml" title="">RSS Feed</a></li>
          <li><a href="http://jigsaw.w3.org/css-validator/check/referer" title="">CSS</a></li>
          <li><a href="http://validator.w3.org/check/referer" title="">XHTML</a></li>
        </ul>
      </div>
      <!-- footer bottom ends here -->

    </div>
    <!-- footer ends here -->
