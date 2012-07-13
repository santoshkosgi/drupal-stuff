<div id="mainWrapper">
  <?php include('includes/header.php'); ?>
  <div id="middleWrapper">
    <div class="homeOfferings">
        <img src="images/faichi-logo.png" alt="FaiChi" title="FaiChi" class="thumb" />
        <div class="content">
          <?php print render($page['content']); ?>
          <div class="clear"></div>
        </div>
    </div>
    <div class="homeBottomContent">
      <div class="ContentBox">
        <?php print render($page['content_first']); ?>
        <a href="#" class="readMore fr">Read More..</a>
      </div>
      <div class="ContentBox">
        <?php print render($page['content_second']); ?>
        <a href="#" class="readMore fr">Read More..</a>
      </div>
      <div class="ContentBox medium">
        <img src="images/360-degree.png" alt="" class="fr" /><div class="clear"></div>
        <?php print render($page['content_third']); ?>
      </div>
    </div>
      <div class="clear"></div>
  </div>
  <?php include('includes/footer.php'); ?>

</div>
