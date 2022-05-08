#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*
Given an arr of int, find len of longest subsequence that has consecutive integers 
NOTE: the nos can appear in any order

ip: arr = [1, 9, 3, 4, 2, 20]
op: 4 (1, 3, 2, 4)

ip: arr = [8, 20, 7, 30]
op: 2 (8, 7)

ip: arr = [20, 30, 40]
op: 1 (no continous elements)
*/

/*
sol1: O(nlogn) time and O(1) space
sort the array
now check the array if the elemnts are getting incremented by one
there can be many sequences of contigous elements, so maintain maximum of len
*/

int maxLenSubsequence(int arr[], int n)
{
    sort(arr, arr + n);
    int res = 1;
    for (int i = 0; i < n-1; i++)
    {
        int curr_len = 1;
        while(arr[i] == arr[i+1] - 1)
        {
            ++curr_len;
            i++;
        }
        res = max(res, curr_len);
    }

    return res; 
}
/*
sol2: O(2n) ~ O(n) time and space
create hashtable and insert all elements 
Now traverse the array and check if it is a starting point for consecutive subsequence 
We do this by looking arr[i]-1 in hashtable 
if it is absent then consider arr[i] as starting point of subsequence
While we keep finding continous nos, keep updating the curr_len
At the end compare curr_len with result
*/

int maxLenSubsequence_hashing(int arr[], int n)
{
    int res = 1;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
        s.insert(arr[i]);

    for (int i = 0; i < n; i++)
    {
        if(s.find(arr[i]-1) == s.end())
        {
            int curr_len = 1;
            while (s.find(arr[i] + curr_len) != s.end())
                ++curr_len;
            res = max(res, curr_len);
        }
    }

    return res;
}

int main()
{
    int arr[] = {1, 9, 3, 4, 2, 20};
    int n = 6;
    cout << maxLenSubsequence_hashing(arr, n);
}