#include <iostream>
using namespace std;

void f(int i, int fact)
{
    if(i < 1)
    {
        cout << fact << "\n";
        return;
    }

    f(i - 1, fact * i);
}

int main()
{
    int n;
    cin >> n;
    f(n, 1);
    return 0;
}