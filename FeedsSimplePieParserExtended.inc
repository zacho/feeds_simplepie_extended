<?php
// 

/**
 * Class definition for Common Syndication Parser.
 *
 * Parses RSS and Atom feeds.
 */
class FeedsSimplePieParserExtended extends FeedsSimplePieParser {

  /**
   * Allow extension of FeedsSimplePie item parsing.
   */
  protected function parseExtensions(&$item, $simplepie_item) {
    $page_contents = file_get_contents( $item['url'] );
    $item['link_contents'] = $page_contents;
  }

  /**
   * Return mapping sources.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'link_contents' => array(
        'name' => t('Link Contents'),
        'description' => t('Fetched contents of the <Link> of the feed item.'),
      ),
     );
  }

}
