/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/permutations/
 *  Time: O(N*N!) 
 *  Space: O(N!)
 *
*/

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> permutations;
        vector<int> current;
        backtrack(permutations, current, nums);

        return permutations;
    }

    void backtrack(vector<vector<int>> &permutations,
                   vector<int> &current,
                   vector<int> &nums)
    {
        if (nums.size() == current.size())
        {
            permutations.push_back(current);
        }
        else
        {
            for (int digit : nums)
            {
                if (find(current.begin(), current.end(), digit) != current.end())
                {
                    continue;
                }

                current.push_back(digit);

                backtrack(permutations, current, nums);

                current.pop_back();
            }
        }
    }
};
