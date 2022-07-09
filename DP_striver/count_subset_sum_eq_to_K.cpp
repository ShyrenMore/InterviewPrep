/*
problem link: https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532

You are given an array (0-based indexing) of positive integers and
you have to tell how many different ways of selecting the elements from the array are there
such that the sum of chosen elements is equal to the target number “tar”.

If N = 4 and tar = 3 and the array elements are [1, 2, 2, 3], then the number of possible ways are:
{1, 2}
{3}
{1, 2}
Hence the output will be 3.
*/

#include <iostream>
#include <vector>
using namespace std;

class Recursive_Sol
{
public:
    int f(vector<int> &arr, int idx, int target)
    {
        if (target == 0)
            return 1;

        if (idx == 0)
            return (arr[0] == target);

        int not_take = f(arr, idx - 1, target);
        int take = 0;
        if (arr[idx] <= target)
            take = f(arr, idx - 1, target - arr[idx]);

        return (take + not_take);
    }

    int findWays(vector<int> &num, int tar)
    {
        int n = num.size();
        return f(num, n - 1, tar);
    }
};

class Memp_Sol{
public:
    int findWaysUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 1;

        if (ind == 0)
            return arr[0] == target;

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTaken = findWaysUtil(ind - 1, target, arr, dp);

        int taken = 0;
        if (arr[ind] <= target)
            taken = findWaysUtil(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = notTaken + taken;
    }

    int findWays(vector<int> &num, int k)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return findWaysUtil(n - 1, k, num, dp);
    }
};

class Tabulation_Sol{
public:
    int findWays(vector<int> &num, int k)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = 1;
        
        if (num[0] <= k)
            dp[0][num[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= k; target++)
            {

                int notTaken = dp[ind - 1][target];
                int taken = 0;
                if (num[ind] <= target)
                    taken = dp[ind - 1][target - num[ind]];

                dp[ind][target] = notTaken + taken;
            }
        }

        return dp[n - 1][k];
    }
};