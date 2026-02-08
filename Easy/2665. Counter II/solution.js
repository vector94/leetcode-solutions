/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    return new Counter(init);
};

class Counter {
    constructor(init){
        this.init = init;
        this.presentCount = init;
    }

    increment() {
        return ++this.presentCount;
    }
    decrement() {
        return --this.presentCount;
    }
    reset(){
        return this.presentCount = this.init;
    }
}

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */