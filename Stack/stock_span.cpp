#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*

Given an array of integers, prices of stock on n-consecutive days

Find span of stock on every day

span on a day is no of consecutive days
including the current day and days just before it
which have value equal or smaller

ip: arr[] = {13, 15, 12, 14, 16, 8, 6, 4, 10, 30}
op:           1   2   1   2   5  1  1  1  4   10

ip: arr[] = {10, 20, 30, 40}
op:           1   2   3   4

ip: arr[] = {40, 30, 20, 10}
op:           1   1   1   1

ip: arr[] = {30, 20, 25, 28, 27, 29}
op:           1   1   2   3   1   5

Naive Approach:
For every element go to the left side of it
keep on moving to left side while we see smaller or equal to elements
and with the count of iterations we can know the span of that element or day

Dry run after code
Time: O(n^2)
Worst case happens when array is sorted in increasing order

Efficient approach:
Time: O(n)
Obervations:
assuming 0 based indexing:
1) span of curr element = 
(idx of curr element - idx of prev greater element)
2) if there is no prev greater element, then
span is (idx+1)

so we maintain prev greater element in stack
For doing this, 
we traverse the array from left to right
For each element, 
we remove all items from top of stack which are smaller or equal to current item 
after that there are two cases:
1) stack is empty
    then curr item is largest item seen so far
    hence ans = (idx+1)
2) curr item < top of stack
    then whatever is there on top of stack is prev greater el of current item
    ans = curr item idx - prev greater el's index
    and prev greater el's index will be given by stack.top()

so we print the ans
and push the current item into stack for next iteration 

Time: O(n)
Space: O(n)
*/

vector<int> printSpan(int arr[], int n)
{
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int span = 1;
        for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--)
            span++;

        ans.push_back(span);
    }
    return ans;
}

/*

Dry run:
arr[] = {18, 12, 13, 14, 11, 16}
i=0: span=1
i=1: span=1
i=2: span=2
i=3: span=3
i=4: span=1
i=5: span=5

*/

void printSpan_eff(int arr[], int n)
{
    stack<int> s;
    s.push(0);
    cout << "1 ";

    for (int i = 1; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] <= arr[i])
            s.pop();
        int span = s.empty() ? (i + 1) : (i - s.top());
        cout << span << " ";
        s.push(i);
    }
}