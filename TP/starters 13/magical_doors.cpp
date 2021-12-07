#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out(n, arr)             \
    for (int i = 0; i < n; i++) \
    cout << arr[i]
#define lli long long int
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

using namespace std;

string makeFlip(string &s)
{
    int i = 0;
    while (i<s.length())
    {
        s[i] = s[i]=='0' ? '1' : '0';
        i++;
    }
    return s;
}
lli ans(string &s)
{
    int i = 0, flips=0;
    while (i < s.length())
    {
        if(s[i] == '1')
            ++i;
        else 
        {
            makeFlip(s);
            ++flips;
            i++;
        }
    }
    return flips;
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
        string s;
        cin >> s;
        cout << ans(s)<<"\n";
        // cout << makeFlip(s) << "\n";
    }
    return 0;
}