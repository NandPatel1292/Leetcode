/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    // let a = [];
    // for(let i = 0; i<arr.length; i++){
    //     a[i] = fn(arr[i],i);
    // }
    const g = arr.map(fn);
    return g;
};