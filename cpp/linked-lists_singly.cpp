/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <climits>
using namespace std;

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
        int min;
        int max;
    
    public:
        LinkedList(int item);
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

void LinkedList::insert_start(int item) {
    Node *new_node = new Node(item);
    if (head == NULL) {
        head = new_node;
        return;
    }
    new_node->link = head;
    head = new_node;
    if (item < min) min = item;
    if (item > max) max = item;
    return; 
}

void LinkedList::insert_end(int item) {
    Node *new_node = new Node(item);
    Node *cur = head;
    while (cur->link) {
        cur = new_node->link;
    }
    cur->link = new_node;
    if (item < min) min = item;
    if (item > max) max = item;
    return;
}

int main()
{
    LinkedList list;
    list.insert_start
    return 0;
}