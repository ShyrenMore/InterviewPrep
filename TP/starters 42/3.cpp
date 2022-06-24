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
        lli n, k;
        cin >> n >> k;
        // vector<lli> arr(n);
        // in(n, arr);

        lli ans = 0;
        for (int i = 0;; i++)
        {
            if(k >= (1<<i)*n)
            {
                ans += n;
                k -= (1<<i)*n;
            }
            else{
                lli mini = k / (1 << i);
                k = k - mini * (1 << i);
                ans += mini;

                if(k)
                {
                    k = (1 << i) - k;
                    for (int j = 0; j <= 30; j++)
                        if((1 << j) & k)
                            ans -= 1;
                    ans += 1;
                }
                break;
            }
        }
        op(ans);
    }
    return 0;
}