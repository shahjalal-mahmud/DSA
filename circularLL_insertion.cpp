#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

Node *linkedList_Traversal(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

// Case 1 -> Insertion at first in circular Linked list
Node *insertion_at_first(Node *head, int data)
{
    Node *p = new Node(data);
    Node *q = head->next;
    while (q->next != head)
    {
        q = q->next;
    }
    q->next = p;
    p->next = head;
    head = p;
    return head;
}
// Case 2 -> Insertion at index in circular linked list
Node *insertion_at_index(Node *head, int data, int index)
{
    Node *newNode = new Node(data);
    Node *p = head;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

// Case 3 -> Insertion at the last index in circular linked list
Node *insertion_at_end(Node *head, int data)
{
    Node *newNode = new Node(data);
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = newNode;
    newNode->next = head;
    return head;
}

// Case 4 -> Insertion after a given value in circular linked list
Node *insertion_at_given(Node *head, int value, int data)
{
    Node *newNode = new Node(data);
    Node *p = head;
    do
    {
        if (p->data == value)
        {
            newNode->next = p->next;
            p->next = newNode;
            return head;
        }
        p = p->next;
    } while (p != head);
    cout << "Value " << value << " not found in the list." << endl;
    return head;
}
int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(40);
    Node *five = new Node(50);
    Node *six = new Node(60);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = five;
    five->next = six;
    six->next = head;

    cout << "Circular linked list before insertion: " << endl;
    linkedList_Traversal(head);

    cout << "\nCircular Linked List After Insertion at first: " << endl;
    head = insertion_at_first(head, 5);
    linkedList_Traversal(head);

    cout << "\nCircular Linked List After Insertion at index 3: " << endl;
    head = insertion_at_index(head, 25, 3);
    linkedList_Traversal(head);

    cout << "\nCircular Linked List After Insertion at end: " << endl;
    head = insertion_at_end(head, 70);
    linkedList_Traversal(head);

    cout << "\nCircular Linked List After Insertion after value 30: " << endl;
    head = insertion_at_given(head, 30, 35);
    linkedList_Traversal(head);
    return 0;
}