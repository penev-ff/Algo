/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/rotting-oranges/
 *  Time: O(V + E) 
 *  Space: O(1)
 *
*/

#include <vector>
#include <queue>
#include <utility>

using namespace std;

using pii = pair<int, int>;

class Solution
{
    enum CELL
    {
        EMPTY,
        FRESH,
        ROTTEN
    };

    static const int DIRS = 4;
    const int D_X[DIRS] = {1, -1, 0, 0};
    const int D_Y[DIRS] = {0, 0, 1, -1};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return -1;

        const int N = grid.size();
        const int M = grid[0].size();

        int totalFresh = 0;
        queue<pii> q;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == ROTTEN)
                {
                    q.push({i, j});
                }

                if (grid[i][j] == FRESH)
                {
                    ++totalFresh;
                }
            }
        }

        if (totalFresh == 0)
            return 0;

        int minutes = 0;

        while (!q.empty() && totalFresh)
        {
            int toProcess = q.size();
            for (int i = 0; i < toProcess; i++)
            {
                pii front = q.front();
                int x = front.first;
                int y = front.second;

                q.pop();

                for (int i = 0; i < DIRS; i++)
                {
                    int n_x = x + D_X[i];
                    int n_y = y + D_Y[i];

                    if (n_x < 0 || n_y < 0 ||
                        n_x >= N || n_y >= M)
                    {
                        continue;
                    }

                    if (grid[n_x][n_y] == ROTTEN ||
                        grid[n_x][n_y] == EMPTY)
                    {
                        continue;
                    }

                    grid[n_x][n_y] = ROTTEN;
                    --totalFresh;
                    q.push({n_x, n_y});
                }
            }

            ++minutes;
        }

        return totalFresh ? -1 : minutes;
    }
};
