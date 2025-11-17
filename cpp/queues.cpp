/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>
using namespace std;

class Queue
{
    private:
        int front;
        int rear;
        int size;
        vector<int> queue;
    
    public:
        Queue();
        void push(int item);
        void pop();
        bool full();
        bool empty();
        void front_element();
        void rear_element();
        void print();
};

Queue::Queue() {
    front = -1;
    rear = -1;
    cout << "Enter queue size: ";
    cin >> size;
    queue.resize(size);
    return;
}

void Queue::push(int item) {
    if (full()) {
        cout << "Queue Full\n";
        return;
    }
    if (empty()) 
        front = 0;
    
    queue[++rear] = item;
    cout << item << " pushed to queue\n";
    return;
}

void Queue::pop() {
    if (empty()) {
        cout << "Queue Empty\n";
        return;
    }
    cout << queue[front] << " popped from queue\n";
    front++;

    if (empty()) {
        front = -1;
        rear = -1;
    }

    return;
}

bool Queue::full() {
    return (rear == size);
}

bool Queue::empty() {
    return ((front == -1) || (front > rear));
}

void Queue::front_element() {
    if (empty()) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Front: " << queue[front] << endl;
    return;
}

void Queue::rear_element() {
    if (empty()) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Rear: " << queue[rear] << endl;
    return;
}

void Queue::print() {
    if (empty()) {
        cout << "Queue Empty\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    Queue q;
    q.push(100);
    q.push(200);
    q.push(300);
    q.print();
    q.pop();
    q.print();
    q.pop();
    q.pop();
    q.pop();
    q.print();

    return 0;
}