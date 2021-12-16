#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*

Given an arr of non-negative integers i.e arr contains 0 or positive values

values in arr represent heights of bar

how much water can you collect between these two bars

ip: arr[] = {2, 0, 2}
op: 2

ip: arr[] = {3, 0, 1, 2, 5}
op: 6 (3+2+1)

ip: arr[] = {1, 2, 3}
op: 0

ip: arr[] = {3, 2, 1}
op: 0

Approach: 
consider ip: arr[] = {3, 0, 1, 2, 5}

some observations: 
1) you cannot store water on top of corner bars
2) for an arr el, or for a single bar, we calc leftmost maximum and rightmost maximum height
and finally the current bar will store min(leftMax, rightMax)-height of curr bar

eg: from digram we see if we follow 0-based indexing, 
bar no 2 stores 2 units of water 

as per our approach here currHeight = 1, leftMax=3, rightMax=5

hence, bar no 2 stores min(3, 5)-1 = 3-1 = 2

so we traverse all bars except corner, i.e from i=1 to n-2
for each element we calculate lMax and rMax

Time: Theta n^2, for every el, we traverse to left and right of it 
*/

int getWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int leftMax = arr[i];
        for (int j = i-1; j >= 0; j--)
            leftMax = max(arr[j], leftMax);

        int rightMax = arr[i];
        for (int j = i + 1; j < n; j++)
            rightMax = max(rightMax, arr[j]);

        // deb2(rightMax, leftMax);
        res = res + min(leftMax, rightMax) - arr[i];
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
    cout << getWater(arr, n);

    return 0;
}