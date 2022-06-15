#include <iostream>
using namespace std;

/*
for finding f(n),
we have to find f(n-1) and f(n-2)

f(n-1) and f(n-2) do not occur simultaneously

first all the recursive calls for f(n-1) takes place
and then all calls for f(n-2)
i.e
if n=3
f(3), f(2), f(1)
now f(1) returns 1 and we backtrack to f(2)
f(2) has 1 + f(0)
now f(0) will be called

so f(2) will return 1+1

now backtracking to f(3) we have 2 + f(2)

and so on
..

Time: ~ O(2^n)
*/

int f(int n)
{
    if(n <= 1)
        return n;

    return f(n - 1) + f(n - 2);

    /*
    or
    int last = f(n-1)
    int second_last = f(n-2)
    return last+second_last
    */
}

int main()
{
    int n;
    cin >> n;
    cout << f(n);
    return 0;
}