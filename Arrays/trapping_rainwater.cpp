/*
Given arr of non-neagtive ints
The value represented in array are heights of bars
How much water can you collect between these bars
see image for ip/op

Approach:
some observations:
1) you cannot store water on top of corner bars
2) for an arr el, or for a single bar, we calc leftmost maximum and rightmost maximum height
and finally the current bar will store min(leftMax, rightMax)-height of curr bar

eg: from digram testcase 2, we see if we follow 0-based indexing,
bar no 2 stores 2 units of water
as per our approach here currHeight = 1, leftMax=3, rightMax=5
hence, bar no 2 stores min(3, 5)-1 = 3-1 = 2

so we traverse all bars except corner, i.e from i=1 to n-2
for each element we calculate lMax and rMax

Time: O(n^2)
*/

#include <iostream>
using namespace std;

int getWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = arr[i];
        for (int j = i - 1; j >= 0; j--)
            leftMax = max(arr[j], leftMax);

        int rightMax = arr[i];
        for (int j = i + 1; j < n; j++)
            rightMax = max(rightMax, arr[j]);

        res = res + min(leftMax, rightMax) - arr[i];
    }

    return res;
}

/*
Efficient sol:
Precompute leftmax and rightmax
For doing this maintain two arrays leftMax[] and rightMax[]
initialise leftMax[0] = arr[0]
Traverse 1 to n
    check if curr el is greater than prev leftmax
    if greater, update leftMax[i]
So we have now constructed leftMax array

Simiarly we fill rightmax array, but we start filling it from right side
so rightMax[n-1] = arr[n-1]
now traverse n-2 to 0
    check if curr el is greater than next rightMax
    if greater then rightMax[i] = arr[i], else rightMax[i+1]
So we have now constructed RightMax array

both have taken theta(n) time
finally compute how much can a vertical column hold
traverse the array from 1 to n-2
Each el or bar can hold min(leftMax, rightMax) - bar height
we keep on summing up the volume in each oteration

res = res + (min(leftMax[i], rightMax[i]) - arr[i])

res is our answer!

Time: O(3n) theta(n) space because of 2 arrays
*/

int getWater_eff(int arr[], int n)
{
    int res = 0;
    int leftMax[n], rightMax[n];
    leftMax[0] = arr[0];

    for (int i = 1; i < n; i++)
        leftMax[i] = max(arr[i], leftMax[i - 1]);

    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(arr[i], rightMax[i + 1]);

    for (int i = 1; i < n - 1; i++)
        res += min(leftMax[i], rightMax[i]) - arr[i];

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
    cout << getWater(arr, n)<<"\n";
    cout << getWater_eff(arr, n)<<"\n";

    return 0;
}