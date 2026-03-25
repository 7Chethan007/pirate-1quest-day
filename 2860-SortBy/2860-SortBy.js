// Last updated: 3/25/2026, 9:02:25 AM
/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
  return arr.sort((a, b) => fn(a) - fn(b));
};
