/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/combinations/
 *  Time: O(C(n,k) * k) 
 *  Space: O()
 *
*/

#include <vector>

using namespace std;

class Solution
{

public:
    void rec(vector<vector<int>> &res, vector<int> comb, int s, int n, int k)
    {
        if (comb.size() == k)
        {
            res.push_back(comb);
            return;
        }

        if (s >= k)
            return;

        for (size_t i = s; i <= n; i++)
        {
            comb.push_back(i);
            rec(res, comb, i + 1, n, k);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;

        for (int i = 1; i <= n; i++)
        {
            rec(res, {i}, i + 1, n, k);
        }

        return res;
    }
};

int main()
{

    Solution sol;
    sol.combine(4, 3);

    return 0;
}