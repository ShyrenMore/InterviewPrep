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
        lli n, res = 0;
        cin >> n;
        vector<lli> arr(n), even, odd;
        in(n, arr);

        for (int i = 0; i < n; i++)
        {
            if (i & 1)
                odd.push_back(abs(arr[i]));
            else
                even.push_back(abs(arr[i]));
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        if (odd[odd.size() - 1] > even[0])
            swap(odd[odd.size() - 1], even[0]);

        for (auto x : even)
            res += x;
        for (auto x : odd)
            res -= x;

        op(res);
    }
    return 0;
}

/*
2
-4 10
2
10 -4

op: 6 for both
*/