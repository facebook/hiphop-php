<?php
// This doc comment block generated by idl/sysdoc.php
/**
 * ( excerpt from http://php.net/manual/en/class.phar.php )
 *
 * The Phar class provides a high-level interface to accessing and
 * creating phar archives.
 *
 */
class Phar extends RecursiveDirectoryIterator
  implements Countable, ArrayAccess {

  const NONE = 0;
  const COMPRESSED = 0x0000F000;
  const GZ = 0x00001000;
  const BZ2 = 0x00002000;

  const SAME = 0;
  const PHAR = 1;
  const TAR = 2;
  const ZIP = 3;

  const MD5 = 0x0001;
  const SHA1 = 0x0002;
  const SHA256 = 0x0003;
  const SHA512 = 0x0004;
  const OPENSSL = 0x0010;

  const PHP = 1;
  const PHPS = 2;

  /**
   * A map from filename_or_alias => Phar object
   */
  private static $aliases = array();

  private $alias;
  private $fileInfo = array();
  private $fileOffsets = array();
  private $stub;
  private $manifest;
  private $contents;
  private $signature;

  private $count;
  private $apiVersion;
  private $archiveFlags;
  private $metadata;

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.construct.php )
   *
   *
   * @filename   mixed   Path to an existing Phar archive or to-be-created
   *                     archive. The file name's extension must contain
   *                     .phar.
   * @flags      mixed   Flags to pass to parent class
   *                     RecursiveDirectoryIterator.
   * @alias      mixed   Alias with which this Phar archive should be
   *                     referred to in calls to stream functionality.
   */
  public function __construct($filename, $flags = null, $alias = null) {
    if (!is_file($filename)) {
      throw new PharException("$filename is not a file");
    }
    $data = file_get_contents($filename);

    $halt_token = "\n__HALT_COMPILER();";
    $pos = strpos($data, $halt_token);
    if ($pos === false) {
      throw new PharException("__HALT_COMPILER(); must be declared in a phar");
    }
    $this->stub = substr($data, 0, $pos);

    $pos += strlen($halt_token);
    // *sigh*. We have to allow whitespace then ending the file
    // before we start the manifest
    while ($data[$pos] == ' ') {
      $pos += 1;
    }
    if ($data[$pos] == '?' && $data[$pos+1] == '>') {
      $pos += 2;
    }
    while ($data[$pos] == "\r") {
      $pos += 1;
    }
    while ($data[$pos] == "\n") {
      $pos += 1;
    }

    $this->contents = substr($data, $pos);
    $this->parsePhar($this->contents);

    if ($alias) {
      self::$aliases[$alias] = $this;
    }
    // From the manifest
    if ($this->alias) {
      self::$aliases[$this->alias] = $this;
    }
    // We also do filename lookups
    self::$aliases[$filename] = $this;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.addemptydir.php )
   *
   *
   * @dirname    mixed   The name of the empty directory to create in the
   *                     phar archive
   *
   * @return     mixed   no return value, exception is thrown on failure.
   */
  public function addEmptyDir($dirname) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.addfile.php )
   *
   *
   * @filename   mixed   Full or relative path to a file on disk to be added
   *                     to the phar archive.
   * @localname  mixed   Path that the file will be stored in the archive.
   *
   * @return     mixed   no return value, exception is thrown on failure.
   */
  public function addFile($filename, $localname = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.addfromstring.php )
   *
   *
   * @localname  mixed   Path that the file will be stored in the archive.
   * @contents   mixed   The file contents to store
   *
   * @return     mixed   no return value, exception is thrown on failure.
   */
  public function addFromString($localname, $contents) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.buildfromdirectory.php )
   *
   *
   * @base_dir   mixed   The full or relative path to the directory that
   *                     contains all files to add to the archive.
   * @regex      mixed   An optional pcre regular expression that is used to
   *                     filter the list of files. Only file paths matching
   *                     the regular expression will be included in the
   *                     archive.
   *
   * @return     mixed   Phar::buildFromDirectory() returns an associative
   *                     array mapping internal path of file to the full path
   *                     of the file on the filesystem.
   */
  public function buildFromDirectory($base_dir, $regex = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.buildfromiterator.php )
   *
   *
   * @iterator   mixed   Any iterator that either associatively maps phar
   *                     file to location or returns SplFileInfo objects
   * @base_directory
   *             mixed   For iterators that return SplFileInfo objects, the
   *                     portion of each file's full path to remove when
   *                     adding to the phar archive
   *
   * @return     mixed   Phar::buildFromIterator() returns an associative
   *                     array mapping internal path of file to the full path
   *                     of the file on the filesystem.
   */
  public function buildFromIterator($iterator, $base_directory = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.compressfiles.php )
   *
   *
   * @compression_type
   *             mixed   Compression must be one of Phar::GZ, Phar::BZ2 to
   *                     add compression, or Phar::NONE to remove
   *                     compression.
   *
   * @return     mixed   No value is returned.
   */
  public function compressFiles($compression_type) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.decompressfiles.php )
   *
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function decompressFiles() {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.compress.php )
   *
   *
   * @compression_type
   *             mixed   Compression must be one of Phar::GZ, Phar::BZ2 to
   *                     add compression, or Phar::NONE to remove
   *                     compression.
   * @file_ext   mixed   By default, the extension is .phar.gz or .phar.bz2
   *                     for compressing phar archives, and .phar.tar.gz or
   *                     .phar.tar.bz2 for compressing tar archives. For
   *                     decompressing, the default file extensions are .phar
   *                     and .phar.tar.
   *
   * @return     mixed   Returns a Phar object.
   */
  public function compress($compression_type, $file_ext = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.decompress.php )
   *
   *
   * @file_ext   mixed   For decompressing, the default file extensions are
   *                     .phar and .phar.tar. Use this parameter to specify
   *                     another file extension. Be aware that all executable
   *                     phar archives must contain .phar in their filename.
   *
   * @return     mixed   A Phar object is returned.
   */
  public function decompress($file_ext = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.converttoexecutable.php )
   *
   *
   * @format     mixed   This should be one of Phar::PHAR, Phar::TAR, or
   *                     Phar::ZIP. If set to NULL, the existing file format
   *                     will be preserved.
   * @compression_type
   *             mixed   This should be one of Phar::NONE for no
   *                     whole-archive compression, Phar::GZ for zlib-based
   *                     compression, and Phar::BZ2 for bzip-based
   *                     compression.
   * @file_ext   mixed   This parameter is used to override the default file
   *                     extension for a converted archive. Note that all
   *                     zip- and tar-based phar archives must contain .phar
   *                     in their file extension in order to be processed as
   *                     a phar archive.
   *
   *                     If converting to a phar-based archive, the default
   *                     extensions are .phar, .phar.gz, or .phar.bz2
   *                     depending on the specified compression. For
   *                     tar-based phar archives, the default extensions are
   *                     .phar.tar, .phar.tar.gz, and .phar.tar.bz2. For
   *                     zip-based phar archives, the default extension is
   *                     .phar.zip.
   *
   * @return     mixed   The method returns a Phar object on success and
   *                     throws an exception on failure.
   */
  public function convertToExecutable($format = 9021976, $compression_type = 9021976, $file_ext = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.converttodata.php )
   *
   * This method is used to convert an executable phar archive to either a
   * tar or zip file. To make the tar or zip non-executable, the phar stub
   * and phar alias files are removed from the newly created archive.
   *
   * If no changes are specified, this method throws a
   * BadMethodCallException if the archive is in phar file format. For
   * archives in tar or zip file format, this method converts the archive to
   * a non-executable archive.
   *
   * If successful, the method creates a new archive on disk and returns a
   * PharData object. The old archive is not removed from disk, and should be
   * done manually after the process has finished.
   *
   * @format     mixed   This should be one of Phar::TAR or Phar::ZIP. If set
   *                     to NULL, the existing file format will be preserved.
   * @compression_type
   *             mixed   This should be one of Phar::NONE for no
   *                     whole-archive compression, Phar::GZ for zlib-based
   *                     compression, and Phar::BZ2 for bzip-based
   *                     compression.
   * @file_ext   mixed   This parameter is used to override the default file
   *                     extension for a converted archive. Note that .phar
   *                     cannot be used anywhere in the filename for a
   *                     non-executable tar or zip archive.
   *
   *                     If converting to a tar-based phar archive, the
   *                     default extensions are .tar, .tar.gz, and .tar.bz2
   *                     depending on specified compression. For zip-based
   *                     archives, the default extension is .zip.
   *
   * @return     mixed   The method returns a PharData object on success and
   *                     throws an exception on failure.
   */
  public function convertToData($format = 9021976, $compression_type = 9021976, $file_ext = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.copy.php )
   *
   *
   * @newfile    mixed
   * @oldfile    mixed
   *
   * @return     mixed   returns TRUE on success, but it is safer to encase
   *                     method call in a try/catch block and assume success
   *                     if no exception is thrown.
   */
  public function copy($newfile, $oldfile) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.count.php )
   *
   *
   * @return     mixed   The number of files contained within this phar, or 0
   *                     (the number zero) if none.
   */
  public function count() {
    return $this->count;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.delete.php )
   *
   *
   * @entry      mixed   Path within an archive to the file to delete.
   *
   * @return     mixed   returns TRUE on success, but it is better to check
   *                     for thrown exception, and assume success if none is
   *                     thrown.
   */
  public function delete($entry) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.delmetadata.php )
   *
   *
   * @return     mixed   returns TRUE on success, but it is better to check
   *                     for thrown exception, and assume success if none is
   *                     thrown.
   */
  public function delMetadata() {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.extractto.php )
   *
   *
   * @pathto     mixed   Path within an archive to the file to delete.
   * @files      mixed   The name of a file or directory to extract, or an
   *                     array of files/directories to extract
   * @overwrite  mixed   Set to TRUE to enable overwriting existing files
   *
   * @return     mixed   returns TRUE on success, but it is better to check
   *                     for thrown exception, and assume success if none is
   *                     thrown.
   */
  public function extractTo($pathto, $files = null, $overwrite = false) {
    throw new UnexpectedValueException('phar is read-only');
  }

  public function getAlias() {
    return $this->alias;
  }

  public function getPath() {
    return $this->path;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getmetadata.php )
   *
   * Retrieve archive meta-data. Meta-data can be any PHP variable that can
   * be serialized.
   * No parameters.
   *
   * @return     mixed   any PHP variable that can be serialized and is
   *                     stored as meta-data for the Phar archive, or NULL if
   *                     no meta-data is stored.
   */
  public function getMetadata() {
    return $this->metadata;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getmodified.php )
   *
   * This method can be used to determine whether a phar has either had an
   * internal file deleted, or contents of a file changed in some way.
   * No parameters.
   *
   * @return     mixed   TRUE if the phar has been modified since opened,
   *                     FALSE if not.
   */
  public function getModified() {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getsignature.php )
   *
   * Returns the verification signature of a phar archive in a hexadecimal
   * string.
   *
   * @return     mixed   Array with the opened archive's signature in hash
   *                     key and MD5, SHA-1, SHA-256, SHA-512, or OpenSSL in
   *                     hash_type. This signature is a hash calculated on
   *                     the entire phar's contents, and may be used to
   *                     verify the integrity of the archive. A valid
   *                     signature is absolutely required of all executable
   *                     phar archives if the phar.require_hash INI variable
   *                     is set to true.
   */
  public function getSignature() {
    return null;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getstub.php )
   *
   * Phar archives contain a bootstrap loader, or stub written in PHP that
   * is executed when the archive is executed in PHP either via include:
   *
   * or by simple execution: php myphar.phar
   *
   * @return     mixed   Returns a string containing the contents of the
   *                     bootstrap loader (stub) of the current Phar archive.
   */
  public function getStub() {
    return $this->stub;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getversion.php )
   *
   * Returns the API version of an opened Phar archive.
   *
   * @return     mixed   The opened archive's API version. This is not to be
   *                     confused with the API version that the loaded phar
   *                     extension will use to create new phars. Each Phar
   *                     archive has the API version hard-coded into its
   *                     manifest. See Phar file format documentation for
   *                     more information.
   */
  public function getVersion() {
    return $this->apiVersion;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.hasmetadata.php )
   *
   * Returns whether phar has global meta-data set.
   * No parameters.
   *
   * @return     mixed   Returns TRUE if meta-data has been set, and FALSE if
   *                     not.
   */
  public function hasMetadata() {
    return $this->metadata !== null;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.isbuffering.php )
   *
   * This method can be used to determine whether a Phar will save changes
   * to disk immediately, or whether a call to Phar::stopBuffering() is
   * needed to enable saving changes.
   *
   * Phar write buffering is per-archive, buffering active for the foo.phar
   * Phar archive does not affect changes to the bar.phar Phar archive.
   *
   * @return     mixed   Returns TRUE if the write operations are being
   *                     buffer, FALSE otherwise.
   */
  public function isBuffering() {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.iscompressed.php )
   *
   *
   * No parameters.
   *
   * @return     mixed   Phar::GZ, Phar::BZ2 or FALSE
   */
  public function isCompressed() {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.isfileformat.php )
   *
   *
   * @fileformat mixed   Either Phar::PHAR, Phar::TAR, or Phar::ZIP to test
   *                     for the format of the archive.
   *
   * @return     mixed   Returns TRUE if the phar archive matches the file
   *                     format requested by the parameter
   */
  public function isFileFormat($fileformat) {
    return $fileformat === self::PHAR;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.iswritable.php )
   *
   * This method returns TRUE if phar.readonly is 0, and the actual phar
   * archive on disk is not read-only.
   * No parameters.
   *
   * @return     mixed   Returns TRUE if the phar archive can be modified
   */
  public function isWritable() {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.offsetexists.php )
   *
   * This is an implementation of the ArrayAccess interface allowing direct
   * manipulation of the contents of a Phar archive using array access
   * brackets.
   *
   * offsetExists() is called whenever isset() is called.
   *
   * @entry      mixed   The filename (relative path) to look for in a Phar.
   *
   * @return     mixed   Returns TRUE if the file exists within the phar, or
   *                     FALSE if not.
   */
  public function offsetExists($entry) {
    return isset($this->files[$entry]);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.offsetget.php )
   *
   * This is an implementation of the ArrayAccess interface allowing direct
   * manipulation of the contents of a Phar archive using array access
   * brackets. Phar::offsetGet() is used for retrieving files from a Phar
   * archive.
   *
   * @entry      mixed   The filename (relative path) to look for in a Phar.
   *
   * @return     mixed   A PharFileInfo object is returned that can be used
   *                     to iterate over a file's contents or to retrieve
   *                     information about the current file.
   */
  public function offsetGet($entry) {
    return new PharFileInfo($this->files[$entry]);
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.offsetset.php )
   *
   *
   * @entry      mixed   The filename (relative path) to modify in a Phar.
   * @value      mixed   Content of the file.
   *
   * @return     mixed   No return values.
   */
  public function offsetSet($entry, $value) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.offsetunset.php )
   *
   *
   * @entry      mixed   The filename (relative path) to modify in a Phar.
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function offsetUnset($entry) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.setalias.php )
   *
   *
   * @alias      mixed   A shorthand string that this archive can be referred
   *                     to in phar stream wrapper access.
   */
  public function setAlias($alias) {
    $this->alias = $alias;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.setdefaultstub.php )
   *
   *
   * @index      mixed   Relative path within the phar archive to run if
   *                     accessed on the command-line
   * @webindex   mixed   Relative path within the phar archive to run if
   *                     accessed through a web browser
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function setDefaultStub($index, $webindex = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.setmetadata.php )
   *
   *
   * @metadata   mixed   Any PHP variable containing information to store
   *                     that describes the phar archive
   *
   * @return     mixed   No value is returned.
   */
  public function setMetadata($metadata) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.setsignaturealgorithm.php )
   *
   *
   * @algorithm  mixed   One of Phar::MD5, Phar::SHA1, Phar::SHA256,
   *                     Phar::SHA512, or Phar::OPENSSL
   * @privatekey mixed   The contents of an OpenSSL private key, as extracted
   *                     from a certificate or OpenSSL key file:
   *
   *                     See phar introduction for instructions on naming
   *                     and placement of the public key file.
   *
   * @return     mixed   No value is returned.
   */
  public function setSignatureAlgorithm($algorithm, $privatekey = null) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.setstub.php )
   *
   *
   * @newstub    mixed   A string or an open stream handle to use as the
   *                     executable stub for this phar archive.
   * @maxlen     mixed
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public function setStub($newstub, $maxlen = -1) {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.startbuffering.php )
   *
   * Although technically unnecessary, the Phar::startBuffering() method can
   * provide a significant performance boost when creating or modifying a
   * Phar archive with a large number of files. Ordinarily, every time a file
   * within a Phar archive is created or modified in any way, the entire Phar
   * archive will be recreated with the changes. In this way, the archive
   * will be up-to-date with the activity performed on it.
   *
   * However, this can be unnecessary when simply creating a new Phar
   * archive, when it would make more sense to write the entire archive out
   * at once. Similarly, it is often necessary to make a series of changes
   * and to ensure that they all are possible before making any changes on
   * disk, similar to the relational database concept of transactions. the
   * Phar::startBuffering()/ Phar::stopBuffering() pair of methods is
   * provided for this purpose.
   *
   * Phar write buffering is per-archive, buffering active for the foo.phar
   * Phar archive does not affect changes to the bar.phar Phar archive.
   *
   * @return     mixed   No value is returned.
   */
  public function startBuffering() {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.stopbuffering.php )
   *
   * Phar::stopBuffering() is used in conjunction with the
   * Phar::startBuffering() method. Phar::startBuffering() can provide a
   * significant performance boost when creating or modifying a Phar archive
   * with a large number of files. Ordinarily, every time a file within a
   * Phar archive is created or modified in any way, the entire Phar archive
   * will be recreated with the changes. In this way, the archive will be
   * up-to-date with the activity performed on it.
   *
   * However, this can be unnecessary when simply creating a new Phar
   * archive, when it would make more sense to write the entire archive out
   * at once. Similarly, it is often necessary to make a series of changes
   * and to ensure that they all are possible before making any changes on
   * disk, similar to the relational database concept of transactions. The
   * Phar::startBuffering()/ Phar::stopBuffering() pair of methods is
   * provided for this purpose.
   *
   * Phar write buffering is per-archive, buffering active for the foo.phar
   * Phar archive does not affect changes to the bar.phar Phar archive.
   *
   * @return     mixed   No value is returned.
   */
  public function stopBuffering() {
    throw new UnexpectedValueException('phar is read-only');
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.canwrite.php )
   *
   * This static method determines whether write access has been disabled in
   * the system php.ini via the phar.readonly ini variable.
   *
   * @return     mixed   TRUE if write access is enabled, FALSE if it is
   *                     disabled.
   */
  public static function canWrite()  {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.apiversion.php )
   *
   * Return the API version of the phar file format that will be used when
   * creating phars. The Phar extension supports reading API version 1.0.0 or
   * newer. API version 1.1.0 is required for SHA-256 and SHA-512 hash, and
   * API version 1.1.1 is required to store empty directories.
   *
   * @return     mixed   The API version string as in "1.0.0".
   */
  final public static function apiVersion() {
    return '1.0.0';
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.cancompress.php )
   *
   * This should be used to test whether compression is possible prior to
   * loading a phar archive containing compressed files.
   *
   * @type       mixed   Either Phar::GZ or Phar::BZ2 can be used to test
   *                     whether compression is possible with a specific
   *                     compression algorithm (zlib or bzip2).
   *
   * @return     mixed   TRUE if compression/decompression is available,
   *                     FALSE if not.
   */
  final public static function canCompress($type = 0) {
    return false;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getsupportedcompression.php
   * )
   *
   *
   * No parameters.
   *
   * @return     mixed   Returns an array containing any of Phar::GZ or
   *                     Phar::BZ2, depending on the availability of the zlib
   *                     extension or the bz2 extension.
   */
  final public static function getSupportedCompression() {
    return array();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.getsupportedsignatures.php
   * )
   *
   * Return array of supported signature types
   * No parameters.
   *
   * @return     mixed   Returns an array containing any of MD5, SHA-1,
   *                     SHA-256, SHA-512, or OpenSSL.
   */
  final public static function getSupportedSignatures () {
    return array();
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.loadphar.php )
   *
   * This can be used to read the contents of an external Phar archive. This
   * is most useful for assigning an alias to a phar so that subsequent
   * references to the phar can use the shorter alias, or for loading Phar
   * archives that only contain data and are not intended for
   * execution/inclusion in PHP scripts.
   *
   * @filename   mixed   the full or relative path to the phar archive to
   *                     open
   * @alias      mixed   The alias that may be used to refer to the phar
   *                     archive. Note that many phar archives specify an
   *                     explicit alias inside the phar archive, and a
   *                     PharException will be thrown if a new alias is
   *                     specified in this case.
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  final public static function loadPhar($filename, $alias = null) {
    new self($filename, null, $alias);
    return true;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.mapphar.php )
   *
   * This static method can only be used inside a Phar archive's loader stub
   * in order to initialize the phar when it is directly executed, or when it
   * is included in another script.
   *
   * @alias      mixed   The alias that can be used in phar:// URLs to refer
   *                     to this archive, rather than its full path.
   * @dataoffset mixed   Unused variable, here for compatibility with PEAR's
   *                     PHP_Archive.
   *
   * @return     mixed   Returns TRUE on success or FALSE on failure.
   */
  public static function mapPhar($alias = null, $dataoffset = 0) {
    new self(debug_backtrace()[0]['file'], null, $alias);
    return true;
  }

  // This doc comment block generated by idl/sysdoc.php
  /**
   * ( excerpt from http://php.net/manual/en/phar.interceptfilefuncs.php )
   *
   * instructs phar to intercept fopen(), readfile(), file_get_contents(),
   * opendir(), and all of the stat-related functions. If any of these
   * functions is called from within a phar archive with a relative path, the
   * call is modified to access a file within the phar archive. Absolute
   * paths are assumed to be attempts to load external files from the
   * filesystem.
   *
   * This function makes it possible to run PHP applications designed to run
   * off of a hard disk as a phar application.
   * No parameters.
   *
   */
  public static function interceptFileFuncs() {
    // Not supported (yet) but most phars call it, so don't throw
  }

  final public static function webPhar(
      $alias,
      $index = "index.php",
      $f404 = null,
      $mimetypes = null,
      $rewrites = null) {
    // This is in the default stub, but lets ignore it for now
  }

  private static function bytesToInt($str, &$pos, $len) {
    if (strlen($str) < $pos + $len) {
      throw new PharException(
        "Corrupt phar, can't read $len bytes starting at offset $pos"
      );
    }
    $int = 0;
    for ($i = 0; $i < $len; ++$i) {
      $int |= ord($str[$pos++]) << (8*$i);
    }
    return $int;
  }

  private static function substr($str, &$pos, $len) {
    $ret = substr($str, $pos, $len);
    $pos += $len;
    return $ret;
  }

  private function parsePhar($str) {
    $pos = 0;
    $len = self::bytesToInt($str, $pos, 4);
    $this->count = self::bytesToInt($str, $pos, 4);
    $this->apiVersion = self::bytesToInt($str, $pos, 2);
    $this->archiveFlags = self::bytesToInt($str, $pos, 4);
    $alias_len = self::bytesToInt($str, $pos, 4);
    $this->alias = self::substr($str, $pos, $alias_len);
    $metadata_len = self::bytesToInt($str, $pos, 4);
    $this->metadata = unserialize(
      self::substr($str, $pos, $metadata_len)
    );
    $this->parseFileInfo($str, $pos);
    if ($pos != $len + 4) {
      throw new PharException(
        "Malformed manifest. Expected $len bytes, got $pos"
      );
    }
    foreach ($this->fileInfo as $key => $info) {
      $this->fileOffsets[$key] = array($pos, $info[2]);
      $pos += $info[2];
    }
  }

  private function parseFileInfo($str, &$pos) {
    for ($i = 0; $i < $this->count; $i++) {
      $filename_len = self::bytesToInt($str, $pos, 4);
      $filename = self::substr($str, $pos, $filename_len);
      $filesize = self::bytesToInt($str, $pos, 4);
      $timestamp = self::bytesToInt($str, $pos, 4);
      $compressed_filesize = self::bytesToInt($str, $pos, 4);
      $crc32 = self::bytesToInt($str, $pos, 4);
      $flags = self::bytesToInt($str, $pos, 4);
      $metadata_len = self::bytesToInt($str, $pos, 4);
      $metadata = self::bytesToInt($str, $pos, $metadata_len);
      $this->fileInfo[$filename] = array(
        $filesize, $timestamp, $compressed_filesize, $crc32, $flags, $metadata
      );
    }
  }

  /**
   * A poor man's FileUtil::canonicalize in PHP
   */
  private static function resolveDotDots($pieces) {
    $starts_with_slash = false;
    if (count($pieces) > 0 && !$pieces[0]) {
      $starts_with_slash = true;
    }

    foreach ($pieces as $i => $piece) {
      if ($piece == '.') {
        $piece[$i] = '';
      } else if ($piece == '..' && $i > 0) {
        $pieces[$i] = '';
        while ($i > 0 && !$pieces[$i-1]) {
          $i--;
        }
        $pieces[$i-1] = '';
      }
    }
    return ($starts_with_slash ? '/' : '') .
           implode('/', array_filter($pieces));
  }

  /**
   * BELOW THIS ISN'T PART OF THE ZEND API. THEY ARE FOR THE STREAM WRAPPER.
   */

  /**
   * For the stream wrapper to stat a file. Same response format as stat().
   * Called from C++.
   */
  private static function stat($full_filename) {
    list($phar, $filename) = self::getPharAndFile($full_filename);
    if (!isset($phar->fileInfo[$filename])) {
      $dir = self::opendir($full_filename);
      if (!$dir) {
        return false;
      }

      return array(
        'size' => 0,
        'atime' => 0,
        'mtime' => 0,
        'ctime' => 0,
        'mode' => POSIX_S_IFDIR,
      );
    }

    $info = $phar->fileInfo[$filename];
    return array(
      'size' => $info[0],
      'atime' => $info[1],
      'mtime' => $info[1],
      'ctime' => $info[1],
      'mode' => POSIX_S_IFREG,
    );
  }

  /**
   * Simulates opendir() and readdir() and rewinddir() using an array.
   * Returns any files that start with $prefix.
   * Called from C++.
   */
  private static function opendir($full_prefix) {
    list($phar, $prefix) = self::getPharAndFile($full_prefix);
    $prefix = rtrim($prefix, '/');

    $ret = array();
    foreach ($phar->fileInfo as $filename => $_) {
      if (!$prefix) {
        if (strpos($filename, '/') === false) {
          $ret[$filename] = true;
        }
      } else {
        if (strpos($filename, $prefix) === 0) {
          $entry = substr($filename, strlen($prefix) + 1);
          if (strlen($entry) > 0) {
            if ($filename[strlen($prefix)] != '/') {
              continue;
            }
            $next_slash = strpos($entry, '/');
            if ($next_slash !== false) {
              $entry = substr($entry, 0, $next_slash);
            }
            $ret[$entry] = true;
          }
        }
      }
    }
    return array_keys($ret);
  }

  /**
   * Used by the stream wrapper to open phar:// files.
   * Called from C++.
   */
  private static function openPhar($full_filename) {
    list($phar, $filename) = self::getPharAndFile($full_filename);
    return $phar->getFileData($filename);
  }

  private function getFileData($filename) {
    if (!isset($this->fileOffsets[$filename])) {
      throw new PharException("No $filename in phar");
    }
    $offsets = $this->fileOffsets[$filename];
    return substr($this->contents, $offsets[0], $offsets[1]);
  }

  /**
   * Checks through a phar://path/to/file.phar/other/path.php and returns
   *
   *   array([Phar object for path/to/file.phar], 'other/path.php')
   *
   * or if the first piece is a valid alias, then returns
   *
   *   array([Phar object for alias], 'rest/of/path.php')
   */
  private static function getPharAndFile($filename_or_alias) {
    if (strncmp($filename_or_alias, 'phar://', 7)) {
      throw new PharException("Not a phar: $filename_or_alias");
    }

    $pieces = explode('/', substr($filename_or_alias, 7));

    if (count($pieces) > 0 && isset(self::$aliases[$pieces[0]])) {
      $alias = array_shift($pieces);
      return array(
        self::$aliases[$alias],
        self::resolveDotDots($pieces)
      );
    }

    $filename = '';
    while ($pieces) {
      $filename .= '/'.array_shift($pieces);
      if (is_file($filename)) {

        if (!isset(self::$aliases[$filename])) {
          self::loadPhar($filename);
        }

        return array(
          self::$aliases[$filename],
          self::resolveDotDots($pieces)
        );
      }
    }

    throw new PharException("Not a phar: $filename_or_alias");
  }

}
