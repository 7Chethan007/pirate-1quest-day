// Last updated: 3/25/2026, 9:02:38 AM
/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */
var compactObject = function(obj) {
    // If the value itself is falsy (and not an object), return undefined to signal removal
    if (!obj) return obj;

    // Handle arrays: filter falsy values and recursively clean nested objects
    if (Array.isArray(obj)) {
        return obj
            .map(compactObject)           // recursively compact elements
            .filter(value => Boolean(value)); // remove falsy results
    }

    // Handle objects
    if (typeof obj === 'object') {
        const result = {};
        for (let key in obj) {
            const compacted = compactObject(obj[key]);
            if (Boolean(compacted)) {
                result[key] = compacted;
            }
        }
        return result;
    }

    // Primitive truthy value (number, string, etc.)
    return obj;
};
