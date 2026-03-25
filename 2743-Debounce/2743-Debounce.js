// Last updated: 3/25/2026, 9:02:54 AM
/**
 * @param {Function} fn
 * @param {number} t milliseconds
 * @return {Function}
 */
var debounce = function(fn, t) {
    let timeout; // holds the timer ID

    return function(...args) {
        // clear any existing scheduled call
        clearTimeout(timeout);

        // schedule a new one
        timeout = setTimeout(() => {
            fn(...args);
        }, t);
    };
};


/**
 * const log = debounce(console.log, 100);
 * log('Hello'); // cancelled
 * log('Hello'); // cancelled
 * log('Hello'); // Logged at t=100ms
 */