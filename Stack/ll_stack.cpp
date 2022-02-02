/*
Time complexity for
push 
pop
size
isEmpty
peek 
should be O(1)

hence it is preferred to insert/remove at head
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

struct MyStack
{
    Node *head;
    int sz;

    MyStack()
    {
        head = NULL;
        sz = 0;
    }

    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        ++sz;
    }

    int pop()
    {
        if(head == NULL)
        {
            cout << "\nUnderflow: you are popping from an empty stack";
            return INT8_MIN;
        }

        int res = head->data;

        Node *ref = head;
        head = head->next;
        delete (ref);
        --sz;
        return res;
    }

    int getSize()
    {
        return sz;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    int peek()
    {
        if (head == NULL)
        {
            cout << "\nUnderflow: you are popping from an empty stack";
            return INT8_MIN;
        }

        return head->data;
    }

    void printStack()
    {
        cout << "\nStack status :: \n";
        Node* curr = head;
        while(curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

        cout << "\n";
    }
};

int main()
{
    MyStack *stk = new MyStack();
    cout<<stk->pop();
    stk->push(10);
    stk->push(20);
    stk->push(30);
    cout << "\nSize :: " << stk->getSize();
    stk->printStack();

    return 0;
}

/*
op
Underflow: you are popping from an empty stack-128
Size :: 3
Stack status ::
30 20 10
*/