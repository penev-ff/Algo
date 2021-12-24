/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/single-number-iii/
 *  Time: O(n)
 *  Space: O(1)
 *
*/

#include <vector>

#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> singleNumberBitwise(vector<int> &nums)
{
    vector<int> answer = {0, 0};

    // Find the xor of the two different numbers
    int diff = 0;
    for (int num : nums)
    {
        diff = diff ^ num;
    }

    // Find the rightmost set bit in diff
    // A set bit in the diff means that this bit is set only in one
    // of the single numbers contained in the input array.
    int rightSetBit = diff & -diff;


    for (int num : nums)
    {
        if (num & rightSetBit)
        {
            answer[0] ^= num;
        }
        else
        {
            answer[1] ^= num;
        }
    }

    return answer;
}

// Could be done with set either
vector<int> singleNumberMap(vector<int> &nums)
{
    unordered_map<int, int> uMap;
    vector<int> answer;

    for (int num : nums)
    {
        ++uMap[num];
    }

    for (auto it = uMap.begin(); it != uMap.end(); ++it)
    {
        if (it->second == 1)
        {
            answer.push_back(it->first);

            if (answer.size() == 2)
                break;
        }
    }

    return answer;
}
