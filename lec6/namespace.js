obj = (function() {

	var m = 1,
            b = 2;

        function f(x) {
	    return m*x + b;
        }

	return {
	    name: "line",
            func: f
        }

})();

console.log(obj.name);
console.log(obj.func(10));
