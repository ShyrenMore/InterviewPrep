/*
Given an array of n elements, where each element is at most k away from its target position
i.e for any arr[i] present between i-k and i+k in sorted array
or you can say The array is somewhat sorted

Sort the array

arr[] = {9, 8, 7, 18, 19, 17}  and k=2
op: arr[] = {7, 8, 9, 17, 18, 19}

Naive: sort function -_-, O(nlogn)

Eff:
use min-heap, since we want arr in increasing order
Maintain two things:
- idx: where to put an el in sorted arr
- min_heap: gives next element to be placed

i.e at idx:0 it can be present between indices 0 to k
So create min-heap of first k+1 elements and insert elements from 0 to k
set index=0 initially

run a loop from k+1 to n-1
    put top of the heap in the index
    pop the top, increment index
    and
    add curr item into heap to maintain k els

since top of heap will give us next el and index var will give index to be placed


Finally pop remaining els and place them in index

dry run:
arr[] = {9, 8, 7, 19, 18} index = 2

1) create heap of size k+1 and push first k els

        7
       /  \
      8    9

index = 0

2) run loop from 3 to 4

put 7 in arr[index] i.e now arr[0] = 7
update index = 1
pop 7 and push 19 in heap

        8
       /  \
      9    19

index = 1

put 8 in arr[index] i.e arr[1] = 8
update index = 2
pop 8 and push 18 into heap

        9
       /  \
      18   19

index = 2
arr condition rn: [7, 8, 7, 19, 18]

since arr traversal is over
pop rem elements from pq
arr[2] = 9, index = 3
pop 9
        18
       /  
      19   

arr[3] = 18., index = 4
pop 18

arr[4] = 19, index = 5
pop(19)

END
arr = [7, 8, 9, 18, 19]

Time: 
- O(klogk) to add k+1 items in min_heap
- runs a loop for n-k-1 items and we do logK work i.e taking and putting an item
- at last emptying min_heap of size k is also  k*logk
hence klogk + nlogk - klogk + klogk
= O(nlogK)
*/

#include <bits/stdc++.h>
using namespace std;

void sortK(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i <= k; i++)
        min_heap.push(arr[i]);

    int index = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[index] = min_heap.top();
        index++;
        min_heap.pop();
        min_heap.push(arr[i]);
    }

    while(!min_heap.empty())
    {
        arr[index] = min_heap.top();
        index++;
        min_heap.pop();
    }

}
