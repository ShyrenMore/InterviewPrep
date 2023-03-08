// https://leetcode.com/problems/maximum-length-of-pair-chain/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int>lis(n, 0);
        lis[0] = 1;
        
        for(int i = 1; i < n; i++)
        {
            lis[i] = 1;
            for(int j = 0; j < i; j++)
                if(arr[j][1] < arr[i][0])
                    lis[i] = max(lis[i], lis[j]+1);
        }
        
        int res = lis[0];
        for(int i = 1; i < n; i++)
            res = max(res, lis[i]);
        return res;
    }
};
