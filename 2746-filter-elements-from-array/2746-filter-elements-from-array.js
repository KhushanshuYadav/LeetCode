/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let ans=[];

    arr.forEach(
        (num,i)=>{
            if(fn(num,i)) ans.push(num);
        }
    )
    
    return ans;
};