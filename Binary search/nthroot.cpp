/*
given n and m, find nth root of m
eg:
n=2, m=4    op: 2, square root of 4
n=3, m=27    op: 3, cub root of 27
n=4, m=15   op: 1.96, 4th root of 15

Approach:
Binary search can be implemented in any search space which can be inc or dec
here the pattern is 1, 8, 27, ...

Then u need to figure out search space:
search space is nothing but where can your answer lie
the answer will lie b/w 1 and M
low = 1, high = M
mid = 1+27/2 = 14

14*14*14 >>> 27
i.e mid*mid*mid >>> M
so answer is b/w 1 and mid
new_mid = 1+14 / 2 = 7.5
again mid*mid*mid >>> M

mid = 1+7.5 / 2 = 4.25
again mid*mid*mid >>> M

mid = 1+4.25 / 2 = 2.625
here mid*mid*mid < M

so my answe is between or is in range
[2.625, 4.25]

new_mid = 3.4375
keep on shrinking the search size until
mid*mid*mid == M or high-low > 10^-6 i.e first 5 digits are same

Time: N*log(M*10^d)
since 1 to 2 contains 1.1, 1.2..2.0 i.e 10
and we run multiplier func for N times
*/

#include <iostream>
#include <math.h>
using namespace std;

double midMult(double num, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= num; i++)
        ans *= num;
    return ans;
}

double getNthroot(int n, int m)
{
    double low = 1, high = m, eps = 1e-6;
    while((high - low) > eps)
    {
        double mid = (low - high) / 2.0;
        if(midMult(mid, n) < m)
            low = mid;
        else
            high = mid;
    }

    int exp = (double)(1.0 / (double)n);
    return pow(m, exp);
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << getNthroot(n, m);
}