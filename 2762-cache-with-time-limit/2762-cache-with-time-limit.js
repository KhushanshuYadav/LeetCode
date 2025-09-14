var TimeLimitedCache = function() {

    this.m=new Map();
    
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {

    if(this.m.has(key)){

        clearTimeout(this.m.get(key).id)

        let tId=setTimeout(()=>this.m.delete(key),duration)
        
        this.m.set(key,{val:value,id:tId});
        return true;
    }else{

        let tId=setTimeout(()=>this.m.delete(key),duration)

        this.m.set(key,{val:value,id:tId});
        return false;
    }
    
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {

    if(this.m.has(key)) return this.m.get(key).val;

    else return -1;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {

    return this.m.size;
    
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */