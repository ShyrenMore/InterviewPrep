#include <iostream>
using namespace std;

/*

Problem statement: Count inversions in an arr
A pair (arr[i], arr[j]) forms ans inversion 
when i<j and arr[i]>arr[j]

in simpler terms, a greater element appears before a smaller element 

ip: 2, 4, 1, 3, 5
op: 3 [(4,1) (4,3) (2, 1)]

ip: 10 20 30 40
op: 0

ip: 40 30 20 10
op: 6, 3+2+1

*/

/*

Naive: I will traverse the array maintaining two pointers, one present at current element and second will traverse elements next to it

if current_el > any of the next el
    increment count 

Time: O(n*n)
*/

int naive_get_inversions(int arr[], int n)
{
    int i, j, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
                ++count;
        }
    }
    return count;
}

/*

Efficient: based on merge sort 
Time: O(n logn) 
Space: O(n) 

- Divide array into two halves
- sort these two halves recursively
- merge these two halves 

but in these merge sort operation, we also count inversions while sorting the array
We count inversions in left half and right half, and while merging 
we count inversions where one el is from left half and other is from right half 

For every inversion (x, y) where x>y has possibilities
- both x and y lie in left half
- both x and y lie in right half
- x is in left half & y is in right half

see video about why we sort
*/

int countandMerge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    int res = 0, i = 0, j = 0, k = l;

    while(i<n1 && j<n2)
    {
        if(left[i] <= right[i])
        {
            arr[k] = left[i];
            ++i;
        }
        else 
        {
            arr[k] = right[j];
            ++j;

            // only extra part
            res = res + (n1 - i);
        }
        k++;
    }

    while(i<n1)
    {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while(j<n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    return res;
}

int countInv(int arr[], int l, int r)
{
    int res = 0;
    if(l<r)
    {
        int m = l + (r - 1) / 2;
        res += countInv(arr, l, m);
        res += countInv(arr, m+1, r);
        res += countandMerge(arr, l, m, r);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << naive_get_inversions(arr, n);
}