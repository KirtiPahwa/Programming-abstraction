#include <iostream>
using namespace std;

template <class T>
class Stack
{
public:
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
    Node *head;
    int size;
    Stack()
    {
        head = NULL;
        size = 0;
    }
    void push(T ele)
    {
        try
        {

            Node *node = new Node(ele); // bad_alloc exception can be there on fullness of heap
            size++;
            if (head == NULL)
            {
                head = node;
                return;
            }
            node->next = head->next;
            cout<<node->next
            head = node;
        }
        catch (exception &e)
        {
            cout << "Stack overflow" << e.what() << endl; // bad_alloc exception
        }
    }
    T top()
    {
        if (isEmpty() == 1)
        {
            return -1;
        }
        cout << head->data << endl;
        return head->data;
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void pop()
    {
        cout << isEmpty() << endl;
        if (isEmpty() == 1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *tobedel = head;
        cout << head->next->data << endl;
        head = head->next;
        delete tobedel;
    }
};

int main()
{
    Stack<int> s;
    s.push(10);
    s.push(7);
    s.push(8);
    cout << s.top() << endl;
    // s.push(9);
    // s.pop();
    // cout << s.top() << endl;
    // // s.pop();
    s.push(4);

    return 0;
}