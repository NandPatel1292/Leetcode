/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
//         let ans = x;
//         for(let i = functions.length-1; i>= 0; i--){
//             const tmp = functions[i];
            
//             ans = tmp(ans);
//         }
        
//       return ans;
        
        return functions.reduceRight((acc,f) => f(acc),x);
    };
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */