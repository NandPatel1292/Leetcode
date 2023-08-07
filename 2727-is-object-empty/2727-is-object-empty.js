/**
 * @param {Object | Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let x = JSON.stringify(obj);
    if(x.length>2){
        return false;
    }
    else{
        return true;
    }
};