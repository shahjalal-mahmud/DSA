#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int *arr;
    int size;

public:
    // Constructor to initialize the array and its size
    BinarySearch(int arr[], int size)
    {
        this->arr = arr;
        this->size = size;
    }


    // Methof to perform Binary Search
    int Search(int element) const
    {
        int low = 0;
        int high = size - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == element)
            {
                return mid;
            }
            if (arr[mid] <= element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 123;

    // Creating an object of BinarySearch class
    BinarySearch Ls(arr, size);

    // Performing Binary search

    int binarySearchIndex = Ls.Search(element);
    cout<<"Binary search: "<<endl;
    if (binarySearchIndex != -1)
    {
        cout << "The element " << element << " was found at index " << binarySearchIndex << endl;
    }
    else
    {
        cout << "The element " << element << " was not found in the array" << endl;
    }

    return 0;
}