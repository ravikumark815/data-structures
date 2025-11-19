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
        LinkedList();
        void insert_start(int item);
        void insert_end(int item);
        void insert_after(int pos, int item);
        void delete_start();
        void delete_end();
        void delete_pos(int pos);
        void print();
        void min_max(int item);
        ~LinkedList();
};

LinkedList::LinkedList() {
    head = NULL;
    min = INT_MAX;
    max = INT_MIN;
}
LinkedList::~LinkedList() {
    if (head != NULL) {
        Node *prev = NULL;
        Node *cur = head;
        while(cur) {
            prev = cur;
            cur = cur->link;
            delete prev;
        }
    }
    cout << "List deleted\n";
}

void LinkedList::insert_start(int item) {
    Node *new_node = new Node(item);
    if (head == NULL) {
        head = new_node;
        min_max(new_node->data);
        return;
    }
    new_node->link = head;
    head = new_node;
    min_max(new_node->data);
    return; 
}

void LinkedList::insert_after(int pos, int item) {
    Node *new_node = new Node(item);
    if (head == NULL) {
        head = new_node;
        min_max(new_node->data);
        return;
    }
    Node *cur = head;
    while ((cur->link) && (cur->data != pos)) {
        cur = cur->link;
    }
    if(cur->data == pos) {
        cur->link = new_node;
        min_max(new_node->data);
    }
    return;
}

void LinkedList::insert_end(int item) {
    Node *new_node = new Node(item);
    if (head == NULL) {
        head = new_node;
        min_max(new_node->data);
        return;
    }
    Node *cur = head;
    while (cur->link) {
        cur = cur->link;
    }
    cur->link = new_node;
    min_max(new_node->data);
    return;
}

void LinkedList::delete_start() {
    if (head == NULL) {
        cout << "Linked List Empty\n";
        return;
    }
    if (head->link == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node *cur = head;
    head = head->link;
    cout << cur->data << " deleted\n";
    delete cur;
    return;
}

void LinkedList::delete_pos(int pos) {
    if (head == NULL) {
        cout << "Linked List Empty\n";
        return;
    }
    Node *prev = NULL;
    Node *cur = head;
    while ((cur->link) && (cur->data != pos)) {
        prev = cur;
        cur = cur->link;
    }
    if (cur->data == pos){
        prev->link = cur->link;
        delete cur;
        cout << pos << " deleted\n";
        return;
    }
    cout << pos << " not found\n";

    return;
}

void LinkedList::delete_end() {
    if (head == NULL) {
        cout << "Linked List Empty\n";
        return;
    }
    Node *prev = NULL;
    Node *cur = head;
    while (cur->link) {
        prev = cur;
        cur = cur->link;
    }
    prev->link = NULL;
    cout << cur->data << " deleted\n";
    delete cur;
    return;
}

void LinkedList::print() {
    if (head == NULL) {
        cout << "Linked List Empty\n";
        return;
    }
    cout << "Linked List: ";
    Node *cur = head;
    while(cur->link) {
        cout << cur->data << "->";
        cur = cur->link;
    }
    cout << cur->data << endl;
    return;
}

void LinkedList::min_max(int item) {
    if (item < min) min = item;
    if (item > max) max = item;
}

int main()
{
    LinkedList list;
    list.print();
    list.insert_start(101);
    list.insert_end(202);
    list.insert_after(202, 303);
    list.insert_end(404);
    list.insert_end(505);
    list.print();
    list.delete_start();
    list.print();
    list.delete_end();
    list.print();
    list.delete_pos(303);
    list.print();
    return 0;
}