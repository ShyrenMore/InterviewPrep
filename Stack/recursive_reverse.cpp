#include <iostream>
#include <stack>
using namespace std;

stack<int> s;

void fun(stack<int> &s)
{
    if (s.empty())
        return;
    int j = s.top();
    s.pop();
    fun(s);
    s.push(j);
}

int main()
{
    s.push(1);
    s.push(2);
    s.push(3);
    fun(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}