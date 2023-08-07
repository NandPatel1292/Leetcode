/**
 * @return {number}
 */
var argumentsLength = function(...args) {
    var c = 0;
    var ar = [...arguments];
    ar.map(() => {
        c++;
        
    })
 return c;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */