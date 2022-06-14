#include <iostream>
using namespace std;

/*
0+3 i = 3
3+2 i = 2
5+1 i = 1
i<1: print sum and return
*/

void func(int i, int sum)
{
    if(i < 1)
    {
        cout << sum << "\n";
        return;
    }

    func(i - 1, sum + i);
}

int main()
{
    int n;
    cin >> n;
    int initial_sum = 0;
    func(n, initial_sum);
    return 0;
}