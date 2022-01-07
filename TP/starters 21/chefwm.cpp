#include <iostream>
using namespace std;

int getUniquePrimeCnt(int n)
{
    int cnt = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if(n%i==0)
        {
            ++cnt;
            while(!(n%i))
                n /= i;
        }
    }

    // if n is prime
    if (n != 1)
        ++cnt;

    return cnt;
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
    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int no_of_primes = getUniquePrimeCnt(m);

        while(no_of_primes>1)
        {
            if(n%no_of_primes==0)
                break;
            --no_of_primes;
        }

        cout << no_of_primes << "\n";
    }
}