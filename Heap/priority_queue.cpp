#include <iostream>
#include <queue>
using namespace std;

/*
In c++, by default 
priority queue is max-heap
*/

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);

    /*
        15
       /  \ 
      10   5
    */

    cout << "Size :: " << pq.size()<<'\n';      // 3
    cout << "Top :: " << pq.top()<<'\n';        // 15

    // printing entire heap
    while(!pq.empty())
    {
        cout << pq.top() << " ";    // curr_max
        pq.pop();
    }
    return 0;
}