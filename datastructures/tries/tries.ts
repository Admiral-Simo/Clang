class TrieNode {
    data: any;
    left: any;
    right: any;
    constructor(data, left = null, right = null) {
        this.data = data;
        this.left = left;
        this.right = right;
    }
}

class BST {
    root: any;
    constructor() {
        this.root = null;
    }
    add(data: any) {
        const node = this.root;
        if (node === null) {
            this.root = new TrieNode(data);
            return;
        } else {
            const searchTree = function(node) {
                if (data < node.data) {
                    
                }
            }
        }
    }
}