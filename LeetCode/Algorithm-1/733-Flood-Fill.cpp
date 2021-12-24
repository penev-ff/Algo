/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/flood-fill/
 *  Time: O(m * n) 
 *  Space: O(m * n)
 *
*/

#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    struct Pixel
    {
        int x, y;

        Pixel(int x, int y)
            : x(x), y(y) {}
    };

    // Breadth-First Search approach
    static vector<vector<int>> floodFillBFS(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];

        if (oldColor == newColor)
        {
            return image;
        }

        vector<vector<int>> filled = image;

        const int MAX_X = filled.size();
        const int MAX_Y = filled[0].size();

        queue<Pixel> wave;
        wave.push({sr, sc});

        while (!wave.empty())
        {
            Pixel toProcess = wave.front();
            wave.pop();

            int x = toProcess.x;
            int y = toProcess.y;

            filled[x][y] = newColor;

            if (x + 1 < MAX_X && filled[x + 1][y] == oldColor)
            {
                wave.push({x + 1, y});
            }

            if (x - 1 >= 0 && filled[x - 1][y] == oldColor)
            {
                wave.push({x - 1, y});
            }

            if (y + 1 < MAX_Y && filled[x][y + 1] == oldColor)
            {
                wave.push({x, y + 1});
            }

            if (y - 1 >= 0 && filled[x][y - 1] == oldColor)
            {
                wave.push({x, y - 1});
            }
        }

        return filled;
    }

    int MAX_X;
    int MAX_Y;
    int OLD_COLOR;
    int NEW_COLOR;

    void fillDFS(vector<vector<int>> &filled, int x, int y)
    {
        filled[x][y] = NEW_COLOR;

        if (x + 1 < MAX_X && filled[x + 1][y] == OLD_COLOR)
        {
            fillDFS(filled, x + 1, y);
        }

        if (x - 1 >= 0 && filled[x - 1][y] == OLD_COLOR)
        {
            fillDFS(filled, x - 1, y);
        }

        if (y + 1 < MAX_Y && filled[x][y + 1] == OLD_COLOR)
        {
            fillDFS(filled, x, y + 1);
        }

        if (y - 1 >= 0 && filled[x][y - 1] == OLD_COLOR)
        {
            fillDFS(filled, x, y - 1);
        }
    }

    // Depth-First Search approach
    vector<vector<int>> floodFillDFS(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        OLD_COLOR = image[sr][sc];
        NEW_COLOR = newColor;

        if (OLD_COLOR == NEW_COLOR)
        {
            return image;
        }

        vector<vector<int>> filled = image;

        MAX_X = filled.size();
        MAX_Y = filled[0].size();

        int x = sr, y = sc;

        fillDFS(filled, x, y);

        return filled;
    }
};