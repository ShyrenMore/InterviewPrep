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

int isPossible(int N, int M, vector<long long> A)
{
    int cnt = 0;
    // (n-3) rd el tak

    if(A[0] == A[1] && A.size()==2)
        return 0;
    
    if(A[0] == A[1] == A[2])
        return 0;
    
    for (int i = 1; i < N-2; i++)
    {
        if(cnt>M)
            break;

        if(A[i] == 0)
            continue;
    
        if(A[i] >= A[i+1])
        {
            int temp_sum = A[i] + A[i + 1] + A[i + 2];
            A[i] = temp_sum;
            A[i + 1] = 0;
            A[i + 2] = 0;
            ++cnt;
        }
    }



    // check if arr has become sorted
    bool isSorted = true;
    vector<long long> res;
    for(auto x: A)
        if(x!=0)
            res.push_back(x);

    cout << "Arr after operations: \n";
    out_arr(res.size(), res);
    cout << "\n";

    for (int i = 0; i < N-1; i++)
    {
        if(res[i] > res[i+1])
        {
            isSorted = false;
            break;
        }
    }

    return isSorted;
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
        int n, m;
        cin >> n >> m;
        vector<long long> arr(n);
        in(n, arr);

        op(isPossible(n, m, arr));
        cout << "\n";
    }
    return 0;
}