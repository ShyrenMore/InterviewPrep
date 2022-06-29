#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// pure recursive sol

int f(int day, int prev_picked, vector<vector<int>>&points)
{
    if(day == 0)
    {
        int maxi = -1;
        for (int task = 0; task < 3; task++)
            if(task!=prev_picked)
                maxi = max(maxi, points[0][task]);

        return maxi;
    }

    int maxi = -1;
    for (int task = 0; task < 3; task++)
        if(task!=prev_picked)
        {
            int curr_pts = points[day][task];
            int prev_day_pts = f(day - 1, task, points);
            maxi = max(maxi, curr_pts + prev_day_pts);
        }

    return maxi;
}

int ninjaTraning(int n, vector<vector<int>> &points)
{
    return f(n - 1, 3, points);
}

// memoization

int f_m(int day, int prev_picked, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = -1;
        for (int task = 0; task < 3; task++)
            if (task != prev_picked)
                maxi = max(maxi, points[0][task]);

        return maxi;
    }

    if(dp[day][prev_picked]!=-1)
        return dp[day][prev_picked];

    int maxi = -1;
    for (int task = 0; task < 3; task++)
        if (task != prev_picked)
        {
            int curr_pts = points[day][task];
            int prev_day_pts = f_m(day - 1, task, points, dp);
            maxi = max(maxi, curr_pts + prev_day_pts);
        }

    return dp[day][prev_picked]=maxi;
}

int ninjaTraning_m(int n, vector<vector<int>> &points)
{
    // n*4 vector
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f_m(n - 1, 3, points, dp);
}
 
// tabulation
int ninjaTraning_t(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // base cases
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);


    for (int day = 1; day < n; day++)
    {
        for (int prev_pick = 0; prev_pick < 4; prev_pick++)
        {
            for (int task = 0; task < 3; task++)
                if (task != prev_pick)
                {
                    int curr_pts = points[day][task];
                    int prev_day_pts = dp[day-1][task];
                    dp[day][prev_pick] = max(dp[day][prev_day_pts], curr_pts + prev_day_pts);
                }
        }
    }

    return dp[n - 1][3];
}