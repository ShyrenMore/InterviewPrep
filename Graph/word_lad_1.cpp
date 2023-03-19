class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        // Code here
        queue<pair<string, int>> q;     // word, level
        q.push({startWord, 1});
        
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        st.erase(startWord); // marking start as visited
        
        while(!q.empty())
        {
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(word == targetWord)
                return level;
            
            for(int i = 0; i < word.size(); i++)    // h,a,t
            {
                char og = word[i];
                for(char it = 'a'; it <= 'z'; it++) // ha, hb, hz..aa,ab,ac..
                {
                    word[i] = it;
                    if(st.find(word) != st.end())
                    {
                        st.erase(word);
                        q.push({word, level+1});
                    }
                }
                word[i] = og;
            }
        }
        
        return 0;
    }
};
