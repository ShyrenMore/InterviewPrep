#include <iostream>
using namespace std;

/*

no isFull func here
size()
getFront()
getRear()
isEmpty()

In Queue we have two ends, front and rear
insertion happens at rear end
removal happens at front end
so head should be front end
and tail is rear end for
O(1) insertion and removal,
if two pointers are maintained

*/
class Node {
    public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
    public:
        Node *front, *rear;
        // int size;
        Queue()
        {
            front = NULL;
            rear = NULL;
            // size = 0;
        }

        void enqueue(int x)
        {
            Node *temp = new Node(x);
            // ++size
            // corner case: addn to empty list
            if(front == NULL)
            {
                front = rear = temp;
                return;
            }

            rear->next = temp;
            rear = temp;
        }

        void dequeue()
        {
            if(front == NULL)
                return;
            // --size
            Node *temp = front;
            front = front->next;

            // corner case: list has only one node
            if(front == NULL)
            {
                rear = NULL;
            }

            delete (temp);
        }

        void printQueue()
        {
            cout << "\nCurrent status report:\n";
            cout << "Front :: " << front->data << "\n";
            cout << "Rear :: " << rear->data << "\n";
            cout << "Queue::\n";
            Node *curr = front;
            while(curr!=NULL)
            {
                cout << curr->data << " ";
                curr = curr->next;
            }

            cout << "\n";
        }
};

int main()
{
    Queue *q = new Queue();
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->printQueue();
    q->dequeue();
    q->printQueue();
}

/*
op:
Current status report:
Front :: 10
Rear :: 30
Queue::
10 20 30

Current status report:
Front :: 20
Rear :: 30
Queue::
20 30
*/