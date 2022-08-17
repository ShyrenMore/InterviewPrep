#include <iostream>
#include <vector>
using namespace std;

/*
link: https://leetcode.com/problems/trapping-rain-water/
*/

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0;
        int n = height.size();
        int leftMax[n], rightMax[n];

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++)
            leftMax[i] = max(height[i], leftMax[i - 1]);

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(height[i], rightMax[i + 1]);

        for (int i = 1; i < n - 1; i++)
            ans += min(leftMax[i], rightMax[i]) - height[i];

        return ans;
        // Time: theta(n);
    }
};