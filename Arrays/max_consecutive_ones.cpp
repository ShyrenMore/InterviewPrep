#include <iostream>
using namespace std;

/*

Given a binary array, count max consecutive ones

ip: arr[] = {0, 1, 1, 0, 1, 0}
op: 2 (index 1 and 2)

ip: arr[] = {1, 1, 1, 1, 1, 1}
op: 6 (all indices)

ip: arr[] = {0, 0, 0, 0}
op: 0

ip: arr[] = {1, 0, 1, 1, 1, 1, 0, 1, 1}
op: 4 (index: 2-5)


Approach: Traverse every element, count consecutive ones begining with the element, 
Whenver the element is 0, reset the current count
if el is 1, increment current count and compare it with res
if(curr_count > res) => update result with curr_count
Time: O(n)
Space: O(1)
*/

int countConsecutiveOnes(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        while(arr[i] == 1)
        {
            ++count;
            ++i;
        }
        res = max(res, count);
    }
    return res;
}

/*
Dry run:
arr[] = {0, 1, 1, 0, 1, 1, 1}

initially, res = 0, curr = 0

i=0, curr=0
i=1, curr=1, res=1
i=2, curr=2, res=2
i=3, curr=0, 
i=4, curr=1
i=5, curr=2
i=6, curr=3, res=3
*/