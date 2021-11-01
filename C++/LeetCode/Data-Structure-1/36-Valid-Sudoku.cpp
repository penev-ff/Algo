/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/valid-sudoku/ 
 *  Time: O(n^2)
 *  Space: O(1)
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
