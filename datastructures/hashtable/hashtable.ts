class HashTable {
  table: any[];
  size: number;
  constructor() {
    this.table = [];
    this.size = 0;
  }

  // Helper function to calculate the hash value of a key
  hash(key) {
    let hash = 0;
    for (let i = 0; i < key.length; i++) {
      hash += key.charCodeAt(i);
    }
    return hash % this.table.length;
  }

  // Put a key-value pair in the hashtable
  put(key, value) {
    const index = this.hash(key);
    let current = this.table[index];

    while (current) {
      if (current.key === key) {
        current.value = value; // Update the existing value for the key
        return;
      }
      current = current.next;
    }

    // Add a new entry for the key-value pair
    const node = new Item(key, value);
    node.next = this.table[index];
    this.table[index] = node;
    this.size++;
  }

  // Get the value for a given key
  get(key) {
    const index = this.hash(key);
    let current = this.table[index];
    while (current) {
      if (current.key === key) {
        return current.value;
      }
      current = current.next;
    }
    return undefined;
  }
}

class Item {
  key: any;
  value: any;
  next: any;
  constructor(key, value) {
    this.key = key;
    this.value = value;
    this.next = null;
  }
}

class Something {
  items = new Array(100);
  put(key: number) {
    this.items[key] = true;
  }
  get(key: number) {
    return this.items[key];
  }
}

function cmpTwoArr(arr1: number[], arr2: number[]) {
  const table = new Map();
  arr1.forEach((item) => {
    table.set(item, true);
  });
  console.log(table.get(3));
  for (let i = 0; i < arr2.length; i++) {
    const item = arr2[i];
    if (table.get(item)) return true;
    
  }
  return false;
}

const arr1 = [1, 3, 6];
const arr2 = [2, 4, 6];

console.log(cmpTwoArr(arr1, arr2));
