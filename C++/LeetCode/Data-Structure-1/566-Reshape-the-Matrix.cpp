/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reshape-the-matrix/
 *  Time: O(m * n)
 *  Space: O(m * n) but it's for the result matrix
 * 
*/

#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    if (mat.size() == 0)
        return mat;

    int m = mat.size();
    int n = mat[0].size();
    const int SIZE = m * n;

    if (r * c != SIZE)
        return mat;

    std::vector<std::vector<int>> reshaped(r, vector<int>(c));

    for (int i = 0; i < SIZE; ++i)
        reshaped[i / c][i % c] = mat[i / n][i % n];

    return reshaped;
}

int main()
{
    vector<vector<int>> matrix =
        {{1, 2, 3},
         {4, 5, 6}};

    matrixReshape(matrix, 3, 2);

    return 0;
}
