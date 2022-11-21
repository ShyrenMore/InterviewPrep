// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        
        maze[entrance[0]][entrance[1]] = '+';
        
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};
        queue<array<int, 3>> q;
        q.push({entrance[0], entrance[1], 0});
        
        while(!q.empty())
        {
            auto [r, c, currDistance] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + delta_row[i];
                int ncol = c + delta_col[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && (maze[nrow][ncol]=='.'))
                {
                    // extra check for land/aanything goes here
                    if((nrow == 0 || nrow == n-1 || ncol == 0 || ncol == m-1))
                        return (currDistance+1);
                    maze[nrow][ncol] = '+';
                    q.push({nrow, ncol, currDistance+1});
                }
            }
        }
        return -1;
    }
};
