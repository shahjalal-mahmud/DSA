#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void linkedList_Traversal(Node *ptr)
{
    while (ptr != nullptr)
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

// Case 1 -> Deletion at first
Node *deletion_at_first(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *ptr = head;
    head = head->next;
    delete ptr;
    return head;
}

// Case 2 -> Deletion in between
Node *deletion_at_index(Node *head, int index)
{
    if (head == nullptr || index == 0)
        return deletion_at_first(head);

    Node *p = head;
    Node *q = head->next;
    for (int i = 0; i < index - 1 && q != nullptr; i++)
    {
        p = p->next;
        q = q->next;
    }

    if (q != nullptr)
    {
        p->next = q->next;
        delete q;
    }
    return head;
}

// Case 3 -> Deletion at End
Node *deletion_at_end(Node *head)
{
    Node *p = head;
    Node *q = head->next;
    while (q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    p->next = nullptr;
    delete q;
    return head;
}

// Case 4 -> Deletion at the given value
Node *deletion_at_given(Node *head, int value)
{
    Node *p = head;
    Node *q = head->next;
    while (q->data != value && q->next != nullptr)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        delete q;
        return head;
    }
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
    six->next = nullptr;

    cout << "Before deletion: " << endl;
    linkedList_Traversal(head);

    cout << "After deletion (Case-1): " << endl; // Deletion the first element
    head = deletion_at_first(head);
    linkedList_Traversal(head);

    cout << "After deletion (Case-2): " << endl; // Deletion at the indext element
    head = deletion_at_index(head, 2);
    linkedList_Traversal(head);

    cout << "After deletion (Case-3): " << endl; // Deletion the end element
    head = deletion_at_end(head);
    linkedList_Traversal(head);

    cout << "After deletion (Case-4): " << endl; // Deletion the given value
    head = deletion_at_given(head, 30);
    linkedList_Traversal(head);

    return 0;
}
