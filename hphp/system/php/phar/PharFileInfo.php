<?hh // partial
// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.pharfileinfo.php )
 *
 * The PharFileInfo class provides a high-level interface to the contents
 * and attributes of a single file within a phar archive.
 *
 */
class PharFileInfo extends SplFileInfo {

  private $name;
  private ?__SystemLib\ArchiveEntryStat $stat;

  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.construct.php )
   *
   * This should not be called directly. Instead, a PharFileInfo object is
   * initialized by calling Phar::offsetGet() through array access.
   *
   * @param string $entry The full url to retrieve a file. If you wish to
   *                      retrieve the information for the file my/file.php
   *                      from the phar boo.phar, the entry should be
   *                      phar://boo.phar/my/file.php.
   */
  public function __construct($entry, $data) {
    if (!($data is __SystemLib\ArchiveEntryStat)) {
      throw new UnexpectedValueException(
        "PharFileInfo can only be constructed via Phar::offsetGet()"
      );
    }
    parent::__construct($entry);
    $this->name = $entry;
    $this->stat = $data;
  }

  public function getPathName() {
    return $this->name;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.chmod.php )
   *
   * PharFileInfo::chmod() allows setting of the executable file permissions
   * bit, as well as read-only bits. Writable bits are ignored, and set at
   * runtime based on the phar.readonly INI variable. As with all
   * functionality that modifies the contents of a phar, the phar.readonly
   * INI variable must be off in order to succeed if the file is within a
   * Phar archive. Files within PharData archives do not have this
   * restriction.
   *
   * @perms      mixed   permissions (see chmod())
   *
   * @return     mixed   No value is returned.
   */
  public function chmod($perms) {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.compress.php )
   *
   * This method compresses the file inside the Phar archive using either
   * bzip2 compression or zlib compression. The bzip2 or zlib extension must
   * be enabled to take advantage of this feature. In addition, if the file
   * is already compressed, the respective extension must be enabled in order
   * to decompress the file. As with all functionality that modifies the
   * contents of a phar, the phar.readonly INI variable must be off in order
   * to succeed if the file is within a Phar archive. Files within PharData
   * archives do not have this restriction.
   *
   * @compression_type
   *             mixed
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function compress($compression_type) {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.decompress.php )
   *
   * This method decompresses the file inside the Phar archive. Depending on
   * how the file is compressed, the bzip2 or zlib extensions must be enabled
   * to take advantage of this feature. As with all functionality that
   * modifies the contents of a phar, the phar.readonly INI variable must be
   * off in order to succeed if the file is within a Phar archive. Files
   * within PharData archives do not have this restriction.
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function decompress() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.delmetadata.php )
   *
   * Deletes the metadata of the entry, if any.
   * No parameters.
   *
   * @return     mixed   Returns TRUE if successful, FALSE if the entry had
   *                     no metadata. As with all functionality that modifies
   *                     the contents of a phar, the phar.readonly INI
   *                     variable must be off in order to succeed if the file
   *                     is within a Phar archive. Files within PharData
   *                     archives do not have this restriction.
   */
  public function delMetadata() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.getcrc32.php )
   *
   * This returns the crc32() checksum of the file within the Phar archive.
   *
   * @return     mixed   The crc32() checksum of the file within the Phar
   *                     archive.
   */
  public function getCRC32() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from
   * http://php.net/manual/en/pharfileinfo.getcompressedsize.php )
   *
   * This returns the size of the file within the Phar archive. Uncompressed
   * files will return the same value for getCompressedSize as they will with
   * filesize()
   *
   * @return     mixed   The size in bytes of the file within the Phar
   *                     archive on disk.
   */
  public function getCompressedSize(): int {
    return $this->stat->compresedSize;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.getmetadata.php )
   *
   * Return meta-data that was saved in the Phar archive's manifest for this
   * file.
   *
   * @return     mixed   any PHP variable that can be serialized and is
   *                     stored as meta-data for the file, or NULL if no
   *                     meta-data is stored.
   */
  public function getMetadata() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.getpharflags.php )
   *
   * This returns the flags set in the manifest for a Phar. This will always
   * return 0 in the current implementation.
   *
   * @return     mixed   The Phar flags (always 0 in the current
   *                     implementation)
   */
  public function getPharFlags() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.hasmetadata.php )
   *
   * Returns the metadata of a file within a phar archive.
   * No parameters.
   *
   * @return     mixed   Returns FALSE if no metadata is set or is NULL, TRUE
   *                     if metadata is not NULL
   */
  public function hasMetadata() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.iscrcchecked.php )
   *
   * This returns whether a file within a Phar archive has had its CRC
   * verified.
   *
   * @return     mixed   TRUE if the file has had its CRC verified, FALSE if
   *                     not.
   */
  public function isCRCChecked() {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.iscompressed.php )
   *
   * This returns whether a file is compressed within a Phar archive with
   * either Gzip or Bzip2 compression.
   *
   * @compression_type
   *             mixed   One of Phar::GZ or Phar::BZ2, defaults to any
   *                     compression.
   *
   * @return     mixed   TRUE if the file is compressed within the Phar
   *                     archive, FALSE if not.
   */
  public function isCompressed($compression_type) {
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/pharfileinfo.setmetadata.php )
   *
   * PharFileInfo::setMetadata() should only be used to store customized
   * data in a file that cannot be represented with existing information
   * stored with a file. Meta-data can significantly slow down the
   * performance of loading a phar archive if the data is large, or if there
   * are many files containing meta-data. It is important to note that file
   * permissions are natively supported inside a phar; it is possible to set
   * them with the PharFileInfo::chmod() method. As with all functionality
   * that modifies the contents of a phar, the phar.readonly INI variable
   * must be off in order to succeed if the file is within a Phar archive.
   * Files within PharData archives do not have this restriction.
   *
   * Some possible uses for meta-data include passing a user/group that
   * should be set when a file is extracted from the phar to disk. Other uses
   * could include explicitly specifying a MIME type to return. However, any
   * useful data that describes a file, but should not be contained inside of
   * it may be stored.
   *
   * @metadata   mixed   Any PHP variable containing information to store
   *                     alongside a file
   *
   * @return     mixed   No value is returned.
   */
  public function setMetadata($metadata) {
  }

  // Custom methods used by Phar class internally

  public function getSize(): int {
    return $this->stat->size;
  }

  public function getTimestamp(): int {
    return $this->stat->timestamp;
  }
}
