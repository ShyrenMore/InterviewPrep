/*
link: https://leetcode.com/problems/merge-k-sorted-lists/

given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge them and return a big sorted LL

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Approach:
Store first nodes of all K linked list in min-heap
Now min_heap will give me the minimum element among all K linked list

eg:
[
  1->3->5->8,
  2->6->7,
  3->5
]

Min-heap:
        1
       /  \
      2    3

Now pop 3 append it to ans list and push the next element after 1 i.e 3 in heap
New list = [1]

        2
       /  \
      3    3

pop 2 and push next element after 2 i.e 6 in heap
        3
       /  \
      3    6
new list = [1, 2]

pop top i.e 3 from heap ans push 5
        3
       /  \
      5    6
new list = [1, 2, 3]
Do the same till heap is empty

General algo:
- Initially push first nodes i.e minimum elements of all K list in min_heap
- Keep doing the foll operation till heap is empty
    - pop the top and insert it in ans list
    - push the next node in that particular list where popped node belonged

Time complexity : O(kN)
Space: O(1)?
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(){
        val = 0;
        next = NULL;
    }  
    ListNode(int x) {
        val = x;
        next = NULL;
    }  
    ListNode(int x, ListNode *next) {
        val = x;
        next = next;
    }
};

// we can't use greater<int> while defining min_heap since pq stores nodes and not integers
struct heapCmp
{
    bool operator()(ListNode* a, ListNode* b){
        if (a->val > b->val)
            return true;
        return false;
    }
};
class Solution
{
public:

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, heapCmp> min_heap;
        ListNode *head = NULL;
        ListNode *curr = NULL;
        for(ListNode* node: lists)
        {
            if(node)
                min_heap.push(node);
        }

        while(!min_heap.empty())
        {
            ListNode *top = min_heap.top();
            min_heap.pop();
            if(head  == NULL)
            {
                head = curr = top;
            }
            else 
            {
                curr->next = top;
                curr = curr->next;
            }

            if(top->next != NULL)
                min_heap.push(top->next);
            
        }

        return head;
    }

    
};