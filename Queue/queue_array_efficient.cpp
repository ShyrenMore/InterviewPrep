#include <iostream>
using namespace std;

/*
implement the foll func:
enqueue(val)
dequeue()
size()
getFront()
getRear()
isFull()
isEmpty()
*/

class MyQueue
{

private:
    int *arr;
    int size;
    int cap;
    int front;

public:
    MyQueue(int n)
    {
        cap = n;
        size = 0;
        front = 0;
        arr = new int[n];
    }

    bool isFull()
    {
        return (size == cap);
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    // O(1)
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "\nQueue full!";
            return;
        }
        int rear = getRear();
        rear = (rear + 1) % cap;
        arr[rear] = x;
        size++;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return (front + size - 1) % cap;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue empty!";
            return;
        }

        front = (front + 1) % cap;
        --size;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        return front;
    }
};