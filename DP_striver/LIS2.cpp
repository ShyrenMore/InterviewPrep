/*
problem link: https://leetcode.com/problems/longest-increasing-subsequence/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> aux_arr;
        aux_arr.push_back(nums[0]);

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > aux_arr.back())
                aux_arr.push_back(nums[i]);
            else
            {
                int idx = lower_bound(aux_arr.begin(), aux_arr.end(), nums[i]) - aux_arr.begin();
                aux_arr[idx] = nums[i];
            }
        }
        return aux_arr.size();
    }
};