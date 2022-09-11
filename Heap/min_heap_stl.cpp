#include <iostream>
#include <queue>
using namespace std;

/*
min-heap: root will be smallest el
priority queues are DS that uses Heap as concept but are built on top of vectors 
*/

int main()
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    min_heap.push(10);
    min_heap.push(15);
    min_heap.push(5);

    /*
        5
       /  \
      15   10
    */

    cout << "Size :: " << min_heap.size() << '\n'; // 3
    cout << "Top :: " << min_heap.top() << '\n';   // 5

    // printing entire heap
    while (!min_heap.empty())
    {
        cout << min_heap.top() << " "; // curr_max
        min_heap.pop();
    }
    return 0;
}