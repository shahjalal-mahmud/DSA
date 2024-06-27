#include <iostream>
using namespace std;

class Array_insertion
{
private:
    int *arr;
    int capacity;

public:
    Array_insertion(int cap) : capacity(cap)
    {
        arr = new int[capacity];
    }
    ~Array_insertion()
    {
        delete[] arr;
    }

    int IndexInsertion(int size, int element, int index)
    {
        // Code for Insertion
        if (size >= capacity)
        {
            return -1;
        }
        for (int i = size - 1; i >= index; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[index] = element;
        return 1;
    }
    void initializeArray(int *initialArr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = initialArr[i];
        }
    }
    void Display(int size)
    {
        // Code for Traversal
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int initialArr[5] = {7, 8, 12, 27, 88};
    int size = 5;
    int element = 19;
    int index = 3;

    Array_insertion ArrOps(100);
    ArrOps.initializeArray(initialArr, size);

    ArrOps.Display(size);
    ArrOps.IndexInsertion(size, element, index);

    size += 1;
    ArrOps.Display(size);

    return 0;
}