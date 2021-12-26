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

void reversestr(string &s, int n, int high)
{
    int low = 0;
    while (low < high)
    {
        int j = s[low];
        s[low] = s[high];
        s[high] = j;
        low++;
        high--;
    }

    // Time: O(n/2) => theta(n)
}

void solve(string &s, int n, int k)
{
    int j = 0;
    char ans[k];
    if (k%2!=0)
    {
        for (int i = k; i >= 1; i -= 2)
            ans[i - 1] = s[j++];
        
        for (int i = 2; i < k; i += 2)
            ans[i - 1] = s[j++];
    }    
    else
    {
        for (int i = k; i >= 2; i -= 2)
            ans[i - 1] = s[j++];
        for (int i = 1; i < k; i += 2)
            ans[i - 1] = s[j++];
    }

    out_arr(k, ans);
    for (int i = k; i < n; i++)
        cout << s[i];
    cout << "\n";
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        solve(s, n, k);
        // vector<int> arr(n);
        // in(n, arr);
        // op();
    }
    return 0;
}

