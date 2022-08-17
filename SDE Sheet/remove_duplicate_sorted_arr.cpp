#include <iostream>
#include <vector>
using namespace std;

/*
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * Video: https://youtu.be/DEJAZBq0FDA

Approach:
Maintain two pointers:
left - where we will put next unique value
right - traverse remaining portion of arr

left ptr will also tell us how many unique values we have seen so far

How do we find if curr item is unique:
- we visit first time, then the prev el will be different
eg: 0, 1, 1
here when we encounter first 1, we see prev is 0
if prev is also 1 that means, it's a dupli

we initialise l, r at second position

we stop the loop when r goes out of bounds
left will have our ans

Time: O(2N)
Space: O(1)
*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int l = 1;
        for (int r = 1; r < nums.size(); r++)
        {
            // is it a new value?
            if(nums[r] != nums[r-1])
            {
                nums[l] = nums[r];
                l++;
                // r is inc by for loop
            }
        }

        return l;
    }
};
