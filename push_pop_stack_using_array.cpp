#include <iostream>
using namespace std;
class Stack
{
private:
    int size;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        arr = new int[size];
        cout << "Stack has been created succesfully." << endl;
    }
    ~Stack()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == size - 1;
    }
    int push(int val)
    {
        if (isFull())
        {
            cout << "Stack Overflow! Cannot push " << val << " to the stack" << endl;
            return -1;
        }
        else
        {
            arr[++top] = val;
            return val;
        }
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow! Cannot pop from the stack" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }
};
int main()
{
    Stack sp(10);
    sp.push(1);
    sp.push(23);
    sp.push(99);
    sp.push(75);
    sp.push(3);

    cout << "Popped " << sp.pop() << " from the stack" << endl; // Last in first out!
    cout << "Popped " << sp.pop() << " from the stack" << endl;
    cout << "Popped " << sp.pop() << " from the stack" << endl;
    
    cout << "Pushed " << sp.push(1538) << " from the stack" << endl;
    cout << "Pushed " << sp.push(1539) << " from the stack" << endl;
    cout << "Pushed " << sp.push(1540) << " from the stack" << endl;

    return 0;
}