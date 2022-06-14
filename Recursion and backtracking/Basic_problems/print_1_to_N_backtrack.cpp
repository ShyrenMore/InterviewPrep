#include <iostream>
using namespace std;

/*
by placing the print statement after func call
we made sure the first recusrive func that gets executed is
func(1, 3)
*/

void func(int i, int n)
{
    if (i < 1)
        return;
    func(i + 1, n);
    cout << i << "\n";
}

int main()
{
    int n;
    cin >> n;
    func(1, n);
    return 0;
}

/*
Time: O(n) time
Space: O(n-1)
*/