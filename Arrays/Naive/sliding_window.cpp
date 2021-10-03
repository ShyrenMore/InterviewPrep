#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Technique name: sliding window technique

Problem 1:

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

/*

Problem 2: Given an unsorted arr of non-negative integers. Find if there is a sub-array with given sum

ip: arr[] = {1, 4, 20, 3, 10, 5}, sum=33
op: Yes (20+3+10)

ip: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum=7
op: Yes

Approach: we find sum of window till it is < given_sum
once it becomes higher than given_sum, we keep removing beginning elements from window until is less than or equal to given sum 

since our window size changes according to certain conditions, we maintain two pointers called start and end representing start and end of the window 

we are considering every element from index 1 as end of window and simulataneously check for conditions 

This approach does not work for negative elements 
eg: arr[] = {4, 7, -3, 1, 2}    sum=9
we do have a subarr wuth sum 9 (4, 7, -3, 1)
but with this approach after getting 4+7, it will remove 4

Time: O(n)

*/

bool isSum(int arr[], int n, int given_sum)
{
    int curr_sum = arr[0], start = 0;
    for (int end = 1; end < n; end++)
    {
        // clean prev window 
        while(curr_sum > given_sum && start < end-1)
        {
            curr_sum -= arr[start];
            start++;
        }

        if(curr_sum == given_sum)
            return true;
        
        // expanding the window
        if(end < n)
            curr_sum += arr[end];
    }

    return (curr_sum == given_sum);
}


int main()
{
    int n;
    cin >> n;
    
    // int k;
    // cin >> k;
    
    int sum;
    cin >> sum;
    
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // cout << getSum(arr, n, k);
    cout << isSum(arr, n, sum);
    return 0;
}