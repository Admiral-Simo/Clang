export class Stack {
  size: number;
  items: any[];
  constructor() {
    this.items = [];
    this.size = 0;
  }

  // checking if the stack is empty
  isEmpty() {
    console.log(!this.size ? "Stack is empty" : "Stack is not empty");
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

  // Check top element in stack
  peek() {
    console.log(`Top element is ${this.items[this.size - 1]}`)
    return this.items[this.size -1]
  }

  // Check size of stack
  getSize() {
    console.log(`Size of stack: ${this.size}`);
    return this.size;
  }

  // Print elements in stack
  print() {
   for (let i = 0; i < this.size; i++) {
    console.log(this.items[i])
    
   }
  }

  // Clear all elements from stack
  clear() {
    this.items = [];
    this.size = 0;
    console.log('Stack cleared.');
  }
}