/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let filteredArr = [];
    arr.forEach((element, index) => {
        if (fn(element, index)){
            filteredArr.push(element);
        }
    })
    return filteredArr;
};