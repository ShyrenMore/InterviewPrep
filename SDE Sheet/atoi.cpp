#include <iostream>
#define deb(x) cout << #x << ": " << x << endl;
#define deb2(x, y) cout << #x << ": " << x << " ~ " << #y << ": " << y << endl;
using namespace std;

/*
link: https://leetcode.com/problems/string-to-integer-atoi/
cases:
- if -, ans is -ve
- if str contains non-digit like a, v, c, ans is 0
- if str is out of bounds INT_MIN then return INT_MIN, same for INT_MAX

Time: O(N)
Space: O(1)
*/

class Solution
{
public:
    int myAtoi(string s)
    { 
        int idx = 0;
        while (idx < s.size() && s[idx] == ' ')
            ++idx;

        bool isNegative = false;
        long ans = 0;

        int MAX = INT_MAX, MIN = INT_MIN;
        if (s[idx] == '-')
        {
            isNegative = true; idx++;
        }
        else if(s[idx] == '+')
            ++idx;
        
        
        while (idx < s.length())
        {
            if (!isdigit(s[idx]))
                break;

            ans = ans * 10 + (s[idx] - '0');

            if (isNegative && -1 * ans < MIN)
                return (MIN);

            if (!isNegative && ans > MAX)
                return MAX;

            ++idx;
        }

        ans = isNegative ? ans * -1 : ans;
        return ans;
    }
};

int main()
{
    string s = "42";
    // cout << myAtoi(s);
    return 0;
}