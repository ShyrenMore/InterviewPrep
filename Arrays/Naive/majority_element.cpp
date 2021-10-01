#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*
Problem Name: majority el in an array

Given an arr, find index of majority element if it exists. An element is a majority element if it occurs MORE THAN n/2 times in array

i.e if n=5, majority el should appear at least 3 times

ip: arr[] = {8, 3, 4, 8, 8}
op: 0 or 3 or 4 (any idx of 8)

ip: arr[] = {3, 7, 4, 7, 7, 5}
op: -1 (no majority, 7 appear 3 times viz = n/2)

ip: arr[] = {20, 30, 40, 50, 50, 50, 50}
op: 3 or 4 or 5 or 6 (index of 50)

Approach: traverse the array, for every element count how many times it appears in the array, if count > n/2 return index else if whole array is traversed return -1

Time: O(n^2)
*/

int findMajority(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr[i] == arr[j])
                ++count;
        }
        
        if(n/2 < count)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findMajority(arr, n);

    return 0;
}