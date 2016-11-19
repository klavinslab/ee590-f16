let JSONable = (superclass) => class extends superclass {
  stringify() {
    return JSON.stringify(this);
  }
};

class Stack extends JSONable(Array) {

  constructor() {
    super();
  }

  get top() {
    if ( this.length > 0 ) {
      return this[this.length-1];
    } else {
      return undefined;
    }
  }

}

module.exports = Stack;
