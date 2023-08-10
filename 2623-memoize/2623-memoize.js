/**
 * @param {Function} fn
 */
function memoize(fn) {
    let cache = [];
    return function(...args) {
        let n = JSON.stringify(args);
        if(n in cache){
            return cache[n];
        }
        else{
            let res = fn(...args);
            cache[n] = res;
            return res;
        }
    }
}


 // let cache = {};
    // return function(...args) {
    //     let n = JSON.stringify(args);
    //     if(n in cache){
    //         return cache[n];
    //     }
    //     else{
    //         let res = fn(...args);
    //         cache[n] = res;
    //         return res;
    //     }
    // }

/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */