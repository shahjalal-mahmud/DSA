#include <iostream>
using namespace std;

class Array_Operation
{
    int *arr;
    int capacity;

public:
    Array_Operation(int cap) : capacity(cap)
    {
        arr = new int[capacity];
    }
    ~Array_Operation()
    {
        delete[] arr;
    }
    void setArray(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter an element for position " << i + 1 << ": ";
            cin >> arr[i];
        }
    }
    int insertElement(int size, int index, int element)
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
    void Display(int size)
    {
        cout << "[";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    int capacity, size;
    cout << "Enter the capacity and size of the array: " << endl;
    cin >> capacity >> size;

    Array_Operation Ao(capacity);
    Ao.setArray(size);

    cout << "Displaying the given array: ";
    Ao.Display(size);

    int element, index;
    cout << "Enter the index where you want to insert an element and the element value: ";
    cin >> index >> element;

    int result = Ao.insertElement(size, index, element);
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
        Ao.Display(size);
    }

    return 0;
}
