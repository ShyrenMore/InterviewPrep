/*
Given an array of positive ints
we need to find length of the longest subarray
that has alternating even-odd elements

ip: arr[] = {10, 12, 14, 7, 8}
op: 3 (14, 7, 8)

ip: arr[] = {7, 10, 13, 14}
op: 4 (all alternate)

ip: arr[] = {10, 12, 8, 4}
op: 1 (all even)

Naive sol O(N^2):
traverse through all elements
for every element find longest alternating subarray
that begins with this element 
if the len is greater than res we have found so far, 
we update res variable

Efficient solution:
O(n) solution
start traversing from second el
there are two cases:
1) begin a new subarr
2) extend prev subarr
we extend the subarr, 
if curr_el is alternating with prev element  
else begin a new subarray
*/

#include <iostream>
using namespace std;

int maxEvenOdd(int arr[], int n)
{
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        int curr_len = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (((arr[j] & 1) && !(arr[j - 1] & 1)) || !(arr[j] & 1) && (arr[j - 1] & 1))
                ++curr_len;
            else
                break;
        }

        res = max(curr_len, res);
    }

    return res;
}

int maxEvenOdd_eff(int arr[], int n)
{
    int res = 1, curr_len = 1;
    for (int i = 1; i < n; i++)
    {
        if (((arr[i] & 1) && !(arr[i - 1] & 1)) || !(arr[i] & 1) && (arr[i - 1] & 1))
        {
            ++curr_len;
            res = max(res, curr_len);
        }
        else
            curr_len = 1;
    }

    return res;
}

/*
Dry run for eff approach

arr[] = {5, 10, 20, 6, 3, 8}

initially, curr=res=1
i=1: curr=2, res=2
i=2: curr=1, res=2
i=3: curr=1, res=2
i=4: curr=2, res=2
i=5: curr=3, res=3
*/

int main()
{
    int arr[] = {10, 12, 14, 7, 8};
    // cout << maxEvenOdd(arr, 5);
    cout << maxEvenOdd_eff(arr, 5);
}

/*
op: 3
*/