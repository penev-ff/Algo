/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/search-a-2d-matrix/
 *  Time: O(M + logN)
 *  Space: O()
 * 
 *  Write an efficient algorithm that searches for a value
 *  in an m x n matrix. 
 *  This matrix has the following properties:
 *      Integers in each row are sorted from left to right.
 *      The first integer of each row is greater than the last integer of the previous row.
 *
 *  Examples:
 *  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 *  Output: true
 * 
 *  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 *  Output: false
 * 
 *  Constraints:
 *
 *  m == matrix.length
 *  n == matrix[i].length
 *  1 <= m, n <= 100
 *  -104 <= matrix[i][j], target <= 104
 *
*/

#include <vector>

using namespace std;

bool binarySearchRec(const std::vector<int> &array, int target, int l, int r)
{
    if (l > r)
        return false;

    int mid = l + (r - l) / 2;

    if (array[mid] == target)
        return true;

    if (array[mid] < target)
    {
        return binarySearchRec(array, target, mid + 1, r);
    }

    return binarySearchRec(array, target, l, mid - 1);
}

bool binarySearch(const std::vector<int> &array, int target)
{
    return binarySearchRec(array, target, 0, array.size() - 1);
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // Validation of the size
    if ((matrix.size() == 0) || (matrix[0].size() == 0))
        return false;

    // O(M), M := matrix rows
    for (int row = 0; row < matrix.size(); ++row)
    {
        // Check if the target belongs to any row
        bool belongsToRow = matrix[row][0] <= target && matrix[row][matrix[0].size() - 1] >= target;
        if (belongsToRow)
        {
            // O(logN), N := matrix cols
            // Perform binary search of the selected row
            return binarySearch(matrix[row], target);
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> m = {{1, 3}};
    searchMatrix(m, 3);

    return 0;
}