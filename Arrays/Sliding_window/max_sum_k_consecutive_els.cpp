#include <iostream>
using namespace std;

/*
Given an array of ints and a number k, find maximum sum of k consecutive els in O(n) time

ip: arr[] = {1, 8, 30, -5, 20, 7}   k=3
op: 45 (30, -5, 20)

ip: arr[] = {5, -10, 6, 90, 3}  k=2
op: 96 (6, 90)

Approach : directly see the code
*/

int getKSum(int arr[], int n, int k)
{
    int curr_sum = 0;

    // calc sum of first window: O(k)
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];

    int ans = curr_sum;

    // calc sum of other window by adding next el and sub each el of prev window O(n-k)
    for (int i = k; i < n; i++)
    {
        // arr[i] = new window's last el
        // arr[i-k] = prev window's first el
        curr_sum = curr_sum + arr[i] - arr[i - k];

        ans = max(ans, curr_sum);
    }

    return ans;
}
