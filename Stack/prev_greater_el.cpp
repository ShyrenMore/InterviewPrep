#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*

Given an array of distinct integers, find prev greater element for every el
prev greater el is the element that is
closest(position-wise) greater on left side
if there is no greater element on left side, print -1

ip: arr[] = {15, 10, 18, 12, 4, 6, 2, 8}
op:          -1  15  -1  18 12 12  6 12

ip: arr[] = {8, 10, 12}
op:         -1  -1  -1

ip: arr[] = {12, 10, 8}
op:          -1  12  10

Naive approach O(n^2):
Traverse array from left to right 
for every element traverse to it's left side
if we find a greater element, we print and break the loop

Efficient solution O(n) time:

initialise an empty stack and push first item
print -1, since prev greater of first el will always be -1

we traverse array from left to right from index 1
we keep popping the smaller elements if they are present in stack
so whatever is remaining at top will be either
1) first prev greater element
2) stack will be empty

if stack is empty, print -1
otherwise ans is top of stack
we push the current element in the stack for next iteration

*/

void prevGreater_naive(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j;
        for (int j = i - 1; j >= 0; j--)
        {
            if(arr[j] > arr[i])
            {
                cout << arr[j] << " ";
                break;
            }
        }
        if(j==-1)
            cout << "-1 ";
    }
}

vector<int> printPrevGreater(int arr[], int n)
{
    stack<int> s;
    vector<int> ans;
    s.push(arr[0]);
    ans.push_back(-1);

    for (int i = 1; i < n; i++)
    {
        while(!s.empty() && s.top()<=arr[i])
            s.pop();

        int res = s.empty() ? -1 : s.top();
        ans.push_back(res);
        s.push(arr[i]);
    }

    return ans;
}

int main()
{
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    vector<int> ans = printPrevGreater(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " " << ans[i] << "\n";
    }
    return 0;
}

/*
op:
15 -1
10 15
18 -1
12 18
4 12
6 12
2 6
8 12
*/