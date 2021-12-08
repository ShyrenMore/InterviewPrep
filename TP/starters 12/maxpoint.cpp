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
        int A, B, C, X, Y, Z;
        cin >> A >> B >> C >> X >> Y >> Z;

        int ans = 0;

        for (int take_a = 0; take_a <= 20; take_a++)
        {
            for (int take_b = 0; take_b <= 20; take_b++)
            {
                for (int take_c = 0; take_c <= 20; take_c++)
                {
                    int time = take_a * A + take_b * B + take_c * C;
                    if (time <= 240)
                    {
                        ans = max(ans, take_a * X + take_b * Y + take_c * Z);
                    }
                }
            }
        }

        cout << ans << "\n";
    }
    return 0;
}