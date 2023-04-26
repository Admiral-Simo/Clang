import { LinkedList } from "./linkedlist/linkedlist";

const list = new LinkedList();


list.push(1);
list.push(2);
list.push(3);
list.push(4);

list.removeAt(3);

list.unshift(2000);
list.insertAt('inserted at 3',3);
list.insertAt('inserted at 3',3);

list.printData();


list.getAt(4);

