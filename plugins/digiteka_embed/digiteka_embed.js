(function ($) {

  Drupal.wysiwyg.plugins.digiteka_embed = {

    /**
     * Return whether the passed node belongs to this plugin (note that "node" in this context is a JQuery node, not a Drupal node).
     *
     * We identify code managed by this FOO plugin by giving it the HTML class
     * 'wysiwyg_plugin_digiteka-embed'.
     */
    isNode: function (node) {
      return ($(node).is('img.wysiwyg_plugin_digiteka-embed'));
    },

    /**
     * Invoke is called when the toolbar button is clicked.
     *
     * @param {object} data - The data object.
     * @param {object} settings - The settings object.
     * @param {number} instanceId - The instanceId value.
     */
    invoke: function (data, settings, instanceId) {
      var content = '';
      if (data.format === 'html') {
        content = this._getPlaceholder(settings);
      }
      else {
        content = '<!--digiteka-placeholder-->';
      }
      if (typeof content !== 'undefined') {
        Drupal.wysiwyg.instances[instanceId].insert(content);
      }
    },

    /**
     * Replace all <!--digiteka-placeholder--> tags with the icon.
     *
     * @param {string} content - The content value.
     * @param {object} settings - The settings object.
     *
     * @return {string} The html content.
     */
    attach: function (content, settings) {
      content = content.replace(/<!--digiteka-placeholder-->/g, this._getPlaceholder(settings));
      return content;
    },

    /**
     * Replace the icons with <!--digiteka-placeholder--> tags in content upon detaching editor.
     *
     * @param {string} content - The content value.
     *
     * @return {string} The html content.
     */
    detach: function (content) {
      var $content = $('<div>' + content + '</div>');
      $.each($('img.wysiwyg_plugin_digiteka-embed', $content), function (i, elem) {
        elem.parentNode.insertBefore(document.createComment('digiteka-placeholder'), elem);
        elem.parentNode.removeChild(elem);
      });
      return $content.html();
    },

    /**
     * Helper function to return a HTML placeholder.
     * Here we provide an image to visually represent the hidden HTML in the Wysiwyg editor.
     *
     * @param {object} settings - The settings object.
     * 
     * @return {string} The html for the image.
     */
    _getPlaceholder: function (settings) {
      return '<img src="' + settings.path + '/images/digiteka.png" width="50px" alt="&lt;--digiteka-placeholder--&gt;" title="&lt;--digiteka-placeholder--&gt;" class="wysiwyg_plugin_digiteka-embed" />';
    }
  };

})(jQuery);
