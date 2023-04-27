export class Queue {
  items: any[];
  size: number;
  constructor() {
    this.items = [];
    this.size = 0;
  }

  // add items to the tail of the list
  enqueue(item: any): void {
    this.items.unshift(item);
    this.size++;
  }

  // add items to the head of the list
  dequeue(): void {
    this.items.pop();
    this.size--;
  }

  // show the next item to leave if we were to dequeue
  peek() {
    if (this.size) {
      console.log(this.items[this.size - 1]);
    }
  }
  
  // show all items in that list
  printData(): void {
    console.log(this.items);
  }

  // show size of the list
  getSize(): void {
    console.log(this.size);
  }
}