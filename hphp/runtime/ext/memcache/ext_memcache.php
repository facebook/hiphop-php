<?hh
// generated by idl-to-hni.php

/* Represents a connection to a set of memcache servers.
 */
<<__NativeData("MemcacheData")>>
class Memcache {
  function __construct() {}

  /* Memcache::connect() establishes a connection to the memcached server. The
   * connection, which was opened using Memcache::connect() will be
   * automatically closed at the end of script execution. Also you can close it
   * with Memcache::close(). Also you can use memcache_connect() function.
   * @param string $host - Point to the host where memcached is listening for
   * connections. This parameter may also specify other transports like
   * unix:///path/to/memcached.sock to use UNIX domain sockets, in this case
   * port must also be set to 0.
   * @param int $port - Point to the port where memcached is listening for
   * connections. Set this parameter to 0 when using UNIX domain sockets.
   * @param int $timeout - Value in seconds which will be used for connecting to
   * the daemon. Think twice before changing the default value of 1 second - you
   * can lose all the advantages of caching if your connection is too slow.
   * @param int $timeoutms
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function connect(string $host,
                   int $port = 0,
                   int $timeout = 0,
                   int $timeoutms = 0): bool;

  /* Memcache::pconnect() is similar to Memcache::connect() with the difference,
   * that the connection it establishes is persistent. This connection is not
   * closed after the end of script execution and by Memcache::close() function.
   * Also you can use memcache_pconnect() function.
   * @param string $host - Point to the host where memcached is listening for
   * connections. This parameter may also specify other transports like
   * unix:///path/to/memcached.sock to use UNIX domain sockets, in this case
   * port must also be set to 0.
   * @param int $port - Point to the port where memcached is listening for
   * connections. Set this parameter to 0 when using UNIX domain sockets.
   * @param int $timeout - Value in seconds which will be used for connecting to
   * the daemon. Think twice before changing the default value of 1 second - you
   * can lose all the advantages of caching if your connection is too slow.
   * @param int $timeoutms
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  function pconnect(mixed $host,
                    mixed $port = 0,
                    mixed $timeout = 0,
                    mixed $timeoutms = 0): bool {
    return $this->connect($host, $port, $timeout, $timeoutms);
  }

  /* Memcache::add() stores variable var with key only if such key doesn't exist
   * at the server yet. Also you can use memcache_add() function.
   * @param string $key - The key that will be associated with the item.
   * @param mixed $var - The variable to store. Strings and integers are stored
   * as is, other types are stored serialized.
   * @param int $flag - Use MEMCACHE_COMPRESSED to store the item compressed
   * (uses zlib).
   * @param int $expire - Expiration time of the item. If it's equal to zero,
   * the item will never expire. You can also use Unix timestamp or a number of
   * seconds starting from current time, but in the latter case the number of
   * seconds may not exceed 2592000 (30 days).
   * @return bool - Returns TRUE on success or FALSE on failure. Returns FALSE
   * if such key already exist. For the rest Memcache::add() behaves similarly
   * to Memcache::set().
   */
  <<__Native>>
  function add(string $key,
               mixed $var,
               int $flag = 0,
               int $expire = 0): bool;

