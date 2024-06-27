#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void linkedlistTravarsal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *forth;

    // Allocate memory using new operator
    head = new Node();
    second = new Node();
    third = new Node();
    forth = new Node();

    // Link first and second nodes
    head->data = 7;
    head->next = second;

    // Link second and third nodes
    second->data = 11;
    second->next = third;

    // Link third and fourth nodes
    third->data = 45;
    third->next = forth;

    // Terminate the list at the third node
    forth->data = 67;
    forth->next = NULL;

    linkedlistTravarsal(head);
    
    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete forth;
    return 0;
}