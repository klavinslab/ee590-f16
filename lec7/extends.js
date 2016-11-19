
class Square  {

  constructor(w) {
    this.width = w;
  }

  get area() {
    return this.width * this.width;
  }

  set area(value) {
    this.width = this.width = Math.sqrt(value);
  }

}

s = new Square();
s.area = 10;
console.log(s.area);

t = Object.create(Square,{width: 10});
