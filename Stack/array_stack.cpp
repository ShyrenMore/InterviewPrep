#include <iostream>
using namespace std;

class MyStack
{
    private:
        int *arr;
        int top;
        int cap;
    public:
        MyStack(int c)
        {
            top = -1;
            cap = c;
            arr = new int[cap];
        }

        void push(int x)
        {
            ++top;
            arr[top] = x;
        }

        int pop()
        {
            int res = arr[top];
            --top;
            return res;
        }

        int peek()
        {
            return arr[top];
        }

        int size()
        {
            return (top + 1);
        }

        bool isEmpty()
        {
            return (top == -1);
        }

        void printStack()
        {
            cout << "\nStack status :: \n";
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << "\n";
        }
};

int main()
{
    // creating a stack of size 5
    MyStack *sq = new MyStack(5);

    sq->push(5);
    sq->push(10);
    sq->push(20);
    sq->printStack();
    cout << "\n";
}