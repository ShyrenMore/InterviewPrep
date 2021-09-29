#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given an arr, find len of longest subarray containing alternating even odd elements

ip: arr[] = {10, 12, 14, 7, 8}
op: 3 (14, 7, 8)

ip: arr[] = {7, 10, 13, 14}
op: 4 (entire arr)

ip: arr[] = {10, 12, 8, 4}
op: 1 (all el are even)

dry run: arr[] = {5, 10, 20, 6, 3, 8}
op: 3

Approach: Traverse the array, for every element find longest alternating subarray that begins with the element 

if len of this curr subarr is greater than the lengths we have found so far then we update the maxLength variable

there are two possibilitoes for the curr element to be alternating:
1) curr element is even & prev el is odd OR
2) curr element is odd & prev el is even

Time: O(n^2)
*/

int getMaxLenEvenOdd(int arr[], int n)
{
    int res = 1;

    for (int i = 0; i < n; i++)
    {
        int currLen = 1;
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[j] % 2 == 0 && arr[j - 1] % 2 != 0) || (arr[j] % 2 != 0 && arr[j - 1] % 2 == 0))
                ++currLen;
            else
                break;
        }
        res = max(res, currLen);
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
    cout << getMaxLenEvenOdd(arr, n);

    return 0;
}