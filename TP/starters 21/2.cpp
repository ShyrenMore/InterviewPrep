#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb3(x, y, z) cout << #x << ": " << x << " ~ " << #y << ": " << y << " ~ " << #z << ": " << z << endl;
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

lli solve(vector<lli> &arr, lli n)
{
    lli ans = 0, pow = 1;
    for (int i = 0; i < 32; i++)
    {
        lli cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if(arr[j]&1)
                ++cnt;
            arr[j] /= 2;
        }

        if(cnt>1)
            ans += pow;

        pow *= 2;
    }

    return ans;
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
        vector<lli> arr(n);
        in(n, arr);
        op(solve(arr, n));
    }
    return 0;
}