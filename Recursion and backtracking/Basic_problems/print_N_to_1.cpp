#include <iostream>
using namespace std;

void func(int i, int n)
{
    if (i > n)
        return;
    cout << n <<"\n";
    func(i, n-1);
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
Space: O(n-1), nth case is base case, that will not be in stack
*/