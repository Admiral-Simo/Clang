class Item {
  data: any;
  next: Item | null;

  constructor(data: any, next: Item | null = null) {
    this.data = data;
    this.next = next;
  }
}


export class LinkedList {
  head: any;
  size: number;
  constructor() {
    this.head = null;
    this.size = 0;
  }

  // Insert first node
  unshift(data: any) {
    this.head = new Item(data, this.head);
    this.size++;
  }

  // Insert last node

  push(data: any) {
    let node = new Item(data);
    let current = this.head;

    // If empty, make it a head
    if (!this.head) {
      this.head = node;
    } else {
      while (current.next) {
        current = current.next;
      }

      current.next = node;
    }
    this.size++;
  }

  // Insert at index
  insertAt(data: any, index: number) {
    // Index out of range
    if (index >= this.size || index < 0) {
      console.log("index out of range");
      return;
    }

    // if index = 0
    if (index === 0) {
      this.unshift(data);
      return;
    }

    const node = new Item(data);

    // loop through
    let previous, current;
    let count = 0;
    current = this.head;

    while (count < index) {
      previous = current; // Node before index
      count++;
      current = current.next; // Node after index
    }

    previous.next = node;
    node.next = current;
    this.size++;
  }

  // get size
  getSize() {
    console.log(this.size);
  }

  // Get at index

  getAt(index: number) {
    if (index >= this.size || index < 0) {
      return;
    }

    let current = this.head;

    for (let i = 0; i < index; i++) {
      current = current.next;
    }

    console.log(current.data);
  }

  // Rmove at index

  removeAt(index: number) {
    // index out of range
    if (index >= this.size || index < 0) {
      return;
    }

    // loop through the list stop at index = index and get the next element and before elemtn and connect them

    if (index === 0) {
        this.head = this.head.next;
        return;
    }

    let current, previous;
    current = this.head;

    for (let count = 0; count < index; count++) {
      previous = current;
      current = current.next;
    }
    previous.next = current.next;
    this.size--;

  }

  // Clear list

  clearList() {
    this.head = null;
    this.size = 0;
  }

  // Print list data

  printData() {
    let head = this.head;
    while (head != null) {
      console.log(head.data);
      head = head.next;
    }
  }
}
