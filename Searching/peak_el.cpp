#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given an unsorted array, find peak element. A peak element is an el not smaller than it's neighbours

ip: arr[] = {5, 10, 20, 15, 7}
op: 20

ip: arr[] = {10, 20, 15, 5, 23, 90, 67}
op: 20 or 90

ip: arr[] = {80, 70, 90}
op: 80 or 90

Naive: check for single el, return it
check for corner el, 
    - if first_el > second_el, return first_el
    - if last_el > second_last_el, return last_el
    - check middle els, for every check if its greater than  or equal to prev_el and greater than or eqal to next_el, if yes, return that el

Time: O(n-3) = O(n)

Efficient: use binary search even if arr is unsorted
We go to the middle element, 
    check if arr[mid] is peak element, return it, 

    If arr[mid] is not peak el
    now there is fact, if arr[mid-1]>=arr[mid], then we will find peak el on left side, 
    else peak el will be found on right side

dry run
arr[] = {5, 20, 40, 30, 20, 50, 60}
op: 40

arr[] = {5, 80, 40, 30, 20, 50, 60}
op: 80 or 60

Time: O(log n)
*/

int naive(int arr[], int n)
{
    if (n==1)
        return arr[0];
    
    if(n==2)
    {
        if(arr[0] >= arr[1])
            return arr[0];
        else 
            return arr[1];
    }

    if(arr[n-1] >= arr[n-2])
        return arr[n - 1];

    for (int i = 1; i < n-1; i++)
    {
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return arr[i];
    }
}

int efficient(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    if (n == 2)
    {
        if (arr[0] >= arr[1])
            return arr[0];
        else
            return arr[1];
    }

    if (arr[n - 1] >= arr[n - 2])
        return arr[n - 1];

    int low = 0, high = n - 1;
    while(low<=high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= arr[mid - 1] && arr[mid] >= arr[mid + 1])
            return arr[mid];
        
        if(arr[mid-1] >= arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
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
    cout << efficient(arr, n);

    return 0;
}
