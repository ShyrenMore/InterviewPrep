#include <iostream>
using namespace std;

/*

Given an array of both +ve and -ve nos, find maximum ssum of a subarray in this array

ip: arr[] = {2, 3, -8, 7, -1, 2, 3}
op: 11 (7-1+2+3)

ip: arr[] = {5, 8, 3}
op: 16 (5+8+3)

ip: arr[] = {-6, -1, -8}
op: -1 

Naive: 
Traverse through all subarrays
calculate sum for each subarr
if(curr_sum > ans)
    update ans to curr_sum

O(n^2) time
*/

int calcMaxSubArrSum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            res = max(res, curr);
        }
    }
    return res;
}

/*

Efficient sol:
traverse arr left to right 
find maximum sum of subarr that ends with curr element
and ans is going to be maximum of all the values 

maxEnding(idx) = max(maxEnding(idx-1) + arr[i], arr[i])

Time: O(n) Space: O(n)
*/

int calcMaxSubArrSum_eff(int arr[], int n)
{
    int res = arr[0];
    int maxEnding[n];
    maxEnding[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding[i] = max(maxEnding[i-1] + arr[i], arr[i]);
        res = max(res, maxEnding[i]);
    }

    cout << "\nMaxending array :: "
         << "\n";
    for(auto x: maxEnding)
        cout << x << " ";
    cout << "\n";
    return res;
}

int main()
{
    int arr[] = {2, 3, -8, 7, -1, 2, 3};
    cout << calcMaxSubArrSum_eff(arr, 7);
    return 0;
}

/*
op: 11
*/