/*
Given arr and int k
find if there is a subarray of size k with given sum

ip:
arr = [1, 8, 30, -5, 20, 7]
k = 3, sum = 45
op: True

compure window sum and keep on comparing with given sum
*/
#include <iostream>
using namespace std;

bool isValidSubarray(int arr[], int k, int sum, int n)
{
    int curr_sum = 0;
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];

    if(curr_sum == sum)
        return true;

    for (int i = k; i < n; i++) 
    {
        curr_sum = curr_sum + arr[i] - arr[i - k];
        if(curr_sum == sum)
            return true;
    }

    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while(t--)
    {
        int n, k, sum;
        cin >> n >> k >> sum;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << isValidSubarray(arr, k, sum, n)<<"\n";
    }
    return 0;

}

/*
ip:
3
6 3 45
1 8 30 -5 20 7
5 2 96
5 -10 6 90 3
5 2 96
5 -10 3 90 3

op:
1
1
0

*/