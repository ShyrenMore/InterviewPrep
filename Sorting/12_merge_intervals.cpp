/*

Given a set of intervals, 
an interval contains start time and end time
eg: {1,3} means start=1, end=3
when there is overlapping part b/w two intervals we need to merge it by taking min of start time and max of end time 

eg {1, 3} and {2, 4} has common part from 2-3, so new merged intervals will be {1, 4} i.e {min(1, 2), max(3, 4)}

ip: {{1, 3}, {2, 4}, {5, 7}, {6, 8}}
op: {{1, 4}, {5, 8}}

ip: {{7, 9}, {6, 10}, {4, 5}, {1, 3}, {2, 4}}
op: {{1, 5}, {6, 10}}

*/

#include <iostream>
#include <algorithm>
using namespace std;

/*

we can use pair container or create a struct for the same

vector<pair<int, int>> arr(n);

First check if intervals overlap

Method 1
we do this was taking larger start value say start1 of first interval and checking if it lies in second interval i.e b/w start2 and end2

eg: i1 = {5, 10} && i2 = {1, 7}
5>1
here 5 lies b/w 1 and 7, so two intervals are overlapping

Method 2
we do this was taking smaller end value of first interval and checking if it lies in second interval i.e b/w start2 and end2

eg: i1 = {5, 10} && i2 = {1, 7}
here smaller end value = 7
is 7 lying b//w 5 and 10, yes
so both intervals are overlapping 
*/

/*

Naive O(n^3)
we traverse through all intervals one by one
I check if the current interval overlaps with any of other intervals, if it does, I will merge the intervals and delete the other intervals

The value of the merged interval will be
start = min(i1.start, i2.start);
end = max(i1.end, i1.end);

n^2 time for making pairs
n time for deleting a pair 

*/

/*

efficient solution
sort the intervals wrt inc order of start time/dec order of end time

let's consider inc order of start time
when you are at interval xi, the intervals from x1,x2 .. xi-1 must have been merged
Now we have non-overlapping intervals say m1, m2...mj-1, mj

Claim: the interval xi, will only be merged with mj
i.e start time of mj> start time of mj-1
and xi start time has to be greater than start of mj-1 

in simpler words, since
xi.start >= mj.start
mj-1.end < mj.start
hence
xi.start > mj-1.end is true

So traverse the array after sorting, keep merging the intervals, for every interval check only prev merged interval

we are not going to use an auxilary array for storing non-overlapping merged intervals
we maintain a res index, el from 0 to res, will contain non-overlapping merged interval

O(nlogn) time complexity
*/

struct Interval
{
    int start, end;
};

bool cmp(Interval i1, Interval i2)
{
    return i1.start<i2.start;
}

void mergeIntervals(Interval arr[], int n)
{
    sort(arr, arr + n, cmp);
    cout << "\nintervals after sorting\n";
    for (int i = 0; i < n; i++)
        cout << arr[i].start << " " << arr[i].end << "\t";
    cout << "\n\n";
    int res = 0;

    for (int i = 1; i < n; i++)
    {
        if(arr[res].end >= arr[i].start)
        {
            arr[res].end = max(arr[res].end, arr[i].end);
            arr[res].start = max(arr[res].start, arr[i].start);
        }
        else 
        {
            res++;
            arr[res] = arr[i];
        }
    }

    cout << "op\n";
    for (int i = 0; i <= res; i++)
        cout << arr[i].start << " " << arr[i].end << "\n";
}

int main()
{
    int n;
    cin >> n;
    Interval arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    mergeIntervals(arr, n);
    return 0;
}

/*

input::

4
5 10
3 15
18 30
2 7

intervals after sorting
2 7     3 15    5 10    18 30

output
5 15
18 30

*/