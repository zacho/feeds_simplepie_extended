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
    //$page_contents = file_get_contents( $item['url'] );
    //$item['link_contents'] = $page_contents;
    
    // Catch data from PRISM namespaces.  Strangely,
    // There appear to be two plausible paths for each of three current versions,
    // So we have to make six checks per field.
    
    $prism_namespace_1_2 = 'http://prismstandard.org/namespaces/basic/1.2/';
    $prism_namespace_2_0 = 'http://prismstandard.org/namespaces/basic/2.0/';
    $prism_namespace_2_1 = 'http://prismstandard.org/namespaces/basic/2.1/';
    $prism_namespace_1_2_alt = 'http://prismstandard.org/namespaces/1.2/basic/';
    $prism_namespace_2_0_alt = 'http://prismstandard.org/namespaces/2.0/basic/';
    $prism_namespace_2_1_alt = 'http://prismstandard.org/namespaces/2.1/basic/';
    
    $simplepie_feed = $simplepie_item->get_feed();

    foreach ($simplepie_item->get_authors() as $author) {
      $item['all_authors'][] = $author->get_name();
    }

    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'doi')) {
      $item['prism_doi'] = $value[0]['data'];
    }
    
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'url')) {
      $item['prism_url'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'url')) {
      $item['prism_url'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'startingPage')) {
      $item['prism_startingPage'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'endingPage')) {
      $item['prism_endingPage'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'publicationName')) {
      $item['prism_publicationName'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'publicationDate')) {
      $prism_pubdate = $value[0]['data'];
    }
    
    if (!empty($prism_pubdate)) {
      if ($prism_timestamp = strtotime($prism_pubdate)) {
        $item['timestamp'] = $prism_timestamp;
      }
      $item['prism_publicationDate'] = $prism_pubdate;
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'volume')) {
      $item['prism_volume'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'number')) {
      $item['prism_number'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'number')) {
      $item['prism_number'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_item->get_item_tags($prism_namespace_2_1,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_1_alt,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_2_0_alt,'section')) {
      $item['prism_section'] = $value[0]['data'];
    } elseif ($value = $simplepie_item->get_item_tags($prism_namespace_1_2_alt,'section')) {
      $item['prism_section'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'issn')) {
      $item['prism_issn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'isPartOf')) {
      $isPartOf = $value[0]['data'];
    }
    if (!empty($isPartOf)) {
      if ($issnPos = strpos($isPartOf,'issn:')) {
        $issnPos = $issnPos + 5;
        $issn = substr($isPartOf,$issnPos);
        if (empty($item['prism_issn'])) {
          $item['prism_issn'] = $issn;
        }
      }
    }

    if ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'eIssn')) {
      $item['prism_eIssn'] = $value[0]['data'];
    }
    
    if ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_1_alt,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_2_0_alt,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    } elseif ($value = $simplepie_feed->get_feed_tags($prism_namespace_1_2_alt,'distributor')) {
      $item['prism_distributor'] = $value[0]['data'];
    }
    
  }

  /**
   * Return mapping sources.
   */
  public function getMappingSources() {
    return parent::getMappingSources() + array(
      'all_authors' => array(
        'name' => t('All Author Names'),
        'description' => t('All author names from SimplePie'),
      ),
      'prism_doi' => array(
        'name' => t('Prism: DOI'),
        'description' => t('Prism DOI'),
      ),
      'prism_url' => array(
        'name' => t('Prism: URL'),
        'description' => t('Prism URL'),
      ),
      'prism_startingPage' => array(
        'name' => t('Prism: Starting Page'),
        'description' => t('Prism Starting Page'),
      ),
      'prism_endingPage' => array(
        'name' => t('Prism: Ending Page'),
        'description' => t('Prism Ending Page'),
      ),
      'prism_publicationName' => array(
        'name' => t('Prism: Publication Name'),
        'description' => t('Prism Publication Name'),
      ),
      'prism_publicationDate' => array(
        'name' => t('Prism: Publication Date'),
        'description' => t('Prism Publication Date'),
      ),
      'prism_volume' => array(
        'name' => t('Prism: Issue Volume'),
        'description' => t('Prism Issue Volume'),
      ),
      'prism_number' => array(
        'name' => t('Prism: Issue Number'),
        'description' => t('Prism Issue Number'),
      ),
      'prism_section' => array(
        'name' => t('Prism: Section'),
        'description' => t('Prism Section'),
      ),
      'prism_issn' => array(
        'name' => t('Prism: ISSN'),
        'description' => t('Prism ISSN'),
      ),
      'prism_eIssn' => array(
        'name' => t('Prism: eISSN'),
        'description' => t('Prism eISSN'),
      ),
      'prism_distributor' => array(
        'name' => t('Prism: Distributor'),
        'description' => t('Prism Distributor'),
      ),
      'prism_issn' => array(
        'name' => t('Prism: ISSN'),
        'description' => t('Prism ISSN'),
      ),
      
      // 'link_contents' => array(
      //   'name' => t('Link Contents'),
      //   'description' => t('Fetched contents of the <Link> of the feed item.'),
      // ),
     );
  }

}
