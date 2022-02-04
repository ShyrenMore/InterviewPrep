#include <iostream>
using namespace std;

/*
We are given an array, 
we need to implement two stacks in it
Reason: cache friendliness

Naive Approach: 
Simply divide the array into two parts 
assign half of the array to both the stacks
the problem with this is it can lead to wastage of memory 
i.e suppose stack1 is full, and stack2 is empty, you still
won't be able to push in stack1

Efficient Approach:
the division will be dynamic, for implementing we will have
two pointers top1 = -1, and top2=n
when I push an item in st1, I will increment top1 ptr
similarly for a push in st2, I will decrement top2 ptr
If they cross each other, stack is overflowing

All operations are O(1)
*/

class TwoStacks{
private:
    int *arr;
    int top1;
    int top2;
    int cap;
public:
    TwoStacks(int n)
    {
        cap = n;
        top1 = -1;
        top2 = cap;
        arr = new int[n];
    }

    void push1(int x)
    {
        if(top1 < top2-1)
        {
            ++top1;
            arr[top1] = x;
        }
    }

    void push2(int x)
    {
        if(top1 < top2-1)
        {
            --top2;
            arr[top2] = x;
        }
        else
            cout << "\nOverflow!";
    }

    int pop1()
    {
        if(top1>=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else
            cout << "\nUnderflow!";
    }
    int pop2()
    {
        if(top2<cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else
            cout << "\nUnderflow!";
    }
};