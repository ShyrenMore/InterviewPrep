#include <iostream>
using namespace std;

/*
testcases: 10 20 30 40
10
for NULL, op will be blank
*/

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printList(Node *head)
{
    Node *temp = head;
    if(head!=NULL)
        while(temp!=NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printList(head);
    return 0;
}