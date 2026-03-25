// Last updated: 3/25/2026, 9:02:56 AM
/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function (fn) {
  const grouped = {};
  for (let i = 0; i < this.length; i++) {
    const key = fn(this[i]);              // fn returns a string key
    if (!Object.prototype.hasOwnProperty.call(grouped, key)) {
      grouped[key] = [];
    }
    grouped[key].push(this[i]);           // preserve original order
  }
  return grouped;
};

/** Examples */
// [1,2,3].groupBy(String) -> {"1":[1], "2":[2], "3":[3]}
