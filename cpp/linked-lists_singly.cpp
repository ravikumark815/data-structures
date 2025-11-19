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
        void reverse();
        void size();
        void find(int item);
        void has_cycle();
        ~LinkedList();
};

LinkedList::LinkedList() {
    head = NULL;
    min = INT_MAX;
    max = INT_MIN;
    cout << "--- Linked List Created ---\n";
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
    cout << "--- Linked list deleted ---\n";
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
        new_node->link = cur->link;
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
    return;
}

void LinkedList::reverse() {
    if (head == NULL) {
        cout << "Linked List empty\n";
        return;
    }
    if (head->link == NULL) {
        return;
    }
    Node *prev = NULL, *cur = head, *next = NULL;
    
    while(cur) {
        next = cur->link;
        cur->link = prev;
        prev = cur;
        cur = next;
    }
    head = prev;
    return;
}

void LinkedList::size() {
    if (head == NULL) {
        cout << "Size: 0\n";
        return;
    }
    if (head->link == NULL) {
        cout << "Size: 1\n";
        return;
    }
    int count = 0;
    Node *cur = head;
    while (cur) {
        cur = cur->link;
        count++;
    }
    cout << "Size: " << count << endl;
}

void LinkedList::find(int item) {
    if (head == NULL) {
        cout << "Linked List empty\n";
        return;
    }
    Node *cur = head;
    int pos = 1;
    while (cur) {
        if (cur->data == item) {
            cout << item << " found at position: " << pos << endl;
            return;
        }
        pos++;
        cur = cur->link;
    }
    cout << item << " not found in the linked list\n";
    return;
}

void LinkedList::has_cycle() {
    if (head == NULL) {
        cout << "Linked List empty\n";
        return;
    }
    if (head->link == NULL) {
        cout << "No cycles present\n";
        return;
    }

    Node *slow = head, *fast = head;
    while (fast && fast->link) {
        slow = slow->link;
        fast = fast->link->link;
        if (slow == fast) {
            cout << "Cycles Present. Data: " << slow->data << endl;
            return;
        }
    }
    cout << "No cycles present\n";
    return;
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
    list.insert_start(101);
    list.print();
    list.insert_after(202, 303);
    list.print();
    list.reverse();
    list.print();
    list.size();
    list.find(202);
    list.find(900);
    list.has_cycle();
    return 0;
}