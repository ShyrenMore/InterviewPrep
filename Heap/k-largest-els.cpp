/*
Given a number k and unsorted arr
print k largest elements

arr = [5, 15, 10, 20, 8] k=2
op: 15 20

arr = [8, 6, 4, 10, 9] k=3
op: 8 9 10

Naive: sort -_-, O(nlogn + k)

Efficient:
use max-heap DS
build max-heap of all items and take out k-items
O(n) time for building max-heap
popping k items will take O(klogn)
overall: O(n + klogn)

Much more efficient:
use min-heap DS
The idea at any instant, min-heap will contain K-largest element seen so far

- build min-heap of first k items of array
- start traversing k+1th element
    - compare curr_el with top of heap
    - if top is greater than curr_el
        then ignore
      else pop top and insert curr element
- print contents of min-heap

Dry run
arr = [5, 15, 10, 20, 8, 25, 18]    k=3
exp op: 18, 20, 25

put first k els in min-heap
        5
       /  \
      15   10

i=3, arr[i] = 20
is top>arr[i]
5 !> 20
pop top & insert 20
        10
       /  \
      15   20

arr[i] = 8
10 > 8
ignore

arr[i] = 25
10 !> 25
pop(10) and insert 25
        15
       /  \
      20   25

arr[i] = 18
15 !> 18
pop(15) and insert 18

        18
       /  \
      20   25

pop out all els: 18, 20, 25

Time: 
Building min-heap: O(k)
We traverse n-k elements and pop elements
popping takes logK time
so loop overall takes O((n-k)* logK)

Overall: O(k + nlogK - KlogK)
if k<<<n
O(n)
but if k=n-1 or n-2
It still ends up as constant
so Best sol

The space will be O(k)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findKthLargestElements(vector<int> &arr, int k)
    {
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < k; i++)
            min_heap.push(arr[i]);

        for (int i = k; i < arr.size(); i++)
        {
            int top = min_heap.top();
            if(top < arr[i])
            {
                min_heap.pop();
                min_heap.push(arr[i]);
            }
        }

        vector<int> ans;
        while (!min_heap.empty())
        {
            ans.push_back(min_heap.top());
            min_heap.pop();
        }
        return ans;
    }
};