  /* Memcache::set() stores an item var with key on the memcached server.
   * Parameter expire is expiration time in seconds. If it's 0, the item never
   * expires (but memcached server doesn't guarantee this item to be stored all
   * the time, it could be deleted from the cache to make place for other
   * items). You can use MEMCACHE_COMPRESSED constant as flag value if you want
   * to use on-the-fly compression (uses zlib).  Remember that resource
   * variables (i.e. file and connection descriptors) cannot be stored in the
   * cache, because they cannot be adequately represented in serialized state.
   * Also you can use memcache_set() function.
   * @param string $key - The key that will be associated with the item.
   * @param mixed $var - The variable to store. Strings and integers are stored
   * as is, other types are stored serialized.
   * @param int $flag - Use MEMCACHE_COMPRESSED to store the item compressed
   * (uses zlib).
   * @param int $expire - Expiration time of the item. If it's equal to zero,
   * the item will never expire. You can also use Unix timestamp or a number of
   * seconds starting from current time, but in the latter case the number of
   * seconds may not exceed 2592000 (30 days).
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function set(string $key,
               mixed $var,
               int $flag = 0,
               int $expire = 0): bool;

  /* Memcache::replace() should be used to replace value of existing item with
   * key. In case if item with such key doesn't exists, Memcache::replace()
   * returns FALSE. For the rest Memcache::replace() behaves similarly to
   * Memcache::set(). Also you can use memcache_replace() function.
   * @param string $key - The key that will be associated with the item.
   * @param mixed $var - The variable to store. Strings and integers are stored
   * as is, other types are stored serialized.
   * @param int $flag - Use MEMCACHE_COMPRESSED to store the item compressed
   * (uses zlib).
   * @param int $expire - Expiration time of the item. If it's equal to zero,
   * the item will never expire. You can also use Unix timestamp or a number of
   * seconds starting from current time, but in the latter case the number of
   * seconds may not exceed 2592000 (30 days).
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function replace(string $key,
                   mixed $var,
                   int $flag = 0,
                   int $expire = 0): bool;

  /* Memcache::get() returns previously stored data if an item with such key
   * exists on the server at this moment.  You can pass array of keys to
   * Memcache::get() to get array of values. The result array will contain only
   * found key-value pairs.
   * @param mixed $key - The key or array of keys to fetch.
   * @param mixed $flags - If present, flags fetched along with the values will
   * be written to this parameter. These flags are the same as the ones given to
   * for example Memcache::set(). The lowest byte of the int is reserved for
   * pecl/memcache internal usage (e.g. to indicate compression and
   * serialization status).
   * @return mixed - Returns the string associated with the key or FALSE on
   * failure or if such key was not found.
   */
  <<__Native>>
  function get(mixed $key,
               mixed &$flags = null): mixed;

  /* Memcache::delete() deletes item with the key. If parameter timeout is
   * specified, the item will expire after timeout seconds. Also you can use
   * memcache_delete() function.
   * @param string $key - The key associated with the item to delete.
   * @param int $expire - Execution time of the item. If it's equal to zero, the
   * item will be deleted right away whereas if you set it to 30, the item will
   * be deleted in 30 seconds.
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function delete(string $key,
                  int $expire = 0): bool;

  /* Memcache::increment() increments value of an item by the specified value.
   * If item specified by key was not numeric and cannot be converted to a
   * number, it will change its value to value. Memcache::increment() does not
   * create an item if it doesn't already exist.  Do not use
   * Memcache::increment() with items that have been stored compressed because
   * subsequent calls to Memcache::get() will fail. Also you can use
   * memcache_increment() function.
   * @param string $key - Key of the item to increment.
   * @param int $offset - Increment the item by value.
   * @return mixed - Returns new items value on success or FALSE on failure.
   */
  <<__Native>>
  function increment(string $key,
                     int $offset = 1): mixed;

  /* Memcache::decrement() decrements value of the item by value. Similarly to
   * Memcache::increment(), current value of the item is being converted to
   * numerical and after that value is substracted.  New item's value will not
   * be less than zero.  Do not use Memcache::decrement() with item, which was
   * stored compressed, because consequent call to Memcache::get() will fail.
   * Memcache::decrement() does not create an item if it didn't exist. Also you
   * can use memcache_decrement() function.
   * @param string $key - Key of the item do decrement.
   * @param int $offset - Decrement the item by value.
   * @return mixed - Returns item's new value on success or FALSE on failure.
   */
  <<__Native>>
  function decrement(string $key,
                     int $offset = 1): mixed;

  /* Memcache::getVersion() returns a string with server's version number. Also
   * you can use memcache_get_version() function.
   * @return mixed - Returns a string of server version number or FALSE on
   * failure.
   */
  <<__Native>>
  function getversion(): mixed;

  /* Memcache::flush() immediately invalidates all existing items.
   * Memcache::flush() doesn't actually free any resources, it only marks all
   * the items as expired, so occupied memory will be overwritten by new items.
   * Also you can use memcache_flush() function.
   * @param int $expire
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function flush(int $expire = 0): bool;

  /* @param int $timeoutms
   * @return bool
   */
  function setoptimeout(mixed $timeoutms): bool {
    $timeoutms = intval($timeoutms);
    if ($timeoutms < 1) {
      $timeoutms = 1000; // make default
    }

    /* intentionally doing nothing for now */

    return true;
  }

