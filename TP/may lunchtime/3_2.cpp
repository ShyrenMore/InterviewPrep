#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
#define in(n, arr)              \
    for (int i = 0; i < n; i++) \
    cin >> arr[i]
#define out_arr(n, arr)         \
    for (int i = 0; i < n; i++) \
    cout << arr[i] << " "
#define op(n) cout << n << "\n"
#define lli long long int
#define here cout << "\nHERE\n"
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;

bool check(const int a[], int n)
{
    return !std::all_of(a, a + n, [a](int x)
                        { return x == a[0]; });
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

        int cnt = 0;

        while (!equal(arr.begin() + 1, arr.end(), arr.begin()))
            for (int i = 0; i < arr.size() - 1; i++)
            {
                if ((arr[i] & arr[i + 1]) == 0 && arr[i + 1] != 0)
                {
                    // cout << "JETE";
                    arr[i] = 0;
                    auto itr = arr.begin() + i + 1;
                    arr.erase(itr);
                    ++cnt;
                }

                // out_arr(arr.size(), arr);
                // cout << "\n";
            }
        
        op(cnt);
    }
    return 0;
}