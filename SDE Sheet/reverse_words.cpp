#include <iostream>
using namespace std;

/*
link: https://leetcode.com/problems/reverse-words-in-a-string/
Approach: 
traverse from back:
print non-space chars 
we do this by maintaining left and left ptr
between left and left will be our word

Space: O(1)
Time: O(N)
*/

class Solution
{
public:
    string reverseWords(string s)
    {
        int left = s.length() - 1;
        string ans = "";
        while(left >= 0)
        {
            // in case the end has blank spaces
            while(left >= 0 && s[left] == ' ')
                --left;

            int right = left;
            // for handling blank spaces at the start of string
            
            if(left < 0)
                break;

            while(left >= 0 && s[left] != ' ')
                left--;

            // append to ans
            // for first time, don't append space
            if(ans.empty())
            {
                for (int i = left + 1; i <= right; i++)
                    ans += s[i];
            }
            else 
            {
                ans += " ";
                for (int i = left + 1; i <= right; i++)
                    ans += s[i];
            }
        }

        return ans;
    }
};