  /* Memcache::close() closes connection to memcached server. This function
   * doesn't close persistent connections, which are closed only during
   * web-server shutdown/restart. Also you can use memcache_close() function.
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function close(): bool;

  /* Memcache::getServerStatus() returns a the servers online/offline status.
   * You can also use memcache_get_server_status() function.  This function has
   * been added to Memcache version 2.1.0.
   * @param string $host - Point to the host where memcached is listening for
   * connections.
   * @param int $port - Point to the port where memcached is listening for
   * connections.
   * @return int - Returns a the servers status. 0 if server is failed, non-zero
   * otherwise
   */
  function getserverstatus(string $host,
                           int $port = 0): int {
    /* intentionally doing nothing for now */
    return 1;
  }

  /* Memcache::setCompressThreshold() enables automatic compression of large
   * values. You can also use the memcache_set_compress_threshold() function.
   * This function has been added to Memcache version 2.0.0.
   * @param int $threshold - Controls the minimum value length before attempting
   * to compress automatically.
   * @param float $min_savings - Specifies the minimum amount of savings to
   * actually store the value compressed. The supplied value must be between 0
   * and 1. Default value is 0.2 giving a minimum 20% compression savings.
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function setcompressthreshold(int $threshold,
                                float $min_savings = 0.2): bool;

  /* Memcache::getStats() returns an associative array with server's statistics.
   * Array keys correspond to stats parameters and values to parameter's values.
   * Also you can use memcache_get_stats() function.
   * @param string $type - The type of statistics to fetch. Valid values are
   * {reset, malloc, maps, cachedump, slabs, items, sizes}. According to the
   * memcached protocol spec these additional arguments "are subject to change
   * for the convenience of memcache developers".
   * @param int $slabid - Used in conjunction with type set to cachedump to
   * identify the slab to dump from. The cachedump command ties up the server
   * and is strictly to be used for debugging purposes.
   * @param int $limit - Used in conjunction with type set to cachedump to limit
   * the number of entries to dump.
   * @return array - Returns an associative array of server statistics or FALSE
   * on failure.
   */
  <<__Native>>
  function getstats(string $type = "",
                    int $slabid = 0,
                    int $limit = 100): array;

  /* Memcache::getExtendedStats() returns a two-dimensional associative array
   * with server statistics. Array keys correspond to host:port of server and
   * values contain the individual server statistics. A failed server will have
   * its corresponding entry set to FALSE. You can also use the
   * memcache_get_extended_stats() function.  This function has been added to
   * Memcache version 2.0.0.
   * @param string $type - The type of statistics to fetch. Valid values are
   * {reset, malloc, maps, cachedump, slabs, items, sizes}. According to the
   * memcached protocol spec these additional arguments "are subject to change
   * for the convenience of memcache developers".
   * @param int $slabid - Used in conjunction with type set to cachedump to
   * identify the slab to dump from. The cachedump command ties up the server
   * and is strictly to be used for debugging purposes.
   * @param int $limit - Used in conjunction with type set to cachedump to limit
   * the number of entries to dump.
   * @return array - Returns a two-dimensional associative array of server
   * statistics or FALSE on failure.
   */
  <<__Native>>
  function getextendedstats(string $type = "",
                            int $slabid = 0,
                            int $limit = 100): array;

