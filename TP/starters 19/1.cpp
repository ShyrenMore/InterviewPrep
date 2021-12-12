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
        int n;
        cin >> n;
        // at odd indices place even
        // at even place odd
        vector<int> ans(n+1, -1);
        int even = 2, odd = 1, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if(i&1)
            {
                
                ans[i] = even;
                even = even + 2;
                // ++cnt;
            }
            else
            {
                
                ans[i] = odd;
                odd += 2;
                // ++cnt;
            }
        }

        if(n%2==0)
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
        else 
        {
            // swap(ans[n], ans[n - 2]);
            ans[n] = ans[n-2];
            ans[n - 2] = n;
            for (int i = 1; i <= n; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
        
    }
    return 0;
}