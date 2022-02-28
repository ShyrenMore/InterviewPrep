#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/*

ip: q = {10, 5, 15, 20}, front=10, rear=20
op: q = {20, 15, 5, 10}, front=20, rear=10

Iterative sol:
Traverse the queue
Put every item of queue into stack
so when we pop items from stack,
and enqueue them back to queue they will be reversed 

Recursive sol:
If I am handling n-1 items
and there are total n items 
how do I handle nth item?
we can dequeue nth item from the queue
reverse the rest of queue recursively
and then I push the nth item back in queue  

eg: {12, 5, 15, 20}
front=12, rear=20

nth item = 12
dequeue nth item
q = {5, 15, 20}

reverse the rest
q = {20, 15, 5}

push the nth item back from rear end
q = {20, 15, 5, 12}
*/

void reverse_itr(queue<int> &q)
{
    stack<int> s;
    while(!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}


void reverse_rec(queue <int> &q)
{
    if(q.empty())
        return;

    int x = q.front();
    q.pop();

    reverse_rec(q);
    q.push(x);
}

int main()
{
    queue<int> q;
    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    cout << "Initial state of queue :: \n";
    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << "\n";

    q.push(12);
    q.push(5);
    q.push(15);
    q.push(20);

    reverse_rec(q);

    cout << "queue after reversal :: \n";
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << "\n";


    return 0;
}

/*
op:
Initial state of queue ::
12 5 15 20
queue after reversal ::
20 15 5 12
*/