  /* Memcache::setServerParams() changes server parameters at runtime. You can
   * also use the memcache_set_server_params() function.  This function has been
   * added to Memcache version 2.1.0.
   * @param string $host - Point to the host where memcached is listening for
   * connections.
   * @param int $port - Point to the port where memcached is listening for
   * connections.
   * @param int $timeout - Value in seconds which will be used for connecting to
   * the daemon. Think twice before changing the default value of 1 second - you
   * can lose all the advantages of caching if your connection is too slow.
   * @param int $retry_interval - Controls how often a failed server will be
   * retried, the default value is 15 seconds. Setting this parameter to -1
   * disables automatic retry. Neither this nor the persistent parameter has any
   * effect when the extension is loaded dynamically via dl().
   * @param bool $status - Controls if the server should be flagged as online.
   * Setting this parameter to FALSE and retry_interval to -1 allows a failed
   * server to be kept in the pool so as not to affect the key distribution
   * algorithm. Requests for this server will then failover or fail immediately
   * depending on the memcache.allow_failover setting. Default to TRUE, meaning
   * the server should be considered online.
   * @param mixed $failure_callback - Allows the user to specify a callback
   * function to run upon encountering an error. The callback is run before
   * failover is attempted. The function takes two parameters, the hostname and
   * port of the failed server.
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  function setserverparams(string $host,
                           int $port = 11211,
                           int $timeout = 0,
                           int $retry_interval = 0,
                           bool $status = true,
                           mixed $failure_callback = null): bool {
    /* intentionally doing nothing for now */
    return true;
  }

  /* Memcache::addServer() adds a server to the connection pool. The connection,
   * which was opened using Memcache::addServer() will be automatically closed
   * at the end of script execution, you can also close it manually with
   * Memcache::close(). You can also use the memcache_add_server() function.
   * When using this method (as opposed to Memcache::connect() and
   * Memcache::pconnect()) the network connection is not established until
   * actually needed. Thus there is no overhead in adding a large number of
   * servers to the pool, even though they might not all be used.  Failover may
   * occur at any stage in any of the methods, as long as other servers are
   * available the request the user won't notice. Any kind of socket or
   * Memcached server level errors (except out-of-memory) may trigger the
   * failover. Normal client errors such as adding an existing key will not
   * trigger a failover.  This function has been added to Memcache version
   * 2.0.0.
   * @param string $host - Point to the host where memcached is listening for
   * connections. This parameter may also specify other transports like
   * unix:///path/to/memcached.sock to use UNIX domain sockets, in this case
   * port must also be set to 0.
   * @param int $port - Point to the port where memcached is listening for
   * connections. Set this parameter to 0 when using UNIX domain sockets.
   * @param bool $persistent - Controls the use of a persistent connection.
   * Default to TRUE.
   * @param int $weight - Number of buckets to create for this server which in
   * turn control its probability of it being selected. The probability is
   * relative to the total weight of all servers.
   * @param int $timeout - Value in seconds which will be used for connecting to
   * the daemon. Think twice before changing the default value of 1 second - you
   * can lose all the advantages of caching if your connection is too slow.
   * @param int $retry_interval - Controls how often a failed server will be
   * retried, the default value is 15 seconds. Setting this parameter to -1
   * disables automatic retry. Neither this nor the persistent parameter has any
   * effect when the extension is loaded dynamically via dl().  Each failed
   * connection struct has its own timeout and before it has expired the struct
   * will be skipped when selecting backends to serve a request. Once expired
   * the connection will be successfully reconnected or marked as failed for
   * another retry_interval seconds. The typical effect is that each web server
   * child will retry the connection about every retry_interval seconds when
   * serving a page.
   * @param bool $status - Controls if the server should be flagged as online.
   * Setting this parameter to FALSE and retry_interval to -1 allows a failed
   * server to be kept in the pool so as not to affect the key distribution
   * algorithm. Requests for this server will then failover or fail immediately
   * depending on the memcache.allow_failover setting. Default to TRUE, meaning
   * the server should be considered online.
   * @param mixed $failure_callback - Allows the user to specify a callback
   * function to run upon encountering an error. The callback is run before
   * failover is attempted. The function takes two parameters, the hostname and
   * port of the failed server.
   * @param int $timeoutms
   * @return bool - Returns TRUE on success or FALSE on failure.
   */
  <<__Native>>
  function addserver(string $host,
                     int $port = 11211,
                     bool $persistent = false,
                     int $weight = 0,
                     int $timeout = 0,
                     int $retry_interval = 0,
                     bool $status = true,
                     mixed $failure_callback = null,
                     int $timeoutms = 0): bool;

  function __destruct(): void {
    $this->close();
  }
}

