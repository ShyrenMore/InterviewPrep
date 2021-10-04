#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given a sorted arr, find whether an element is present or not

if there are multple occurences, return any index, 
if there is no such element, return -1

ip: arr[] = {10, 20, 30, 40, 50, 60} x=20
op: 1

ip: arr[] = {10, 15} x=20
op: -1

Naive sol: linear search O(n)

Binary search algo:

find midpt = Floor((low+high)/2), 0-based indexing
compare arr[mid] with x
    - case 1: x == arr[mid]
        return index        
    - case 2: x < arr[mid]
        - do binary search on indices 0 to mid-1
    - case 3: x > arr[mid]
        - do binary search on indices mid+1 to n-1
*/

int binSearch_itr(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

/*

dry run for recursive solution
1) arr = [10, 20, 30, 40, 50, 60, 70] x = 20

binSearch_recur(arr, 0, 6, 20)
|
| -> mid = 3
| -> arr[mid] = arr[3] = 40 > 20
| -> binSearch_recur(arr, 0, 2, 20)
    | -> mid = (0+2)/2 = 1
    | -> arr[mid] == x, return mid

2) arr = [10, 20, 30, 40, 50, 60, 70] x = 25

Aux space: O(log n)

*/


int binSearch_recur(int arr[], int low, int high, int x)
{
    // base case
    if(high < low)
        return -1;

    int mid = (low + high) / 2;
    if(arr[mid]==x)
        return mid;
    else if(arr[mid] > x)
        return binSearch_recur(arr, low, mid - 1, x);
    else
        return binSearch_recur(arr, mid+1, high, x);
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
    // cout << getMaxSum(arr, n);

    return 0;
}

/*

CONCLUSION: which is better for binary search, recursion or iterative?
ans: iterative since we dont need extra auxilary space. 
In recursion we require extra O(log n) aux space since it involves function call overhead

Time for both approaches is same:
-> for successful search (el is present) = O(logn)
-> for unsuccessful search (el is absent) = Theta(logn)
*/