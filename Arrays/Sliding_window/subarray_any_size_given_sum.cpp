/*
Given an unsorted array of non-negative integers. Find if there is a subarray with given sum

ip: 
arr[] = {1, 4, 20, 3, 10, 5}    sum = 33
op: Yes (20, 3, 10)

ip:
arr[] = {1, 4, 0, 0, 3, 10, 5}  sum = 7
op: Yes (1, 4, 0, 0, 3)

ip: 
arr[] = {2, 4} sum =3 
op: No

Maintain a window of starting point of el
if window_sum < given sum
    then add more els in window 
we do this until window_sum > given sum
Now we remove elements from starting point of window ie i = 0, 1, 2..
until we get desired sum or reach the end of array

return (given_summ == curr_sum)

O(n) time & O(1) space

NOTE : this approach will not work if array has negative integers 
eg arr = [4, 7, -3, 1, 2]   sum = 9
wind = 4, 7 = 11
remove 4
wind = 7-3 = 4
and so on

but there was a subarray with sum 9:
4 7 -3 1 

You can solve this by using a combination of hashing and prefix-sum
*/

#include <iostream>
using namespace std;

bool hasValidSubarray(int n, int arr[], int sum)
{
    // initialise window with starting el
    int curr_sum = arr[0];

    // corner case for subarr of 1 el 
    if(curr_sum == sum)
        return true;

    int start_idx = 0;
    for(int end = 1; end < n; end++)
    {
        // if window_sum > given_sum at any iteration
        // then start removing els from beginning
        while(curr_sum > sum && start_idx < end-1)
        {
            curr_sum -= arr[start_idx];
            start_idx++;
        }

        if(curr_sum == sum)
            return true;

        if(end < n)
            curr_sum += arr[end];
    }

    return (curr_sum == sum);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << hasValidSubarray(n, arr, sum) << "\n";
    }
    return 0;
}

/*
ip:
3
6 33
1 4 20 3 10 5
7 7
1 4 0 0 3 10 5
2 3
2 4

op:
1
1
0

*/