/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {

    const n=nums.length;

    //if(n===0) return init;

    for(let i=0;i<n;i++){

        init=fn(init,nums[i]);

    }


    return init;
    
};