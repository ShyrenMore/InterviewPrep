#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr(n, arr)         \
    for (int i = 0; i < n; i++) \
    cout << arr[i]
#define op(n) cout << n << "\n"
#define lli long long int
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;


// function returns unique prime factors
// eg: 30 has factors 2, 3, 5, 6, 10, 15, so function will return only 3 (2, 3, 5)
lli countUniquePrimeFactors(lli n)
{
    lli cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if(n%i==0)
        {
            ++cnt;
            // we don't want multiples of say 2 or 3..
            while(!(n%i))
                n /= i;
        }
    }

    // if n is prime
    if(n != 1)
        ++cnt;

    return cnt;
}

int main()
{

    // /*
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    // */
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        lli cnt = 0;
        
        while(n>0)
        {
            if(!(n&1))
            {
                ++cnt;
                n /= 2;
            }
            else
                break;
        }
        // vector<lli> arr(n);
        // in(n, arr);
        op(cnt);
    }
    return 0;
}