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
        cout << "Set all the value of the Array: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Enter an element index(" << i << "): ";
            cin >> arr[i];
        }
    }
    void displayArray(int size)
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
    int indexInsertion(int size, int index, int element)
    {
        if (index < 0 || index > size)
        {
            return -1; // index is out of bounds
        }

        if (size >= capacity)
        {
            return -2; // array is full
        }
        for (int i = size; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = element;
        return 0; // successful insertion
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
    Ao.displayArray(size);

    char operation;
    cout << "Enter 'i' for insertion and 'd' for deletion an element: ";
    cin >> operation;
    // code for insertion
    if (operation == 'i')
    {
        int index, element;
        cout << "Enter the index where you want to insert an element and the element value: ";
        cin >> index >> element;
        int result = Ao.indexInsertion(size, index, element);
        if (result == -1)
        {
            cout << "Error: Index out of bounds." << endl;
        }
        else if (result == -2)
        {
            cout << "Error: Array is full." << endl;
        }
        else if (result == 0)
        {
            size++; // increase size as we have inserted an element
            cout << "Element inserted successfully. Updated array: ";
            Ao.displayArray(size);
        }
    }
    // code for deleltion
    if (operation == 'd')
    {
        int index;
        cout << "For Deletion enter the index: ";
        cin >> index;

        int result = Ao.indexDeletion(size, index);
        if (result == 0)
        {
            size--; // decrease size as we have deleted an element
            cout << "Element deleted successfully: Updated Array";
            Ao.displayArray(size);
        }

        else
        {
            cout << "Index out of bounds.";
        }
    }

    return 0;
}