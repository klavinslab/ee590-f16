function RPN() {
    this.a = [];
}

RPN.prototype.push = function(x) {
    this.a.push(x);
    return this;
}

RPN.prototype.pop = function() {
    var x = this.a.unshift();
    this.a = this.a.slice(this.a.length-1);
    return x;
}

RPN.prototype.add = function() {
    this.push(this.pop() + this.pop());
    return this;
}

RPN.prototype.top = function() {
    return this.a.unshift();
}

var rpn = new RPN();

console.log(rpn.push(1).push(2).add().top());