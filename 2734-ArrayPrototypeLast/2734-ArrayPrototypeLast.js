// Last updated: 3/25/2026, 9:03:00 AM
/**
 * @return {null|boolean|number|string|Array|Object}
 */
Array.prototype.last = function() {
    // If array is empty, return -1
    if (this.length === 0) return -1;
    // Otherwise, return the last element
    return this[this.length - 1];
};


/**
 * const arr = [1, 2, 3];
 * arr.last(); // 3
 */