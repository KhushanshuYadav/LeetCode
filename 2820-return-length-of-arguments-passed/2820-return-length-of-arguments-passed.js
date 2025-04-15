/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    //work is to destructure or to recive an indefinate number of arguments
    
    return args.length;
    
};

/**
 * argumentsLength(1, 2, 3); // 3
 */