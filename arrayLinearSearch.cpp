#include <iostream>
using namespace std;

class LinearSearch
{
private:
    int *arr;
    int size;

public:
    // Constructor to initialize the array and its size
    LinearSearch(int arr[], int size)
    {
        this->arr = arr;
        this->size = size;
    }

    // Method to perform linear search
    int linearSearch(int element) const
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 444;

    // Creating an object of LinearSearch class
    LinearSearch ls(arr, size);

    // Performing linear search
    int linearSearchIndex = ls.linearSearch(element);
    cout<<"Linear Search: "<<endl;

    // Printing the results
    if (linearSearchIndex != -1)
    {
        cout << "The element " << element << " was found at index " << linearSearchIndex << endl;
    }
    else
    {
        cout << "The element " << element << " was not found in the array" << endl;
    }

    return 0;
}