/* Memcache::connect() establishes a connection to the memcached server. The
 * connection, which was opened using Memcache::connect() will be
 * automatically closed at the end of script execution. Also you can close it
 * with Memcache::close(). Also you can use memcache_connect() function.
 * @param string $host - Point to the host where memcached is listening for
 * connections. This parameter may also specify other transports like
 * unix:///path/to/memcached.sock to use UNIX domain sockets, in this case
 * port must also be set to 0.
 * @param int $port - Point to the port where memcached is listening for
 * connections. Set this parameter to 0 when using UNIX domain sockets.
 * @param int $timeout - Value in seconds which will be used for connecting to
 * the daemon. Think twice before changing the default value of 1 second - you
 * can lose all the advantages of caching if your connection is too slow.
 * @param int $timeoutms
 * @return object - Returns TRUE on success or FALSE on failure.
 */
function memcache_connect(mixed $host,
                          mixed $port = 0,
                          mixed $timeout = 0,
                          mixed $timeoutms = 0): Memcache {
  $ret = new Memcache();
  $ret->connect($host, $port, $timeout, $timeoutms);
  return $ret;
}

/* Memcache::pconnect() is similar to Memcache::connect() with the difference,
 * that the connection it establishes is persistent. This connection is not
 * closed after the end of script execution and by Memcache::close() function.
 * Also you can use memcache_pconnect() function.
 * @param string $host - Point to the host where memcached is listening for
 * connections. This parameter may also specify other transports like
 * unix:///path/to/memcached.sock to use UNIX domain sockets, in this case
 * port must also be set to 0.
 * @param int $port - Point to the port where memcached is listening for
 * connections. Set this parameter to 0 when using UNIX domain sockets.
 * @param int $timeout - Value in seconds which will be used for connecting to
 * the daemon. Think twice before changing the default value of 1 second - you
 * can lose all the advantages of caching if your connection is too slow.
 * @param int $timeoutms
 * @return object - Returns TRUE on success or FALSE on failure.
 */
function memcache_pconnect(mixed $host,
                           mixed $port = 0,
                           mixed $timeout = 0,
                           mixed $timeoutms = 0): Memcache {
  return memcache_connect($host, $port, $timeout, $timeoutms);
}

/* Memcache::add() stores variable var with key only if such key doesn't exist
 * at the server yet. Also you can use memcache_add() function.
 * @param object $memcache - The key that will be associated with the item.
 * @param string $key - The variable to store. Strings and integers are stored
 * as is, other types are stored serialized.
 * @param mixed $var - Use MEMCACHE_COMPRESSED to store the item compressed
 * (uses zlib).
 * @param int $flag - Expiration time of the item. If it's equal to zero, the
 * item will never expire. You can also use Unix timestamp or a number of
 * seconds starting from current time, but in the latter case the number of
 * seconds may not exceed 2592000 (30 days).
 * @param int $expire
 * @return bool - Returns TRUE on success or FALSE on failure. Returns FALSE
 * if such key already exist. For the rest Memcache::add() behaves similarly
 * to Memcache::set().
 */
function memcache_add(Memcache $memcache,
                      mixed $key,
                      mixed $var,
                      mixed $flag = 0,
                      mixed $expire = 0): bool {
  return $memcache->add($key, $var, $flag, $expire);
}

/* Memcache::set() stores an item var with key on the memcached server.
 * Parameter expire is expiration time in seconds. If it's 0, the item never
 * expires (but memcached server doesn't guarantee this item to be stored all
 * the time, it could be deleted from the cache to make place for other
 * items). You can use MEMCACHE_COMPRESSED constant as flag value if you want
 * to use on-the-fly compression (uses zlib).  Remember that resource
 * variables (i.e. file and connection descriptors) cannot be stored in the
 * cache, because they cannot be adequately represented in serialized state.
 * Also you can use memcache_set() function.
 * @param object $memcache - The key that will be associated with the item.
 * @param string $key - The variable to store. Strings and integers are stored
 * as is, other types are stored serialized.
 * @param mixed $var - Use MEMCACHE_COMPRESSED to store the item compressed
 * (uses zlib).
 * @param int $flag - Expiration time of the item. If it's equal to zero, the
 * item will never expire. You can also use Unix timestamp or a number of
 * seconds starting from current time, but in the latter case the number of
 * seconds may not exceed 2592000 (30 days).
 * @param int $expire
 * @return bool - Returns TRUE on success or FALSE on failure.
 */
