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
    int peek(int i)
    {
        int arrayInd = top - i + 1;
        if (arrayInd < 0)
        {
            cout << "Invalid position for peek." << endl;
            return -1;
        }
        else
        {
            return arr[arrayInd];
        }
    }
    int getTop()
    {
        return top;
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
    sp.push(64);
    sp.push(57);
    sp.push(46);
    sp.push(89);
    sp.push(6);

    for (int j = 1; j <= sp.getTop()+1; j++)
    {
        cout << "The value at position " << j << " is: " << sp.peek(j) << endl;
    }

    return 0;
}