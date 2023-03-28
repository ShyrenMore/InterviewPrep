/*
GFG link: https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
Editorial link: https://takeuforward.org/data-structure/distinct-subsequences-dp-32/
Video link: https://youtu.be/nVG7eTiD2bY
*/

class Solution{
public:
    int f(int i, int j, string S1, string S2)
    {
        if(j < 0)
            return 1;
        if(i < 0)
            return 0;
        if(S1[i] == S2[j])
            return f(i-1,j-1, S1, S2) + f(i-1, j, S1, S2);
        
        return f(i-1, j, S1, S2);
    }
    int countWays(string S1, string S2){
        // code here
        int n = S1.size();
        int m = S2.size();
        return f(n-1, m-1, S1, S2);
    }
};
