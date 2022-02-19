#include <iostream>
#include <stack>
#include <vector>
// for reverse function
#include <algorithm>
using namespace std;

/*

Given an array of int,
find next greater (position-wise closest on right side)
for every array element

ip: arr[] = {5, 15, 10, 8, 6, 12, 9, 18}
op:         15  18  12 12 12  18 18  -1

ip: arr[] = {10, 15, 20, 25}
op:          15  20  25 -1

ip: arr[] = {25, 20, 15, 10}
op:          -1  -1  -1  -1

Naive sol O(n^2):
for each element
we traverse to right of it,
if we find a greater element,
print the ele and break the loop

Efficient solution:
Traverse from right to left
find prev greater element on right side
that will be actually the next greater element
and for the logic of previous greater element
we push initially last element of arr into stack

then begin from second last el
we keep popping the smaller elements if they are present in stack
so whatever is remaining at top will be either
1) first prev greater element
2) stack will be empty

if stack is empty, print -1
otherwise ans is top of stack
we push the current element in the stack for next iteration

we need to print the entire output in reverse order 
Time: O(2n) 
Space: O(n)
*/

void nextGreater_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }

        if(j==n)
            cout << "-1 ";
    }
} 

vector<int> nextGreater_eff(int arr[], int n)
{
    vector<int> ans;
    stack<int> s;

    s.push(arr[n - 1]);
    ans.push_back(-1);
    for (int i = n - 2; i >= 0; i--)
    {
        while(!s.empty() && s.top()<=arr[i])
            s.pop();

        int res = s.empty() ? -1 : s.top();
        ans.push_back(res);
        s.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int arr[] = {5, 15, 10, 8, 6, 12, 9, 18};
    vector<int> ans = nextGreater_eff(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " " << ans[i] << "\n";
    }
    return 0;
}
