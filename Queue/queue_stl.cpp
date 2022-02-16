#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << q.front() << " " << q.back() << "\n";
    q.pop();
    cout << q.front() << " " << q.back() << "\n";
    
    // traversing queue
    while(!q.empty())
    {
        cout << q.front() << " " << q.back() << "\n";
        q.pop();
    }
    return 0;

}

/*
op
10 30
20 30
*/