/*

Given an array of int, find minimum difference in this array
ip: arr[] = {1, 8, 12, 5, 18}
op: 3

ip: arr[] = {8, 15}
op: 7

ip: arr[] = {8, -1, 0, 3}
op: 1 (0-(-1))

ip: arr[] = {10}
op: INF

*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
naive: consider all pairs, for every pair find the abs value of differnce, and if absoulute value differnce is less than result obtained so far then update the result variable

pair a[i] with prev elements

Time: θ(n^2)

also in c++ it's a huge pain in ass to use abs function
abs function has multiple instances for double, float and int arguments

so it's better to use fabs which returns a double and typecast it into int
*/

int naive_getMinDiff(int arr[], int n)
{
    int res = INT16_MAX;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            res = min(res, int(fabs(arr[i] - arr[j])));

    return res;
}

/*

effcient solution: re-arrange the array in such a way that every element is closest to it's value-wise closest element

then find the diff b/w current el and value wise closest el

we do this by sorting the array,
we compute differences b/w adjacent els
we return minimum diff

Time: O(nlogn) + θ(n) = O(nlogn)
*/

int eff_getMinDiff(int arr[], int n)
{
    sort(arr, arr + n);
    int res = INT16_MAX;

    for (int i = 1; i < n; i++)
    {
        res = min(res, int(fabs(arr[i] - arr[i - 1])));
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // cout<< naive_getMinDiff(arr, n);
    cout << eff_getMinDiff(arr, n);

    return 0;
}
