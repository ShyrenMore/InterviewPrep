/*
https://leetcode.com/problems/single-element-in-a-sorted-array/

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.
Return the single element that appears only once.

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Linear Approach:
XOR all numbers, whatver number remains at last will be answer

Better approach:
Since arr is sorted try binary search

Find a breakpoint such that
- to the left all elements appears twice
- to the right the single element starts and then all els are twice

on the left half
the first instance of any number is at even idx
the second instance of any number is at odd idx

Vice-versa is on left half

keep low = 0 and high = n-2(second last idx)
mid = 3
check if mid is on left half
we do this by checking if arr[mid] apperas before it
if it does not then we are not on left side
we are not on left

new high = mid-1 = 2
mid = 1
check if mid is on left half
we do this by checking if arr[mid] apperas before it
we are on left half

new low = mid+1
low = high = 2
mid = 2
check if mid is on left half
we are at even idx
then 2nd instance i.e arr[mid] and arr[mid+1] should be matching
it does not
we are not on left
high = mid-1 = 1
now low>high
breakpoint found
ans is arr[low]

since low>high in anycase, thi was the reason we initialise high at second last index

Time: O(log N)
Space: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 2;
        while (low <= high)
        {
            // div by 2, right shift
            int mid = (low + high) >> 1;

            // odd xor 1 == next even == odd+1
            // even xor 1 == next odd == even+1

            // prev even or next odd
            // if on left half, shrink
            if (nums[mid] == nums[mid ^ 1])
                low = mid + 1;
            else
                high = mid - 1;
        }

        return nums[low];
    }
};
