#include <iostream>
#include <vector>
using namespace std;

/*
link: https://leetcode.com/problems/max-consecutive-ones/
*/
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {

        int ans = 0, curr_count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {

            if (nums[i])
                ++curr_count;
            else
            {
                ans = max(ans, curr_count);
                curr_count = 0;
            }
        }
        ans = max(ans, curr_count);
        return ans;
    }
};