#include <iostream>
using namespace std;

/*
Given an array of integers, find max(arr[j] - arr[i]) such that j>i

ip: arr[] = {2, 3, 10, 6, 4, 8, 1}
op: 8

ip: arr[] = {7, 9, 5, 6, 3, 2}
op: 2

ip: arr[] = {30, 10, 8, 2}
op: -2

ip: arr[] = {10, 20, 30}
op: 20

Naive Approach:
initialise res as diff b/w first pair i.e arr[1]-arr[0]
Now we consider every pair for each element
we find diff and
if diff > curr_res, we update res
Time: O(n^2)

Efficient solution:
Traverse array from left to right
Keep track of minimum element that we have seen so far
For every element, subtract minimum element from it
and we see if the res > curr_ res, we update the res

Time: Theta(n)

eg: arr = [2, 3, 10, 6, 4, 8, 1]

initially,
res = arr[1] - arr[0] = 1
minVal = arr[0] = 2

j=1:
res = max(1, arr[1]-minVal) = (1, 3-2) = 1
minVal = min(2, arr[1]) = min(2, 3) = 2

j=2:
res = max(1, arr[1]-minVal) = (1, 3-2) = 1
*/

int maxDiff_naive(int arr[], int n)
{
    int res = arr[1] - arr[0];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            res = max(res, arr[j] - arr[i]);

    return res;
}

int maxDiff_eff(int arr[], int n)
{
    int minVal = arr[0], res = arr[1]-arr[0];
    for (int i = 1; i < n; i++)
    {
        res = max(res, arr[i] - res);
        if(minVal > arr[i])
            minVal = arr[i];
    }
    return res;
}

int main()
{
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    cout << maxDiff_eff(arr, 7);
}