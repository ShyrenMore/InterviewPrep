#include <bits/stdc++.h>
using namespace std;

/*
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements
from 2nd position to 4th position
is 12.
*/

/*
Input:
N = 10, S = 15
A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements
from 1st position to 5th position
is 15.
*/

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        int startidx = 0;
        vector<int> ans_subarray;
        bool subArrayFound = false;
        int curr_sum = arr[0];

        int end = 1;
        while (end <= n)
        {
            while (curr_sum > s && startidx < end - 1)
            {
                curr_sum -= arr[startidx];
                startidx++;
            }

            if (curr_sum == s)
            {
                subArrayFound = true;
                break;
            }

            if (end < n)
                curr_sum += arr[end];
            end++;
        }

        if (subArrayFound)
        {
            // idk why +1 is needed
            ans_subarray.push_back(startidx + 1);
            ans_subarray.push_back(end);
        }
        else
            ans_subarray.push_back(-1);
        return ans_subarray;
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long s;
        cin >> n >> s;
        int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} 