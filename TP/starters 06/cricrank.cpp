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
        // int n;
        // cin >> n;
        // vector<int> arr(n);
        // in(n, arr);
        int r1, w1, c1, r2, w2, c2;
        cin >> r1 >> w1 >> c1 >> r2 >> w2 >> c2;
        int a = 0, b = 0;

        if(r1 > r2)
            a++;
        else
            b++;
        if(w1 > w2)
            a++;
        else
            b++;
        if(c1 > c2)
            a++;
        else
            b++;
        
        if(a>b)
            op('A');
        else
            op('B');
    }
    return 0;
}