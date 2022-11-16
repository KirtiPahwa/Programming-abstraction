#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void traverseLinkedList(Node *head)
{

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtStart(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        return;
    }
    node->next = head;
    head = node;
}
void insertAtTail(Node *&head, int ele)
{
    Node *node = new Node(ele);
    if (!head)
    {
        head = node;
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = node;
}
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == key)
        {
            cout << "Key found in the Linked List" << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Key not found in the Linked List" << endl;
    return false;
}
void insertInBetween(Node *&head, int index, int data)
{
    Node *temp = head;
    int i = 1;
    if (index == 1)
    {
        insertAtStart(head, data);
    }
    else
    {
        Node *node = new Node(data);

        while (temp)
        {
            if (i == index - 1)
            {
                node->next = temp->next;
                temp->next = node;
            }
            i++;
            temp = temp->next;
        }
    }
}
void deleteNode(Node *&head, int key)
{
    Node *temp = head;
    Node *nodeToDelete = NULL;
    if (temp && temp->data == key)
    {
        nodeToDelete = temp;
        head = temp->next;
    }
    else
    {
        while (temp)
        {
            if (temp->next && temp->next->data == key)
            {
                nodeToDelete = temp->next;
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
    }
    delete nodeToDelete;
}
void rearrangeTheList(Node *head)
{
    if (!head || !head->next)
    {
        return;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *oddStart = odd;
    Node *evenStart = even;
    int count = 0;
    while (odd->next && even->next)
    {
        if (count % 2 == 0)
        {
            odd->next = even->next;
            odd = odd->next;
        }
        else
        {
            even->next = odd->next;
            even = even->next;
        }
        count++;
    }
    odd->next = NULL;
    even->next = NULL;
    cout << "Odd :";
    traverseLinkedList(oddStart);
    cout << "Even:";
    traverseLinkedList(evenStart);
}

int main()
{
    Node *head = new Node(50);
    int n;
    // cout << "Enter the size of the linked list" << endl;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        insertAtTail(head, a);
    }

    rearrangeTheList(head);

    return 0;
}