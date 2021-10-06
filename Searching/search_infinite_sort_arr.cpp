#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Algo name: Unbounded binary search

given infinite size sorted arr, write a func to return idx if element is present, else return -1

ip: arr[] = {1, 10, 15, 20, 40, 80, 90, 100, 120, 500}, x=100
op: 7

ip: arr[] = {20, 40, 100, 300,...} x = 50
op: -1

in online environment, you will be given n as 10^9

Naive: Theta(position), even if el is absent 
Linear searh: 
two cases:
    - el found, return idx
    - el is > x, return -1

Efficient: Theta(log(position))
begin index 1, 2, 4, 8, ... until curr_el < x
stop at curr_el >= x, here we have to handle zero idx seperately

arr[] = {1, 10, 15, 20, 40, 60, 80, 100, 200, 500, 1000....} x = 100

arr[0] != x

i=1, 2, 4, 8

arr[8] > x
so we know know the el must be present b/w  index 0 to 8
specifically from index 4 to 8 i.e b/w 5 to 7, and do bin search for indexes 4, 8

Time: ~ O(2*position) for finding indexes
O(2*logn) for search 
*/

int naive(int arr[], int x)
{
    int i = 0;
    while(true)
    {
        if(arr[i] == x)
            return i;
        
        if(arr[i] > x)
            return -1;

        ++i;
    }
}

int binarySearch(int arr[], int x, int low, int high)
{
    while(low <=high)
    {
        int mid = (low + high) / 2;
        if(arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int efficient(int arr[], int x)
{
    if(arr[0] == x)
        return 0;

    int i = 1;
    while(arr[i] < x)
        i *= 2;
    
    if(arr[i] == x)
        return i;

    return binarySearch(arr, x, i / 2 + 1, i-1);
}

int main()
{
    int n, arr[100], x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // cout << sq_root_naive(x);
    cout << efficient(arr, x);
    return 0;
}
