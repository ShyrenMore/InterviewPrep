/*
Given n: number of stair
initially you are at 0th stair
Each time, you are at a step:
    - you can climb one step at a time OR
    - two steps at a time

Return no of distinct ways in which you can climb from 0th to Nth step

ip: n=3
op: 3
exp:

way 1: 0, 1, 2, 3
way 2: 0, 2, 3
way 3: 0, 1, 3
*/

#include <iostream>
#include <cstring> // for memset
#include <vector>
using namespace std;

int recursive_sol(int n)
{
    if(n==0)
        return 1;
    if (n==1)
        return 1;

    return recursive_sol(n-1) + recursive_sol(n-2);
}

int main()
{
    int n;
    cin >> n;
    cout << recursive_sol(n);
}