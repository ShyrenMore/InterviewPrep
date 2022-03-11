#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/*
given two strings
find length of longest common subsequence (LCS)
or
find maximum length of the common appearing subsequence in both strings

ip:
s1 = "ABCDGH"
s2 = "AEDFHR"
op: 3
explnation: ADH

ip:
s1 = "AGGTAB"
s2 = "GXTXAYB"
op: 4
explnation: GTAB

ip:
s1 = "XYZ"
s2 = "XYZ"
op: 3
explnation: XYZ

ip:
s1 = "ABC"
s2 = "XY"
op: 0
explnation: no common char

Hint: assume two strings s1 and s2 of lens m and n
so you have 4 parameters in terms of which you have to write recursion

Solution:
Begin matching strings from any of the two corners
let's say we start from end
taking two eg:
s1 = "AXYZ"
s2 = "BAZ"
and len of s1 = m
and len of s2 = n

last char of both s1 and s2 is same
then we can set LCS=1
now recursively call for remaining string of len m-1 and n-1
Now in our recursive call, the strings are
s1 = "AXY"
s2 = "BA"
this time Y != A and ends do not match
In this case we do naive method of fixing one char of a string and comparing with remaning chars of other string
so there are 2 cases that is 
fix Y and check for B
or fix A and check for X and A
we take maximum of whatever both the recursive calls gives as op 
i.e max( lcs(s1, s2, m-1, n), lcs(s1, s2, m, n-1))
i.e max( lcs("AX", "BA") , lcs("AXY", "B") )

Now what will be my base case
when one of the string reaches till start? i.e either m=0 or n=0 so output will be 0, since an empty string cannot have subsequnce of len > 0

Well we have our recusrive code ready
*/

int lcs_recursive(string s1, string s2, int m, int n)
{

    // base case
    if(m==0 || n==0)
        return 0;

    // if chars match: add 1 and recursively call for rem
    if(s1[m-1] == s2[n-1])
        return 1 + lcs_recursive(s1, s2, m - 1, n - 1);
    else 
        return max(lcs_recursive(s1, s2, m, n-1), lcs_recursive(s1, s2, m-1, n));
}

/*
Time for recusrive sol:
O(2^n)
*/