function memcache_set(Memcache $memcache,
                      mixed $key,
                      mixed $var,
                      mixed $flag = 0,
                      mixed $expire = 0): bool {
  return $memcache->set($key, $var, $flag, $expire);
}

/* Memcache::replace() should be used to replace value of existing item with
 * key. In case if item with such key doesn't exists, Memcache::replace()
 * returns FALSE. For the rest Memcache::replace() behaves similarly to
 * Memcache::set(). Also you can use memcache_replace() function.
 * @param object $memcache - The key that will be associated with the item.
 * @param string $key - The variable to store. Strings and integers are stored
 * as is, other types are stored serialized.
 * @param mixed $var - Use MEMCACHE_COMPRESSED to store the item compressed
 * (uses zlib).
 * @param int $flag - Expiration time of the item. If it's equal to zero, the
 * item will never expire. You can also use Unix timestamp or a number of
 * seconds starting from current time, but in the latter case the number of
 * seconds may not exceed 2592000 (30 days).
 * @param int $expire
 * @return bool - Returns TRUE on success or FALSE on failure.
 */
function memcache_replace(Memcache $memcache,
                          mixed $key,
                          mixed $var,
                          mixed $flag = 0,
                          mixed $expire = 0): bool {
  return $memcache->replace($key, $var, $flag, $expire);
}

/* Memcache::get() returns previously stored data if an item with such key
 * exists on the server at this moment.  You can pass array of keys to
 * Memcache::get() to get array of values. The result array will contain only
 * found key-value pairs.
 * @param object $memcache - The key or array of keys to fetch.
 * @param mixed $key - If present, flags fetched along with the values will be
 * written to this parameter. These flags are the same as the ones given to
 * for example Memcache::set(). The lowest byte of the int is reserved for
 * pecl/memcache internal usage (e.g. to indicate compression and
 * serialization status).
 * @param mixed $flags
 * @return mixed - Returns the string associated with the key or FALSE on
 * failure or if such key was not found.
 */
function memcache_get(Memcache $memcache,
                      mixed $key,
                      mixed &$flags = null): mixed {
  return $memcache->get($key, $flags);
}

/* Memcache::delete() deletes item with the key. If parameter timeout is
 * specified, the item will expire after timeout seconds. Also you can use
 * memcache_delete() function.
 * @param object $memcache - The key associated with the item to delete.
 * @param string $key - Execution time of the item. If it's equal to zero, the
 * item will be deleted right away whereas if you set it to 30, the item will
 * be deleted in 30 seconds.
 * @param int $expire
 * @return bool - Returns TRUE on success or FALSE on failure.
 */
function memcache_delete(Memcache $memcache,
                         mixed $key,
                         mixed $expire = 0): bool {
  return $memcache->delete($key, $expire);
}

/* Memcache::increment() increments value of an item by the specified value.
 * If item specified by key was not numeric and cannot be converted to a
 * number, it will change its value to value. Memcache::increment() does not
 * create an item if it doesn't already exist.  Do not use
 * Memcache::increment() with items that have been stored compressed because
 * subsequent calls to Memcache::get() will fail. Also you can use
 * memcache_increment() function.
 * @param object $memcache - Key of the item to increment.
 * @param string $key - Increment the item by value.
 * @param int $offset
 * @return int - Returns new items value on success or FALSE on failure.
 */
function memcache_increment(Memcache $memcache,
                            mixed $key,
                            mixed $offset = 1): int {
  return $memcache->increment($key, $offset);
}

/* Memcache::decrement() decrements value of the item by value. Similarly to
 * Memcache::increment(), current value of the item is being converted to
 * numerical and after that value is substracted.  New item's value will not
 * be less than zero.  Do not use Memcache::decrement() with item, which was
 * stored compressed, because consequent call to Memcache::get() will fail.
 * Memcache::decrement() does not create an item if it didn't exist. Also you
 * can use memcache_decrement() function.
 * @param object $memcache - Key of the item do decrement.
 * @param string $key - Decrement the item by value.
 * @param int $offset
 * @return int - Returns item's new value on success or FALSE on failure.
 */
function memcache_decrement(Memcache $memcache,
                            mixed $key,
                            mixed $offset = 1): int {
  return $memcache->decrement($key, $offset);
}

