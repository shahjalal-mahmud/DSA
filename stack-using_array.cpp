#include <iostream>
using namespace std;
class Stack
{
    int size;
    int top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;   // top == -1 means Empty. //top == size-1 means Full.
        arr = new int[size];
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
};
int main()
{
    Stack s(100);

    if (s.isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    if (s.isFull())
    {
        cout << "The stack is Full." << endl;
    }

    return 0;
}