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
    $prism_namespace_1_2 = 'http://prismstandard.org/namespaces/basic/1.2/';
    $prism_namespace_2_0 = 'http://prismstandard.org/namespaces/basic/2.0/';
    $prism_namespace_2_1 = 'http://prismstandard.org/namespaces/basic/2.1/';

    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'url')) {
      $item['prism_url'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    }
    if (!empty($prism_pubdate)) {
      if ($prism_timestamp = strtotime($prism_pubdate)) {
        $item['timestamp'] = $prism_timestamp;
      }
      $item['prism_publicationDate'] = $prism_pubdate;
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'number')) {
      $item['prism_number'] = $value[0]['data'];
    }
    
    if ($value = $simplepit_item->get_item_tags($prism_namespace_2_1,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_2_0,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepit_item->get_item_tags($prism_namespace_1_2,'section')) {
      $item['prism_section'] = $value[0]['data'];
    }
    
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
