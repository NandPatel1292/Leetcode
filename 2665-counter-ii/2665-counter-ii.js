/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let x = init;
    return new Proxy({},{
        get : (target,key) => {
            if(key === "increment"){
                return () => ++x;
            }
            else if(key === "decrement"){
                return () => --x;
            }
            else if(key === "reset"){
                return () => (x = init);
            }
            else{
                throw new Error("nikal kutariya");
            }
        }
    })
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */