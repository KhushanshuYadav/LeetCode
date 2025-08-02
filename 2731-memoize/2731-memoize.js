/**
 * @param {Function} fn
 * @return {Function}
 */
function memoize(fn) {

    const m=new Map();
    
    return function(...args) {

       if(!m.has(JSON.stringify(args)) )m.set(JSON.stringify(args),fn(...args));

       return m.get(JSON.stringify(args));

       
        
    }
}


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