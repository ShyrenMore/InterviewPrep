#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given array, find maximum sum of subarray 

note that a single element is also a subarray

ip: arr[] = {2, 3, -8, 7, -1, 2, 3}
op: 11 (7 + -1 + 2 + 3)

ip: arr[] = {5, 8, 3}
op: 16

ip: arr[] = {-6, -1, -8}
op: -1 

Approach: Traverse through all subarrays and for each sub-array find the sum of it, we will call it current_sum

if current_sum is greater than maximum sum that we have found so far, we will update maximum_sum with current_sum

Time: O(n^2)
*/

int maxSum(int arr[], int n)
{
    int res = arr[0];

    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;

        // finding sum of all sub-arrays that begin with arr[i]
        for (int j = i; j < n; j++)
        {
            curr_sum = curr_sum + arr[j];
            res = max(res, curr_sum);
        }
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
    cout << maxSum(arr, n);

    return 0;
}