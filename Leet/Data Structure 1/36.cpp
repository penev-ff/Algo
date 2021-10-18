/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/valid-sudoku/ 
 *  Time: O(n^2)
 *  Space: O(1)
 *  
 *  Determine if a 9 x 9 Sudoku board is valid.
 *  Only the filled cells need to be validated according to the following rules:
 *  Each row must contain the digits 1-9 without repetition.
 *  Each column must contain the digits 1-9 without repetition.
 *  Each of the nine 3 x 3 sub-boxes of the grid must contain the
 *  digits 1-9 without repetition.
 *
 *  Note:
 *
 *  A Sudoku board (partially filled) could be valid but is
 *  not necessarily solvable.
 *  Only the filled cells need to be validated according to 
 *  the mentioned rules.
 *
 *  Examples:
 *  
 * Input: board = 
 *  [['5','3','.','.','7','.','.','.','.']
 *  ,['6','.','.','1','9','5','.','.','.']
 *  ,['.','9','8','.','.','.','.','6','.']
 *  ,['8','.','.','.','6','.','.','.','3']
 *  ,['4','.','.','8','.','3','.','.','1']
 *  ,['7','.','.','.','2','.','.','.','6']
 *  ,['.','6','.','.','.','.','2','8','.']
 *  ,['.','.','.','4','1','9','.','.','5']
 *  ,['.','.','.','.','8','.','.','7','9']]
 * 
 *  Output: true
 *  
 * Input: board = 
 *  [['8','3','.','.','7','.','.','.','.']
 *  ,['6','.','.','1','9','5','.','.','.']
 *  ,['.','9','8','.','.','.','.','6','.']
 *  ,['8','.','.','.','6','.','.','.','3']
 *  ,['4','.','.','8','.','3','.','.','1']
 *  ,['7','.','.','.','2','.','.','.','6']
 *  ,['.','6','.','.','.','.','2','8','.']
 *  ,['.','.','.','4','1','9','.','.','5']
 *  ,['.','.','.','.','8','.','.','7','9']]
 *  
 *  Output: false
 * 
 *  Explanation: Same as Example 1, except with the 5
 *  in the top left corner being modified to 8.
 *  Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 * 
 * 
 *  Constraints:
 * 
 *   board.length == 9
 *   board[i].length == 9
 *   board[i][j] is a digit 1-9 or '.'.
 *
*/

#include <vector>
#include <iostream>

using namespace std;

bool setBit(int num, int &bits)
{
    int mask = 1 << num;

    if (mask & bits)
        return true;

    bits |= mask;
    return false;
}

bool isValidSudoku(vector<vector<char>> &board)
{
    const size_t BOARD_SIZE = 81, SUBBOX_SIZE = 9;

    int subboxBitmask = 0x0, rowBitmask = 0x0, colBitmax = 0x0;

    int offset = 0;

    for (size_t i = 0; i < BOARD_SIZE; i++)
    {
        if (i % SUBBOX_SIZE == 0)
        {
            subboxBitmask = 0x0;
            rowBitmask = 0x0;
            colBitmax = 0x0;
        }

        if (i != 0 && i % 27 == 0)
            offset += 3;

        if (board[(i / 3) % 9][i % 3 + offset] != '.')
        {
            int cellvalue = board[(i / 3) % 9][i % 3 + offset] - '0';

            if (setBit(cellvalue, subboxBitmask))
                return false;
        }

        if (board[i / 9][i % 9] != '.')
        {
            int cellvalue = board[i / 9][i % 9] - '0';

            if (setBit(cellvalue, rowBitmask))
                return false;
        }

        if (board[i % 9][i / 9] != '.')
        {
            int cellvalue = board[i % 9][i / 9] - '0';

            if (setBit(cellvalue, colBitmax))
                return false;
        }
    }

    return true;
}

int main()
{

    vector<vector<char>> board = {
        {'5', '1', '5', '.', '5', '.', '.', '1', '.'},
        {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
        {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
        {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
        {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
        {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
        {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

    std::cout << isValidSudoku(board) << std::endl;

    return 0;
}
