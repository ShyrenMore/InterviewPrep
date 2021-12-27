#include <iostream>
using namespace std;

/*

given an array that contains three types of elements

These can be asked in different forms
eg:
1) sort an array of 0s, 1s and 2s
ip: arr[] = {0, 1, 0, 2, 1, 2}
op: arr[] = {0, 0, 1, 1, 2, 2}

2) three way partitioning
given an array, partition the array around a pivot and there can be multiple occurences of pivot, all ocuurences should come together

ip: arr[] = {2, 1, 2, 20, 10, 20, 1}    pivot=2
op: arr[] = {1, 1, 2, 2, 20, 10, 20}
note order of elements <20 and >20 need not be sorted

3) partition around a range
ip: arr[] = {10, 5, 6, 3, 20, 9, 40}    range = [5, 10]
op: arr[] = {3, 5, 6, 9, 10, 20, 40}

*/

/*

Naive approach: Use an auxilary array, traverse through input arr, consider only 0's and put them in auxilary array

we again traverse input array, this time we looks for 1's and put them in the aux array

lastly we traverse ip array again for 2's and put them after 1's

Finally copy aux array to original array

time: θ(4n)     space: θ(n)

another approach will be to count 0, 1, 2 in array and accordingly create the ans array, but if you treat them as key values pair i.e objects, then this approach will result in losing relation with actual object
*/

void naive_sort_0_1_2s(int arr[], int n)
{
    int temp[n], i = 0;

    for (int j = 0; j < n; j++)
        if (arr[j] == 0)
        {
            temp[i] = arr[j];
            ++i;
        }

    for (int j = 0; j < n; j++)
        if (arr[j] == 1)
        {
            temp[i] = arr[j];
            ++i;
        }

    for (int j = 0; j < n; j++)
        if (arr[j] == 2)
        {
            temp[i] = arr[j];
            ++i;
        }

    for (int j = 0; j < n; j++)
        arr[j] = temp[j];
}

/*

Efficient: use dutch national flag algorithm
a variation of hoarse partition

here we want all pivots i.e 1 to come together
and all smaller elements to left side (0s)
and all greater elements to right side (2s)

idea: we maintain 4 sections in our array
1) 0 to low-1 will contains 0s
2) low to mid-1 will contains 1s
3) mid to high is unknown i.e we are currently processing them
4) high to n-1 are 2s

Diagram

---------------------------
| 0s | 1s | unknowns | 2s |
---------------------------
0   low   mid      high  n-1

we do mid++ and hi--, when they cross each other, the entire array is traversed

we initialise low=0, high=n-1, mid=0
we need to check arr[mid]
if(arr[mid]==0)     increment boundary of low and move our zero to 1st section
if(arr[mid]==1)     increment boundary of 2nd section by ++mid
if(arr[mid]==2)     increment boundary of 4th section by --high

Time: θ(n) one traversal
Space: O(1)
*/

void eff_sort_0_1_2s(int arr[], int n)
{
    int low = 0, high = n - 1, mid = 0;
    while(mid<=high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            ++low;
            ++mid;
        }
        else if(arr[mid]==1)
            ++mid;
        else 
        {
            swap(arr[mid], arr[high]);
            --high;
        }
    }
}

/*
dry run: imgs/dutch_national_flag.jpg
*/
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // naive_sort_0_1_2s(arr, n);
    eff_sort_0_1_2s(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
