/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/reshape-the-matrix/
 *  Time: O(m * n)
 *  Space: O(m * n) but it's for the result matrix
 * 
 *  In MATLAB, there is a handy function called reshape which
 *  can reshape an m x n matrix into a new one with a different size
 *  r x c keeping its original data.
 * 
 *  You are given an m x n matrix mat and two integers r and c
 *  representing the number of rows and the number of columns of the
 *  wanted reshaped matrix.
 * 
 *  The reshaped matrix should be filled with all the elements
 *  of the original matrix in the same row-traversing order as they were.
 * 
 *  If the reshape operation with given parameters is possible and legal,
 *  output the new reshaped matrix; Otherwise, output the original matrix.
 * 
 * 
 *  Examples:
 *  Input: mat = [[1,2],[3,4]], r = 1, c = 4
 *  Output: [[1,2,3,4]]
 * 
 *  Input: mat = [[1,2],[3,4]], r = 2, c = 4
 *  Output: [[1,2],[3,4]]
 * 
 *   Constraints:
 *   m == mat.length
 *   n == mat[i].length
 *   1 <= m, n <= 100
 *   -1000 <= mat[i][j] <= 1000
 *   1 <= r, c <= 300
 *
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
