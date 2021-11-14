/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/search-a-2d-matrix/
 *  Time: O(M + logN)
 *  Space: O()
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