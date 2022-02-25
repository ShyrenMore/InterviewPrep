#include <iostream>
#include <stack>
using namespace std;

/*
Given an arr of ints,
every val represents heights of different bars in a histogram
width of all bars is 1 unit
find largest rectangular area in the histogram

ip: arr[] = {6, 2, 5, 4, 1, 5, 6}
op: 10 (last two bars)

ip: arr[] = {2, 5, 1}
op: 5 (2nd bar)

Naive sol:
we consider every element as the smallest bar,
we find rectangular area with these bar being smallest
we do this for each bar and return max area
for ith bar, I can find area as
1) go to left of it and include all consecutive bars having height greater or equal to ith bar height
2) go to right of it and include all consecutive bars having height greater or equal to ith bar height

and we keep adding i, whenver we find a bar that satisfies above two conditions 

eg: we have sequence like 6, 2, 5, 4, 1, 5, 6
we are at bar having height 2
we go left to it, we find 6, so area = 2+2 = 4
we go right to it, we find 5, 4, so area = 4+2+2 = 8
which is diagramatically true

Time: theta(n^2)

Better sol below
*/

int getMaxHistogramArea_naive(int arr[], int n)
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        // consider arr[i] as smallest bar
        int curr_area = arr[i];

        // go left and keep adding curr bar if >= height
        for (int j = i - 1; j >= 0; j--)
        {
            if(arr[j] >= arr[i])
                curr_area += arr[i];
            else
                break;
        }

        // go right and keep adding curr bar if >= height
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
                curr_area += arr[i];
            else
                break;
        }

        res = max(res, curr_area);
    }

    return res;
}

/*

Dry run for naive method:
arr = [6, 2, 5, 4, 1, 5, 6]
initialise res = 0
i = 0: arr[i] = 6, curr_area = 6
i = 1: arr[i] = 2, curr_area = 8, res = 8
i = 2: arr[i] = 5, curr_area = 5, res = 8
i = 3: arr[i] = 4, curr_area = 8, res = 8
i = 4: arr[i] = 1, curr_area = 7, res = 8
i = 5: arr[i] = 5, curr_area = 10, res = 10
i = 6: arr[i] = 6, curr_area = 6

*/

/*

Better solution: O(n) time, O(n) space

1) we find prevsmaller el and next smaller el for each el

for finding prev smaller el
we compare stack top with curr el
if curr el is greater than top,
    push that el into stack
otherwise
    pop the top items until we find an el at top that is <= current el
so basically top of stack will always have previous smaller element

so here we are going to pre-process
and find indexes of previous smaller, next smaller elements for each element
and then we find out, how many bars on left and right have height greater than or equal

in prev smaller(ps) array, if an element does not have prev smaller el, then we put -1
in next smaller(ns) array, if element does not have next smaller el, then we put n (impossible index)

curr_area = arr[i]
curr_area += (i - ps[i] - 1) * arr[i]
curr_area += (ns[i] - i - 1) * arr[i]
res = max(res, max)
So basically this is an extension of naive sol

this sol requires, 3 traversals 
one to create prev smaller array
one to create next smaller array
one to do computation

also there are multiple auxilary arrays

*/

/*

Efficient solution: 
1) create empty stack
2) initialise res var with 0
3) Traverse all the items 
find prev smaller element

when we push an index i into stack
when top of stack is < curr_el
the item below it, is prev smaller of it 
when we pop item of stack, 
*/

int getMaxHistogramArea_eff(int arr[], int n)
{
    stack<int> s;
    int res = 0, curr=0;
    int tp = -1;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            tp = s.top();
            s.pop();

            curr = arr[tp] * (s.empty() ? i : (i - s.top() - 1));

            res = max(res, curr);
        }

        s.push(i);
    }

    while(!s.empty())
    {
        tp = s.top();
        s.pop();
        curr = arr[tp] * (s.empty() ? n : (n - s.top() - 1));
        res = max(res, curr);
    }

    return res;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 1, 5, 6};
    cout << getMaxHistogramArea_eff(arr, 7);
    return 0;
}