/* Memcache::close() closes connection to memcached server. This function
 * doesn't close persistent connections, which are closed only during
 * web-server shutdown/restart. Also you can use memcache_close() function.
 * @param object $memcache
 * @return bool - Returns TRUE on success or FALSE on failure.
 */
function memcache_close(Memcache $memcache): bool {
  return $memcache->close();
}

/* @param object $memcache
 * @return mixed
 */
function memcache_get_version(Memcache $memcache): mixed {
  return $memcache->getversion();
}

/* Memcache::flush() immediately invalidates all existing items.
 * Memcache::flush() doesn't actually free any resources, it only marks all
 * the items as expired, so occupied memory will be overwritten by new items.
 * Also you can use memcache_flush() function.
 * @param object $memcache
 * @param int $timestamp
 * @return bool - Returns TRUE on success or FALSE on failure.
 */
function memcache_flush(Memcache $memcache,
                        mixed $timestamp = 0): bool {
  return $memcache->flush($timestamp);
}

/* @param object $memcache
 * @param int $timeoutms
 * @return bool
 */
function memcache_setoptimeout(Memcache $memcache,
                               int $timeoutms): bool {
  return $memcache->setoptimeout($timeoutms);
}

/* @param object $memcache
 * @param string $host
 * @param int $port
 * @return int
 */
function memcache_get_server_status(Memcache $memcache,
                                    string $host,
                                    int $port = 0): int {
  return $memcache->getserverstatus($host, $port);
}

/* @param object $memcache
 * @param int $threshold
 * @param float $min_savings
 * @return bool
 */
function memcache_set_compress_threshold(Memcache $memcache,
                                         mixed $threshold,
                                         mixed $min_savings = 0.2): bool {
  return $memcache->setcompressthreshold($threshold, $min_savings);
}

/* @param object $memcache
 * @param string $type
 * @param int $slabid
 * @param int $limit
 * @return array
 */
function memcache_get_stats(Memcache $memcache,
                            mixed $type = "",
                            mixed $slabid = 0,
                            mixed $limit = 100): array {
  return $memcache->getstats($type, $slabid, $limit);
}

/* @param object $memcache
 * @param string $type
 * @param int $slabid
 * @param int $limit
 * @return array
 */
function memcache_get_extended_stats(Memcache $memcache,
                                     mixed $type = "",
                                     mixed $slabid = 0,
                                     mixed $limit = 100): array {
  return $memcache->getextendedstats($type, $slabid, $limit);
}

/* @param object $memcache
 * @param string $host
 * @param int $port
 * @param int $timeout
 * @param int $retry_interval
 * @param bool $status
 * @param mixed $failure_callback
 * @return bool
 */
function memcache_set_server_params(Memcache $memcache,
                                    mixed $host,
                                    mixed $port = 11211,
                                    mixed $timeout = 0,
                                    mixed $retry_interval = 0,
                                    mixed $status = true,
                                    mixed $failure_callback = null): bool {
  return $memcache->setserverparams($host, $port, $timeout, $retry_interval,
                                    $status, $failure_callback);
}

/* @param object $memcache
 * @param string $host
 * @param int $port
 * @param bool $persistent
 * @param int $weight
 * @param int $timeout
 * @param int $retry_interval
 * @param bool $status
 * @param mixed $failure_callback
 * @param int $timeoutms
 * @return bool
 */
function memcache_add_server(Memcache $memcache,
                             mixed $host,
                             mixed $port = 11211,
                             mixed $persistent = false,
                             mixed $weight = 0,
                             mixed $timeout = 0,
                             mixed $retry_interval = 0,
                             mixed $status = true,
                             mixed $failure_callback = null,
                             mixed $timeoutms = 0): bool {
  return $memcache->addserver($host, $port, $persistent, $weight, $timeout,
                              $retry_interval, $status, $failure_callback,
                              $timeoutms);
}

// Signifies we have built-in session support
define('MEMCACHE_HAVE_SESSION', true);

class MemcacheSessionModule implements \SessionHandlerInterface {

  const UNIX_PREFIX = 'unix://';
  const FILE_PREFIX = 'file://';

  const SCHEME_FILE = 'file';
  const SCHEME_TCP = 'tcp';

