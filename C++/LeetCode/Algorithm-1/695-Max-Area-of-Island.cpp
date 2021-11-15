/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/max-area-of-island/
 *  Time: O(n * m) 
 *  Space: O(n * m)
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    static void dfsCalcArea(vector<vector<int>> &grid, int x, int y, int &area)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size())
        {
            return;
        }

        if (grid[x][y] == 0)
        {
            return;
        }

        grid[x][y] = 0;
        ++area;

        dfsCalcArea(grid, x, y + 1, area);
        dfsCalcArea(grid, x + 1, y, area);
        dfsCalcArea(grid, x - 1, y, area);
        dfsCalcArea(grid, x, y - 1, area);
    }

    static int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        const int ROWS = grid.size();
        const int COLS = grid[0].size();

        int maxArea = 0;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                {
                    int area = 0;
                    dfsCalcArea(grid, i, j, area);
                    maxArea = std::max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
