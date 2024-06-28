#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};
void linkedListTravarsal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
// Case 1-> Insertion at first index
Node *insert_at_first(Node *head, int data)
{
    Node *ptr = new Node(data);
    ptr->next = head;
    return ptr;
}
// CAse 2 -> Insertion at any middle of the index
Node *insert_at_index(Node *head, int data, int index)
{
    Node *ptr = new Node(data);
    Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Case 3 -> Insertion at the End
Node *insert_at_End(Node *head, int data)
{
    Node *ptr = new Node(data);
    Node *p = head;

    while (p->next != nullptr)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = nullptr;
    return head;
}
// Case 4 -> Insertion at Node
Node *insert_at_Node(Node *head, Node *prevNode, int data)
{
    Node *ptr = new Node(data);
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main()
{
    Node *head = new Node(7);
    Node *second = new Node(14);
    Node *third = new Node(21);
    Node *forth = new Node(28);

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = nullptr;
    cout << "linked list before insertion: " << endl;
    linkedListTravarsal(head);

    cout << "After inserting at the first index: " << endl;
    head = insert_at_first(head, 0);
    linkedListTravarsal(head);

    cout << "After inserting at index: " << endl;
    head = insert_at_index(head, 8, 2);
    linkedListTravarsal(head);

    cout << "After inserting at End: " << endl;
    head = insert_at_End(head, 35);
    linkedListTravarsal(head);

    cout << "After inserting at Node: " << endl;
    head = insert_at_Node(head, third, 16);
    linkedListTravarsal(head);

    return 0;
}