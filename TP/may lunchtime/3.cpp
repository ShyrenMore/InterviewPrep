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
        lli n;
        cin >> n;
        vector<lli> arr(n);
        int cntOfZero = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x == 0)
                ++cntOfZero;

            arr[i] = x;
        }
        int helper = 0;
        int j = 0;
        for (; j < n-1; j++)
        {
            
            if((arr[j] & arr[j+1]) == 0 && arr[j+1]!=0)
            {
                ++helper;
                break;
            }
        }
        deb2(j, helper);
        if(n==2)
            op(0);
        else 
        {
            // deb2(n, cntOfZero);
            int balancezero = cntOfZero ? cntOfZero - 1 : 0;
            int ans = n - 2 - balancezero + helper;
            op(ans);
            // n-j
        }
    }
    return 0;
}