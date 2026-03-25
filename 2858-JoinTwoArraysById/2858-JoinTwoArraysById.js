// Last updated: 3/25/2026, 9:02:28 AM
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    // Use a Map to track merged objects by their id
    const map = new Map();

    // Insert all objects from arr1 into the map
    for (const obj of arr1) {
        map.set(obj.id, { ...obj });  // clone to avoid mutation
    }

    // Merge or insert objects from arr2
    for (const obj of arr2) {
        if (map.has(obj.id)) {
            // Merge: arr2 overrides arr1's values
            map.set(obj.id, { ...map.get(obj.id), ...obj });
        } else {
            map.set(obj.id, { ...obj });
        }
    }

    // Convert the map values to an array and sort by id
    return Array.from(map.values()).sort((a, b) => a.id - b.id);
};
