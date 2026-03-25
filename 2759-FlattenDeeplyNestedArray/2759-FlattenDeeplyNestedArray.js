// Last updated: 3/25/2026, 9:02:48 AM
/**
 * @param {Array} arr
 * @param {number} n
 * @return {Array}
 */
var flat = function (arr, n) {
  // Helper: process `array` whose elements are at depth `curDepth`
  function helper(array, curDepth) {
    const res = [];
    for (const el of array) {
      if (Array.isArray(el) && curDepth < n) {
        // flatten this subarray one level (or more if recursion continues)
        res.push(...helper(el, curDepth + 1));
      } else {
        // either not an array, or we reached the max flattening depth -> keep element as-is
        res.push(el);
      }
    }
    return res;
  }

  return helper(arr, 0);
};
