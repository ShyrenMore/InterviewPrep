#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*
Problem name: Maximum circular subarray sum

Given an arr, find maximum sum of circular sub array, 
a circular subarray contains elements from normal subarray and also the elements formed by connecting last el to first el 

eg: arr {10, 5, -5} has foll sub-arr
{10}, {5}, {-5}, {10, 5}, {5, -5}, {10, 5, -5},
{5, -5, 10}, {-5, 10}, {-5, 10, 5}

op: 15 == {10, 5}

ip: arr[] = {5, -2, 3, 4}
op: 12 (3, 4, 5)

ip: arr[] = {2, 3, -4}
op: 5 (2, 3)

ip: arr[] = {8, -4, 3, -5, 4}
op: 12 (4, 8)

ip: arr[] = {-3, 4, 6, -2}
op: 10 (4, 6)

ip: arr[] = {-8, 7, 6}
op: 13 (7, 6)

ip: arr[] = {3, -4, 5, 6, -8, 7}
op: 17 (7, 3, -4, 5, 6)

Approach: consider every array el as beginning element, find maximum sum that you can obtain by considering this as beginning element 
so for every element there can be n-subarrays that begin with it 

Time: O(n^2)
*/

int getMaxSum(int arr[], int n)
{
    int res = arr[0];
    for (int i = 0; i < n; i++)
    {
        int curr_max = arr[i];
        int curr_sum = arr[i];
        for (int j = 1; j < n; j++)
        {
            int idx = (i + j) % n;
            curr_sum += arr[idx];
            curr_max = max(curr_max, curr_sum);
        }
        res = max(res, curr_max);
    }
    return res;
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
    cout << getMaxSum(arr, n);

    return 0;
}