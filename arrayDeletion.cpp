#include <iostream>
using namespace std;

class ArrayOperation
{
private:
    int *arr;     // Pointer to the internal array
    int capacity; // Capacity of the internal array

public:
    // Constructor to initialize the array with a given capacity
    ArrayOperation(int cap) : capacity(cap)
    {
        arr = new int[capacity]; // Dynamically allocate memory for the array
    }

    // Destructor to release the allocated memory
    ~ArrayOperation()
    {
        delete[] arr;
    }

    // Method to display the elements of the array
    void Display(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Method to delete an element at a given index
    void IndDeletion(int size, int index)
    {
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }

    // Method to initialize the internal array with given initial values
    void InitializeArray(int *initialArr, int size)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = initialArr[i];
        }
    }
    int *getArray()
    {
        return arr;
    }
};

int main()
{
    // Initial values for the array
    int initialArr[5] = {7, 8, 12, 27, 88};
    int size = 5, index = 0;

    // Create an instance of ArrayOperations with a capacity of 100
    ArrayOperation arrayOps(100);

    // Initialize the internal array with the initial values
    arrayOps.InitializeArray(initialArr, size);

    // Display the array
    arrayOps.Display(size);

    // Delete the element at the specified index
    arrayOps.IndDeletion(size, index);
    size -= 1;

    // Display the array after deletion
    arrayOps.Display(size);

    return 0;
}