#include <iostream>
using namespace std;

bool isPalindrome(string s, int l, int n)
{
    if(s[l]!=s[n-l-1])
        return false;

    if(l>=n/2)
        return true;

    return isPalindrome(s, l + 1, n);
}

int main()
{
    string s = "MADAN";
    int n = s.length();
    if(isPalindrome(s, 0, n))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}