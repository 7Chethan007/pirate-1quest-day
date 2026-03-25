// Last updated: 3/25/2026, 9:02:53 AM
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const filteredArr = [];                // create an empty array for filtered results
    for (let i = 0; i < arr.length; i++) {
        if (fn(arr[i], i)) {          // call fn with value and index
            filteredArr.push(arr[i]);      // if fn returns truthy, keep the element
        }
    }
    return filteredArr;                    // return filtered array
};
