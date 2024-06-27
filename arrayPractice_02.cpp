#include <iostream>
using namespace std;

class ArrayOperation
{
    int *arr;
    int capacity;

public:
    ArrayOperation(int cap) : capacity(cap)
    {
        arr = new int[capacity];
    }
    ~ArrayOperation()
    {
        delete[] arr;
    }
    void setArray(int size)
    {
        cout << "Set the Array: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter an element for index(" << i << "): ";
            cin >> arr[i];
        }
    }

    void Display(int size)
    {
        cout << "Array: [";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i < size - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }
    int indexDeletion(int size, int index)
    {
        if (index < 0 || index > size)
        {
            return -1; // Index out of bounds
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        return 0;
    }
};

int main()
{
    int size, capacity;
    cout << "Enter the array capacity and size: ";
    cin >> capacity >> size;

    ArrayOperation Ao(capacity);
    Ao.setArray(size);
    Ao.Display(size);

    int index;
    cout << "For Deletion enter the index: ";
    cin >> index;

    int result = Ao.indexDeletion(size, index);
    if (result == 0)
    {
        size--;
        cout << "Element deleted successfully: Updated Array";
        Ao.Display(size);
    }

    else
    {
        cout << "Index out of bounds.";
    }

    return 0;
}