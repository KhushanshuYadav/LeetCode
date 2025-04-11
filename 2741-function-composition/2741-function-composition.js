/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    
    return function(x) {

        let ans=x;

        const n=functions.length;
        for(let i=n-1;i>=0;i--){

            let f=functions[i];
            ans=f(ans);
        }

        return ans;
        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */