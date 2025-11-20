/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <queue>

using namespace std;

class Node 
{
    public: 
        int data;
        Node *left;
        Node *right;
        Node *parent;

        Node (int item) {
            data = item;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
};

class BinarySearchTree 
{
    public:
        Node *root;
        BinarySearchTree();
        ~BinarySearchTree();
        void insert(int item);
        void del(int item);
        void print();
        void print_helper(Node *ptr, int level);
        void min_element();
        void max_element();
        void inorder_helper(Node *root);
        void inorder();
        void preorder_helper(Node *root);
        void preorder();
        void postorder_helper(Node *root);
        void postorder();
        void levelorder();
};

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    cout << "---Binary Search Tree created---\n";
}

BinarySearchTree::~BinarySearchTree() {
    cout << "---Binary Search Tree destroyed---\n";
}

void BinarySearchTree::insert(int item) {
    Node *new_node = new Node(item);

    if (root == NULL) {
        root = new_node;
        return;
    }
    
    Node *cur = root;
    while(cur) {
        if((cur->data > item) && (cur->left != NULL)) {
            cur = cur->left;
        }
        else if ((cur->data < item) &&(cur->right != NULL)) {
            cur = cur->right;
        }
        else {
            break;
        }
    }
    if (cur->data > item) {
        cur->left = new_node;
        new_node->parent = cur;
    }
    else {
        cur->right = new_node;
        new_node->parent = cur;
    }
    
    return;
}

void BinarySearchTree::del(int item) {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return;
    }
    // Find the node to be deleted
    Node *cur = root;
    while (cur) {
        if (item < cur->data) {
            cur = cur->left;
        } else if (item > cur->data) {
            cur = cur->right;
        } else {
            break;
        }
    }
    if (cur == NULL) {
        cout << item << " not found in the tree\n";
        return;
    }
    // Case 1: Leaf node
    if ((cur->left == NULL) && (cur->right == NULL)) {
        cur->parent->left = NULL;
        cur->parent->right = NULL;
        cout << cur->data << " deleted\n";
        delete cur;
        return;
    }

    // Case 2: Two children
    if ((cur->left) && (cur->right)) {
        Node *temp = cur->right;
        while (temp->left) {
            temp = temp->left;
        }
        int successor_data = temp->data;
        del(temp->data);
        cur->data = successor_data;
        return;
    }

    // Case 3: One child
    if (cur->left) {
        cur->parent->left = cur->left;
        cout << cur->data << " deleted\n";
        delete cur;
        return;
    } else {
        cur->parent->right = cur->right;
        cout << cur->data << " deleted\n";
        delete cur;
        return;
    }
}

void BinarySearchTree::print_helper(Node *node, int level) {
    if (node == NULL) return;
    print_helper(node->right, level+1);
    cout << "\n";
    for (int i = 0; i< level; i++) {
        cout << "    ";
    }
    cout << node->data;
    print_helper(node->left, level+1);
}

void BinarySearchTree::print() {
    cout << "--- Tree ---";
    if (root == NULL) return;
    if ((root->left == NULL) && (root->right == NULL)) {
        cout << root->data;
        return;
    }
    print_helper(root, 0);
    cout << endl;
    return;
}

void BinarySearchTree::min_element() {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return;
    }

    Node *cur = root;
    while (cur->left) {
        cur = cur->left;
    }

    cout << "Min: " << cur->data << endl;
    return;
}

void BinarySearchTree::max_element() {
    if (root == NULL) {
        cout << "Tree Empty\n";
        return;
    }

    Node *cur = root;
    while (cur->right) {
        cur = cur->right;
    }
    cout << "Max: " << cur->data << endl;
    return;
}

void BinarySearchTree::inorder_helper(Node *root) {
    if (root == NULL) return;
    inorder_helper(root->left);
    cout << root->data << " ";
    inorder_helper(root->right);
    return;
}

void BinarySearchTree::inorder() {
    cout << "Inorder Traversal: ";
    inorder_helper(root);
    cout << endl;
    return;
}

void BinarySearchTree::preorder_helper(Node *root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder_helper(root->left);
    preorder_helper(root->right);
    return;
}

void BinarySearchTree::preorder() {
    cout << "Preorder Traversal: ";
    preorder_helper(root);
    cout << endl;
    return;
}

void BinarySearchTree::postorder_helper(Node *root) {
    if (root == NULL) return;
    postorder_helper(root->left);
    postorder_helper(root->right);
    cout << root->data << " ";
    return;
}

void BinarySearchTree::postorder() {
    cout << "Postorder Traversal: ";
    postorder_helper(root);
    cout << endl;
    return;
}

void BinarySearchTree::levelorder() {
    queue <Node *> q;
    q.push(root);
    
    cout << "Levelorder Traversal: ";
    while (!q.empty()) {
        Node *cur = q.front();
        q.pop();
        cout << cur->data << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    cout << endl;
    
    return;
}

int main()
{
    BinarySearchTree bst;
    // Inserting elements in a way that creates a more balanced tree
    bst.insert(500);
    bst.insert(250);
    bst.insert(750);
    bst.insert(150);
    bst.insert(350);
    bst.insert(650);
    bst.insert(850);
    bst.insert(200);
    bst.insert(450);
    bst.insert(950);
    bst.print();
    bst.min_element();
    bst.max_element();
    bst.inorder();
    bst.preorder();
    bst.postorder();
    bst.levelorder();
    bst.del(950);  // Deleting a leaf node
    bst.del(150);  // Deleting a node with one child
    bst.del(750);  // Deleting a node with two children
    bst.del(500);
    bst.print();
    bst.del(999); // Deleting a non-existent node
    return 0;
}