#include <iostream>
using namespace std;

/*

Reverse an array
ip: arr[] = {10, 5, 7, 30}
op: arr[] = {30, 7, 5, 10}

Approach: Maintain two idx var: low & high pointing to index of first and last els

Swap these els at both the indexes and then move low and high close to each other

*/

void reverseArr(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }

    // Time: O(n/2) => theta(n)
}

int main()
{
    int arr[] = {5, 12, 30, 40};
    reverseArr(arr, 4);
    for(auto x: arr)
        cout << x << " ";
    return 0;
}

/*
op: 40 30 12 5
*/