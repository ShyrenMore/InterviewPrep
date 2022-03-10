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
const lli INF = 1e9 + 7;
using namespace std;

/*
4 comps 2 eq
comps = [5, 10, 12, 2]

4 lines for eq

eq1
1 2 
a1 gives out 2
3 2 4 3
a1 = 3a2+4a3

eq2
3 1
a3 give only 1 item
a3 = 2a4
*/

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

    // int t;
    // cin >> t;
    // while (t--)
    // {
        lli n, m;
        cin >> n >> m;
        vector<lli> arr(n);
        in(n, arr);
        // op();

        while(m--)
        {
            lli comp_no, items;
            cin >> comp_no >> items;
            lli len = 2 * items;
            vector<lli> actual_eq(len);
            for (int i = 0; i < 2 * items; i++)
                cin >> actual_eq[i];

            lli temp = arr[comp_no - 1];
            arr[comp_no - 1] = 0;
            for (int i = 0; i < actual_eq.size() - 1; i += 2)
            {
                arr[actual_eq[i + 1] - 1] = (arr[actual_eq[i + 1] - 1] + temp * actual_eq[i]) % INF;
            }
        }

        for (auto x : arr)
            op(x);
    // }
    return 0;
}