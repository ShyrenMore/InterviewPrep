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

class MyQueue{

private:
    int *arr;
    int size;
    int cap;
public:
    MyQueue(int n)
    {
        cap = n;
        size = 0;
        arr = new int[cap];
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
        if(isFull())
        {
            cout << "\nQueue full!";
            return;
        }

        arr[size] = x;
        size++;
    }

    // O(n) time, since front is at index 0
    void dequeue()
    {
        if(isEmpty())
        {
            cout << "\nQueue empty!";
            return;
        }

        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];

        --size;
    }

};