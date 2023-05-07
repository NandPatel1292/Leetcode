/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let x = init;
    return {
        increment: function(){
            x += 1;
            // init = x;
            return x;
        },
            decrement: function() {
                x -= 1;
                // init = x;
                return x;
            },
                reset: function() {
                    x = init;
                    // init = x;
                    return x;
                }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */