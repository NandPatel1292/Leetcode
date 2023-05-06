/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    let sum = n-1;
    return function() {
        
        sum += 1;
        return sum;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */