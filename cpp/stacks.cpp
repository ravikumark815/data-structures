/*
Author: Ravi Koothati
GitHub: https://github.com/ravikumark815
*/

#include <iostream>
#include <vector>

using namespace std;

class Stack
{
    private:
        vector<int> stack_arr;
        int top;
        int size;
    
    public:
        Stack(int stack_size);
        void push(int data);
        int pop();
        void print();
};

Stack::Stack(int stack_size) {
    size = stack_size;
    top = -1;
    stack_arr.resize(size);
}

void Stack::push(int data) {
    if (top == size - 1) {
        cout << "Stack Full\n";
        return;
    }
    stack_arr[++top] = data;
}

int Stack::pop() {
    if (top == -1) {
        cout << "Stack Empty\n";
        return -1;
    }
    cout << stack_arr[top--] << " popped\n";
    return 0;
}

void Stack::print() {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << stack_arr[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int size;
    cout << "Enter Stack size: ";
    cin >> size;
    Stack st(size);
    st.push(100);
    st.push(200);
    st.push(300);
    st.print();
    st.push(400);
    st.pop();
    st.print();
    st.pop();
    st.pop();
    st.print();
    st.pop();
    st.print();
    return 0;
}