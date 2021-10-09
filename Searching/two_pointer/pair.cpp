#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given an unsorted arr and a number x, we need to find if there is a pair in array with sum == x

ip: arr[] = {3, 5, 9, 2, 8, 10, 11} x = 17
op: Yes (pair of 9, 8)

ip: arr[] = {8, 4, 6} x=11
op: No

Naive: Run two loops, we fix a element and see if any of remaining elements adds up to x 
O(n^2)

Through hashing we can optimise above sol to O(n)
Hashing is DS which allows search, insert and delete in O(1) time

Efficient: have two ptrs
time: O(n/2)

Suppose the array was sorted 
ip: arr[] = {2, 5, 8, 12, 30} x = 17
op: Yes (pair of 5, 12)

ip: arr[] = {3, 8, 13, 18} x = 14
op: No

*/

bool two_ptr(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        if(arr[low]+arr[high] == x)
            return true;

        ++low;
        --high;
    }
    return false;
}

int main()
{
    int n, arr[100], x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << two_ptr(arr, n, x);
    return 0;
}