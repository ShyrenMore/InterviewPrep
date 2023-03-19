/*
GFG link: https://practice.geeksforgeeks.org/problems/word-ladder-ii/1
Video: https://youtu.be/DREutrv2XD0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        // code here
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        
        // no of list of strings in queue belonging to same level
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        
        while(!q.empty())
        {
            vector<string> curr = q.front();
            q.pop();
            // erase all word that have been
            // used in the prev levels to transform
            if(curr.size() > level)
            {
                ++level;
                for(auto it: usedOnLevel)
                    st.erase(it);
                usedOnLevel.clear();
            }
            
            string word = curr.back();
            
            if(word == endWord)
                ans.push_back(curr);
                
            
            for(int i = 0; i < word.size(); i++)    // h,a,t
            {
                char og = word[i];
                for(char it = 'a'; it <= 'z'; it++) // ha, hb, hz..aa,ab,ac..
                {
                    word[i] = it;
                    if(st.find(word) != st.end())
                    {
                        curr.push_back(word);
                        
                        q.push(curr);
                        usedOnLevel.push_back(word);
                        
                        curr.pop_back();
                    }
                }
                word[i] = og;
            }
        }
        
        return ans;
    }
};
