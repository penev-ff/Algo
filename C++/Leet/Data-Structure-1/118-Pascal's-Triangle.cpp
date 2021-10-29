/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/pascals-triangle/
 *  Time: O(n^2)
 *  Space: O(n^2)
 *  
 * Given an integer numRows, return the first numRows of Pascal's triangle.
 * In Pascal's triangle, each number is the sum of the two numbers
 * 
 *  Examples:
 *
 * Input: numRows = 5
 * Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
 * 
 * Input: numRows = 1
 * Output: [[1]]
 * 
 *  Constraints:
 * 1 <= numRows <= 30
*/

#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> pascalTriangle(numRows);

    for (size_t row = 0; row < numRows; ++row)
    {
        pascalTriangle[row] = std::vector<int>(row + 1);

        for (size_t col = 0; col < row + 1; ++col)
        {
            if (col == 0 || col == row)
                pascalTriangle[row][col] = 1;
            else
                pascalTriangle[row][col] = pascalTriangle[row - 1][col - 1] + pascalTriangle[row - 1][col];
        }
    }

    return pascalTriangle;
}

int main () {

    // Driver - test generate()
    std::vector<std::vector<int>> output1 = generate(1);
    std::vector<std::vector<int>> output2 = generate(2);
    std::vector<std::vector<int>> output3 = generate(3);
    std::vector<std::vector<int>> output4 = generate(4);
    


}