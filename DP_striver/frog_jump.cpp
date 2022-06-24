/*

There is a frog on the 1st step of an N stairs long staircase.
The frog wants to reach the Nth stair.
HEIGHT[i] is the height of the (i+1)th stair.
If Frog jumps from ith to jth stair, the energy lost in the jump is given by |HEIGHT[i-1] - HEIGHT[j-1] |.
If the Frog is on ith staircase, he can jump either to (i+1)th stair or to (i+2)th stair.
Your task is to find the minimum total energy used by the frog to reach from 1st stair to Nth stair.

ip: n and height arr
op: return an integer corresponding to the minimum energy lost to reach the last stair.

ip: 4
10 20 30 10
op: 20

ip: 3
10 50 10
op: 0

Follow up: 
Read after all optimisation
if there are k indices to jump, what will you do?
like you are allowed to either jump
i+1, i+2 or..i+k
what's the min cost now

Answer:
we have to put recurrence in for loop
f(idx)
{
    if(idx == 0)
        return 0;

    // if dp!=-1: return dp[idx]

    int min_steps = INT_MAX;
    for(j = 1; j <= k; j++)
    {
        if(idx>=j)
            jump = f(idx-j) + abs(height[idx] - height[idx-j]);
        min_steps = min(min_steps, jump);

        //dp[idx]=min_steps
    }

    return min_steps;
}

Time: O(n*k) if memoization is applied 
*/
#include <iostream>
#include <vector>
#include <math.h>
#define INT_MAX INT32_MAX
using namespace std;

// pure recursive sol
int f_r(int idx, vector<int> &heights)
{
    if(idx == 0)
        return 0;

    int left = f_r(idx - 1, heights) + fabs(heights[idx] - heights[idx - 1]);
    int right = INT_MAX;
    if(idx>1)
        right = f_r(idx - 2, heights) + fabs(heights[idx] - heights[idx - 2]);

    return min(left, right);
}

int frogJump_r(int n, vector<int> &heights)
{
    return f_r(n - 1, heights);
}

// memoization
int f_m(int idx, vector<int> &heights, vector<int> &dp)
{
    if (idx == 0)
        return 0;

    if(dp[idx]!=-1)
        return dp[idx];

    int left = f_m(idx - 1, heights, dp) + fabs(heights[idx] - heights[idx - 1]);
    int right = INT_MAX;
    if (idx > 1)
        right = f_m(idx - 2, heights, dp) + fabs(heights[idx] - heights[idx - 2]);

    return dp[idx] = min(left, right);
}

int frogJump_m(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f_m(n - 1, heights, dp);
}

// tabulation
int frogJump_t(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int l = dp[i - 1] + fabs(heights[i - 1] - heights[i]);
        int r = INT_MAX;
        if(i>1)
            r = dp[i - 2] + fabs(heights[i - 2] - heights[i]);

        dp[i] = min(l, r);
    }

    return dp[n - 1];
}

// space optimisation
int frogJump_s(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int l = prev1 + fabs(heights[i - 1] - heights[i]);
        int r = INT_MAX;
        if(i>1)
            r = prev2 + fabs(heights[i - 2] - heights[i]);

        int curr = min(l, r);

        prev2 = prev1;
        prev1 = curr;
    }

    // since at i == n, i-1 will be prev1
    return prev1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << frogJump_r(n, arr);
    cout << frogJump_m(n, arr);
    cout << frogJump_t(n, arr);

    // space opti
    cout << frogJump_s(n, arr);
    return 0;
}