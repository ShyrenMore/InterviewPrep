#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

/*
Given an array of +ve, -ve and 0s, and a sum
find length of longest subarray with given sum

ip: arr[] = {5, 8, -4, -4, 9, -2, 2}, sum = 0
op: 3 (8, -4, -4)
(-2, 2) also gives us given sum but of len=2 

ip: arr[] = {3, 1, 0, 1, 8, 2, 3, 6}, sum = 5
op: 4 (3, 1, 0, 1)
*/

/*
sol1: Time: O(n^2) and space: O(1)
traverse the array from left to right
consider each el as starting of subarray
and for every subarray, compute the sum and compare it with curr sum
If both are equal
then I will find the length by start and end indices and store it in res var
so will take max for each iteration
*/

int getMaxLen(int arr[], int n, int sum)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if(curr_sum == sum)
                res = max(res, j - i + 1);
        }
    }

    return res;
}

/*
sol2: 
compute prefix sums and store it in hashtable
if (prefix_sum-given_sum) already appeared
then subarray after that apperance till this point
is your given sum

eg: arr = [8, 3, 1] and sum=4
here prefixSum = [8, 11, 12]

so when we are at 12
prefixsum-givensum = 12 - 4 = 8
this means sum of elements from 11 to 12 is 4

extending the above array
arr = [8, 3, 1, 5, -6, 6, 2, 2] and sum=4
op is 4 since longest is (-6, 6, 2, 2)
prefixSum = [8, 11, 12, 17, 11, 17, 19, 21]
at 21,
prefixsum-givensum = 21 - 4 = 17
so prefix[11, 17, 19, 21] will have sum as 4

for keeping a track of lengths of different subarrays, we store prefixSum along with their index
for duplicate els, we store the earliest index i.e index of first occurence or leftmost index 
*/

int getMaxLen_hashing(int arr[], int n, int given_sum)
{
    unordered_map<int, int> m;
    int prefixSum = 0, len = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if(prefixSum == given_sum)
            len = i + 1;
        
        // store the first occurence
        if(m.find(prefixSum) == m.end())
            m.insert({prefixSum, i});

        if (m.find(prefixSum - given_sum) != m.end())
            len = max(len, i - m[prefixSum - given_sum]);
    }
    return len;
}

int main()
{
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = 8;
    int sum = 4;
    cout << getMaxLen(arr, n, sum) << "\n";
    cout << getMaxLen_hashing(arr, n, sum) << "\n";
    return 0;
}