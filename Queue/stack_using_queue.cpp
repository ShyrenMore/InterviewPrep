/*
Consider a situation where we have library available for queue
and we need stack library
How do we implement the stack

We use two queues q1 and q2
whenever we push an item, it will go into q1 only
so top(), size(), pop() operations will be done using q1
we need to push in q1 in O(1) time

eg: q1 = {10, 5, 15}, q2={}
in q1 rear is 15, front is 10
push(20)
we should get q1 = {20, 10, 5, 15}
instead of q1 = {10, 5, 15, 20}

to do this, we put all els of q1 in q2
q1 = {}, q2 = {10, 5, 15}

now push the new item in q1
q1 = {20}, q2 = {10, 5, 15}

move everything back to q1

q1 = {20, 10, 5, 15} q2={}

top, size, pop are O(1)
only push is O(n)
you can modify the code where other operations are costly instead of push
*/

#include <iostream>
#include <queue>
using namespace std;

class Stack{
public:
    queue<int> q1, q2;
    
    int top()
    {
        return q1.front();
    }

    int size()
    {
        return q1.size();
    }

    int pop()
    {
        return q1.front();
    }

    void push(int x)
    {
        // copy q1 to q2
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // push new item in empty q1
        q1.push(x);

        // copy back to q1
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
};