  const ZERO_PORT = ':0';

  private $memcache;
  private $serverList;

  public function close() {
    if ($this->memcache instanceof Memcache) {
      $this->memcache->close();
    }
    $this->memcache = null;
    $this->serverList = array();
    return true;
  }

  public function destroy($sessionId) {
    return $this->getMemcache()->delete($sessionId);
  }

  public function gc($maxLifetime) {
    return true;
  }

  public function open($savePath, $name) {
    $serverList = self::parseSavePath($savePath);
    if (!$serverList) {
      return false;
    }

    $this->serverList = $serverList;
    return true;
  }

  public function read($sessionId) {
    return (string)$this->getMemcache()->get($sessionId);
  }

  public function write($sessionId, $data) {
    return $this->getMemcache()->set($sessionId,
                                     $data,
                                     MEMCACHE_COMPRESSED,
                                     ini_get('session.gc_maxlifetime'));
  }

  private static function parseSavePath($savePath) {
    if (empty($savePath)) {
      trigger_error("Failed to parse session.save_path (empty save_path)",
                    E_WARNING);
      return false;
    }

    $serverList = explode(',', $savePath);

    $return = array();
    foreach ($serverList as $url) {
      $url = strtolower(trim($url));

      // white-space only / empty keys are skipped
      if (empty($url)) {
        continue;
      }
      // Swap unix:// to file:// for parse_url usage like pecl does
      if (substr($url, 0, strlen(self::UNIX_PREFIX)) === self::UNIX_PREFIX) {
        $url = self::FILE_PREFIX . substr($url, strlen(self::UNIX_PREFIX));
      }

      $parsedUrlData = parse_url($url);
      if (!$parsedUrlData) {
        trigger_error("Failed to parse session.save_path " .
                      "(unable to parse url, url was '" . $url . "')",
                      E_WARNING);
        return false;
      }

      // Init optional values to default values
      $serverInfo = array(
        'persistent' => true,
        'weight' => 1,
        'timeout' => 1,
        'retry_interval' => 15
      );

      switch ($parsedUrlData['scheme']) {
        case self::SCHEME_FILE:
          // Remove a zero port, if found
          if (substr($parsedUrlData['path'], -2) === self::ZERO_PORT) {
            $parsedUrlData['path'] = substr($parsedUrlData['path'], 0, -2);
          }
          // Return url back to a unix:// prefix instead of file://
          $serverInfo['host'] = self::UNIX_PREFIX . $parsedUrlData['path'];
          $serverInfo['port'] = 0;
          break;
        case self::SCHEME_TCP:
          // We don't give TCP connections a tcp:// prefix
          $serverInfo['host'] = $parsedUrlData['host'];
          if (array_key_exists('port', $parsedUrlData)) {
            $serverInfo['port'] = $parsedUrlData['port'];
          } else {
            $serverInfo['port'] = (int)ini_get('memcache.default_port');
          }
          break;
        default:
          trigger_error("Failed to parse session.save_path " .
                        "(unknown protocol, url was '" . $url . "')",
                        E_WARNING);
          return false;
      }

      if (array_key_exists('query', $parsedUrlData)) {
        $optionList = array();
        parse_str($parsedUrlData['query'], $optionList);
        if (count($optionList) > 0) {
          foreach ($optionList as $key => $value) {
            switch ($key) {
              case 'persistent':
                $serverInfo[$key] = (bool)$value;
                break;
              case 'weight':
              case 'timeout':
              case 'retry_interval':
                $serverInfo[$key] = (int)$value;
                break;
            }
          }
        }
      }

      $return[] = $serverInfo;
    }

    return $return;
  }

  private function getMemcache() {
    if ($this->memcache instanceof Memcache) {
      return $this->memcache;
    }

    $memcache = new Memcache;
    if (!empty($this->serverList)) {
      foreach ($this->serverList as $serverInfo) {
        $memcache->addServer($serverInfo['host'],
                             $serverInfo['port'],
                             $serverInfo['persistent'],
                             $serverInfo['weight'],
                             $serverInfo['timeout'],
                             $serverInfo['retry_interval']);
      }
    }

    $this->memcache = $memcache;
    return $memcache;
  }
}
