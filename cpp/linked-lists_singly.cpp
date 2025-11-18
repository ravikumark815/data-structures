/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <climits>

class Node {
    public:
        int data;
        Node *link;

        Node(int item) {
            data = item;
            link = NULL;
        }
};

class LinkedList {
    private:
        Node *head;
        Node *min;
        Node *max;
    
    public:
        LinkedList();
        void insert_start(int item);
        void insert_end(int item);
        void insert_after(int item);
        void delete_start();
        void delete_end();
        void delete_after(int item);
        void print();
};

LinkedList::LinkedList(int item) {
    head = NULL;
    min = INT_MAX;
    max = INT_MIN;
}

LinkedList::LinkedList(const LinkedList& list) {
    if (list.head == NULL) head = NULL;
    else {
        Node *ptr1, *ptr2;
        ptr1 = list.head;
        ptr2 = head = new Node(ptr1->data);
    }
}

void LinkedList::insert_start(int item) {
    Node node(item);
    node.link = head;
    head = node;
    if (item < min) min = item;
    if (item > max) max = item;
    return; 
}

void LinkedList::insert_end(int item) {
    Node node(item);

    while (node.link) {
        n
    }
    if (item < min) min = item;
    if (item > max) max = item;
    return;
}