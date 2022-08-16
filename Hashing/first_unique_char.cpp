#include <iostream>
#include <unordered_map>
using namespace std;

/*
link: https://leetcode.com/problems/first-unique-character-in-a-string/
Approach: store count and index of every character into the hash table
Then traverse the hashtable and only look at els whose count == 1

edge case: if no unique char is present
In that case, initialise idx with len, 
after traversing the hashmap, if idx remains same this means there is no unique char, so return -1
*/

class Solution
{
public:
    int firstUniqChar(string s)
    {
        // for each char store (count, idx)
        unordered_map<char, pair<int, int>> m;

        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]].first++;    // increment count
            m[s[i]].second = i; // assign idx
        }

        int idx = s.size();
        for (auto p : m)
        {
           if (p.second.first == 1)
               idx = min(idx, p.second.second);
        }

        return idx == s.size() ? -1 : idx;
    }
};