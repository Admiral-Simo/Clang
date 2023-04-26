class Stack {
  size: number;
  items: any[];
  constructor() {
    this.items = [];
    this.size = 0;
  }

  // checking if the stack is empty
  isEmpty() {
    return !this.size;
  }

  // push to the top of the stack
  push(data: any) {
    this.items[this.size] = data;
    console.log(`${data} added to ${this.size}`);
    this.size++;
    return this.size - 1;
  }

  // pop from the top of the stack
  pop() {
    if(this.size === 0) return undefined
    let deleteItem = this.items[this.size - 1]
    this.size--;
    console.log(`${deleteItem} removed}`)
    return deleteItem
  }
}

const s = new Stack();

s.push(100);
s.push(200);
s.push(300);

console.log(s.pop());
console.log(s.pop());
console.log(s.pop());

console.log(s.isEmpty())
