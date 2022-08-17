#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution
{

private:
    void dfs(int row, int col, vector<vector<int>> &image, int newColor, int delta_row[], int delta_col[], int initialColor)
    {
        int n = image.size();
        int m = image[0].size();

        image[row][col] = newColor;
        for (int i = 0; i < 4; i++)
        {
            int neighbour_row = row + delta_row[i];
            int neighbour_col = col + delta_col[i];

            // for each neighbour check boundary
            if (neighbour_row >= 0 && neighbour_row < n and neighbour_col >= 0 && neighbour_col < m)
            {
                // check for same color and prev visited
                if (image[neighbour_row][neighbour_col] == initialColor && image[neighbour_row][neighbour_col] != newColor)
                {
                    dfs(neighbour_row, neighbour_col, image, newColor, delta_row, delta_col, initialColor);
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initialColor = image[sr][sc];
        // visiting up, down, left, right
        int deltarow[] = {-1, 0, 1, 0};
        int deltacol[] = {0, 1, 0, -1};
        dfs(sr, sc, image, color, deltarow, deltacol, initialColor);
        return image;
    }
};