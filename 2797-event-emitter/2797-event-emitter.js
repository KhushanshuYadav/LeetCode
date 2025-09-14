class EventEmitter {


    constructor(){
        this.m=new Map();
    }

    /**
     * @param {string} eventName
     * @param {Function} callback
     * @return {Object}
     */
    subscribe(eventName, callback) {

        if(!this.m.has(eventName)) this.m.set(eventName,[]);
        this.m.get(eventName).push(callback);
        
        return {
            unsubscribe: () => {

                let index = this.m.get(eventName).indexOf(callback); 

                if (index !== -1) this.m.get(eventName).splice(index, 1); 

            }
        };
    }
    
    /**
     * @param {string} eventName
     * @param {Array} args
     * @return {Array}
     */
    emit(eventName, args = []) {

        const ans=[];
        if (!this.m.has(eventName)) return ans;
    

        for(let e of this.m.get(eventName)){
            ans.push(e(...args));
        }

        return ans;
        
    }
}

/**
 * const emitter = new EventEmitter();
 *
 * // Subscribe to the onClick event with onClickCallback
 * function onClickCallback() { return 99 }
 * const sub = emitter.subscribe('onClick', onClickCallback);
 *
 * emitter.emit('onClick'); // [99]
 * sub.unsubscribe(); // undefined
 * emitter.emit('onClick'); // []
 */