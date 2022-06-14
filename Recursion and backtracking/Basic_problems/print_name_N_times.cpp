#include <iostream>
using namespace std;

void func(int i, int n)
{
    if(i>n)
        return;
    cout << "Shyren here\n";
    func(i + 1, n);
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