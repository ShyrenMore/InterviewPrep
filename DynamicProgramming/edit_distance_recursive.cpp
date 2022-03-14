#include <iostream>
using namespace std;

/*

Similar to LCS
begin from last character since we will be using recursion

if last two chars match, do nothing and make recursive call for m-1 and n-1 where m is len of s1 and n is len of s2

if last chars don't match,
You try three possibilities
say
s1 = "SATURDAY"
s2 = "SUNDAY"
we have
s1 = "SATUR"
and s2 = "SUN"

1) inserting char N to s1
result will be
s1 = "SATURN"
s2 = "SUN"
i.e insert second strings last char is processed and inserted into s1
after insertion:
s1 = "SATURN"
s2 = "SUN"

since both chars are matching, ignore
hence recursive call happens for m, n-1

2) delete R
s1 = "SATU"
s2 = "SUN"
hence recursive call happens for m-1, n

3) Replace R with N
s1 = "SATUN"
s2 = "SUN"
ignore since chars are matching
hence recursive call happens for m-1, n-1

we take the min of these three operations

we need to add 1 to result while returning, 
since in all the above three cases we are doing one operation

base cases:
if first string is empty, return n, 
since we need to do n insertions 
to convert s1=s2

if second string is empty, return m,
since we need to convert s1 to s2, 
hence delete all chars of m
so m deletions 

*/

int editDistance(string s1, string s2, int m, int n)
{
    // if s1="" s2="XYZ" so 3 insertions
    if(m==0)
        return n;
    
    // if s1="XYZ" s2="" so 3 deletions
    if(n==0)
        return m;

    // if s1="N" s2="N"
    // so return values of child call
    if(s1[m-1] == s2[n-1])
        return editDistance(s1, s2, m - 1, n - 1);
    else
    /*
    insert: editDistance(s1, s2, m, n - 1)
    delete: editDistance(s1, s2, m - 1, n)
    replace: editDistance(s1, s2, m - 1, n - 1)
    */
        return 1 + min(min(editDistance(s1, s2, m, n - 1), editDistance(s1, s2, m - 1, n)), editDistance(s1, s2, m - 1, n - 1));
}

int main()
{
    string s1 = "SATURDAY", s2="SUNDAY";
    cout << editDistance(s1, s2, s1.length(), s2.length());
    return 0;
}
