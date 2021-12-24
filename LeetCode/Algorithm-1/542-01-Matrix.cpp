/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/01-matrix/
 *  Time: O(M * N) 
 *  Space: O(1)
 *
*/

#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
    static const int INF = (int)1E6;
    static const int DIRS = 4;
    const int D_X[DIRS] = {1, 0, -1, 0};
    const int D_Y[DIRS] = {0, 1, 0, -1};

public:
    vector<vector<int>> updateMatrixDP(vector<vector<int>> &mat)
    {
        const int ROWS = (int)mat.size();
        const int COLS = (int)mat[0].size();

        for (int row = 0; row < ROWS; row++)
        {
            for (int col = 0; col < COLS; col++)
            {
                if (mat[row][col] == 0)
                    continue;

                int top = INF, left = INF;

                if (row - 1 >= 0)
                {
                    top = mat[row - 1][col];
                }

                if (col - 1 >= 0)
                {
                    left = mat[row][col - 1];
                }

                mat[row][col] = min(top, left) + 1;
            }
        }

        for (int row = ROWS - 1; row >= 0; row--)
        {
            for (int col = COLS - 1; col >= COLS; col--)
            {
                if (mat[row][col] == 0)
                    continue;

                int bot = INF, right = INF;

                if (row + 1 < ROWS)
                {
                    bot = mat[row + 1][col];
                }

                if (col + 1 < COLS)
                {
                    right = mat[row][col + 1];
                }

                mat[row][col] = min(mat[row][col], min(bot, right) + 1);
            }
        }

        return mat;
    }

    vector<vector<int>> updateMatrixDFS(vector<vector<int>> &mat)
    {
        const int ROWS = (int)mat.size();
        const int COLS = (int)mat[0].size();

        queue<pair<int, int>> wave;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                if (mat[i][j] == 0)
                {
                    wave.push({i, j});
                }
                else
                {
                    mat[i][j] = -1; // Not Processed
                }
            }
        }

        while (!wave.empty())
        {
            pair<int, int> toProcess = wave.front();
            wave.pop();

            int x = toProcess.first;
            int y = toProcess.second;

            for (int i = 0; i < DIRS; i++)
            {
                int n_x = x + D_X[i];
                int n_y = y + D_Y[i];

                if (n_x < 0 || n_x >= ROWS || n_y < 0 || n_y >= COLS)
                {
                    continue;
                }

                if (mat[n_x][n_y] != -1)
                {
                    continue;
                }

                wave.push({n_x, n_y});
                mat[n_x][n_y] = mat[x][y] + 1;
            }
        }

        return mat;
    }
};
