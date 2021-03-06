<?php
// $Id$

/**
 * Field handler to present a product edit link.
 */
class views_handler_field_commerce_product_link_edit extends views_handler_field_commerce_product_link {
  function construct() {
    parent::construct();

    $this->additional_fields['type'] = 'type';
    $this->additional_fields['uid'] = 'uid';
  }

  function render($values) {
    // Ensure the user has access to edit this product.
    $product = new stdClass();
    $product->product_id = $values->{$this->aliases['product_id']};
    $product->type = $values->{$this->aliases['type']};
    $product->uid = $values->{$this->aliases['uid']};

    if (!commerce_product_access('update', $product)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    return l($text, 'admin/commerce/products/' . $product->product_id . '/edit', array('query' => drupal_get_destination()));
  }
}
