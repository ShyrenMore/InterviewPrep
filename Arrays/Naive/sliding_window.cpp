#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Technique name: sliding window technique

Given an array of integers and number K, find the maximum sum of K consecutive elements 

ip: arr[] = {1, 8, 30, -5, 20, 7} & K=3
op: 45

ip: arr[] = {5, -10, 6, 90, 3} & K=2
op: 96

Approach: Slide a window lol
when sliding you will remove first el from left side and add first el from right side

Time: O(n)
*/

int getSum(int arr[], int n, int k)
{
    int curr_sum = 0;

    // computing for starting window, theta(K)
    for (int i = 0; i < k; i++)
        curr_sum += arr[i];

    int max_sum = curr_sum;
    
    // sliding the window, array traversed: n-k 
    for (int i = k; i < n; i++)
    {
        curr_sum += (arr[i] - arr[i - k]);
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main()
{
    int n;
    cin >> n;
    
    int k;
    cin >> k;
    
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << getSum(arr, n, k);

    return 0;
}