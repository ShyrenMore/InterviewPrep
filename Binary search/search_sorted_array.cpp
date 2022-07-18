/*
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
exp: target appears at idx 4

Linear Approach:
Linear search of target
O(N) time and O(1) space

Better Approach:
Binary search

low = 0, high = n-1 = 6
mid = 3
arr[mid] = 7
The left half is sorted [4,5,6,7]
we conclude that by saying  4<7

but target does not lie b/w 4 to 7
eliminate left half
new_low = mid+1 = 4
high = 6
mid = 5
arr[mid] = 1
0<1 then entire right half is sorted
0<=traget<1
hence target lies in right half

new_high = mid-1 = 4
low = 4
mid = 4
arr[mid] == target
idx found!

Time: O(log N)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while(low<=high)
        {
            int mid = (low + high) >> 1;
            if(nums[mid] == target)
                return mid;
            
            // if left side is sorted
            if(nums[low] <= nums[mid])
            {
                // if target lies in left half
                if(target >= nums[low] && target <= nums[mid])
                    high = mid - 1; // eliminate right half
                else
                    low = mid + 1;
            }
            else // right side is sorted
            {
                // if target lies in right half
                if (target >= nums[mid] && target <= nums[high])
                    low = mid + 1; // eliminate left half
                else
                    high = mid - 1;
            }   
        }
        return -1;
    }
};
