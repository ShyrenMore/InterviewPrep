/*
problem link: https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

Let the sum of the elements of  two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’.

ip: 5 2 6 4 && diff = 3
op: 1
exp:
Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3
*/

#include <iostream>
#include <vector>
using namespace std;

class Rec_Solution {
public:
    int f(int idx, int target, vector<int> &arr)
    {
        if (idx == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        int not_pick = f(idx - 1, target, arr);
        int pick = 0;
        if(arr[idx] <= target)
            pick = f(idx - 1, target - arr[idx], arr);

        return pick + not_pick;
    }

    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totSum = 0;
        for(auto x: arr)
            totSum += x;

        // Checking for edge cases
        if (totSum - d < 0)
            return 0;
        if ((totSum - d) % 2 == 1)
            return 0;

        int tgt = (totSum - d) / 2;
        return f(n - 1, tgt, arr);
    }
};

class Memo_Sol{
public:
    int mod = (int)1e9 + 7;
    int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTaken = f(ind - 1, target, arr, dp);

        int taken = 0;
        if (arr[ind] <= target)
            taken = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = (notTaken + taken) % mod;
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totSum = 0;
        for (int i = 0; i < arr.size(); i++)
            totSum += arr[i];
        
        // Checking for edge cases
        if (totSum - d < 0)
            return 0;
        if ((totSum - d) % 2 == 1)
            return 0;

        int s2 = (totSum - d) / 2;

        vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
        return f(n - 1, s2, arr, dp);
    }
};

class TabulationSol{
public:
    int mod = (int)1e9 + 7;
    int f(vector<int> &num, int tar)
    {
        int n = num.size();
        vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
        if (num[0] == 0)
            dp[0][0] = 2; // 2 cases -pick and not pick
        else
            dp[0][0] = 1; // 1 case - not pick

        if (num[0] != 0 && num[0] <= tar)
            dp[0][num[0]] = 1; // 1 case -pick

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= tar; target++)
            {
                int notTaken = dp[ind - 1][target];
                int taken = 0;
                if (num[ind] <= target)
                    taken = dp[ind - 1][target - num[ind]];
                dp[ind][target] = (notTaken + taken) % mod;
            }
        }
        return dp[n - 1][tar];
    }
    int countPartitions(int n, int d, vector<int> &arr)
    {
        int totSum = 0;
        for (int i = 0; i < arr.size(); i++)
            totSum += arr[i];

        // Checking for edge cases
        if (totSum - d < 0)
            return 0;
        if ((totSum - d) % 2 == 1)
            return 0;

        int s2 = (totSum - d) / 2;
        return f(arr, s2);
    }
};