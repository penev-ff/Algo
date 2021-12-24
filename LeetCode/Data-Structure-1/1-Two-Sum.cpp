/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/two-sum/
 *  Time: O(n)
 *  Space: O(n)
 *
*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> uMap;

    for (int i = 0; i < nums.size(); i++)
    {
        int toFind = target - nums[i];

        if (uMap.find(toFind) != uMap.end())
            return {i, uMap[toFind]};

        uMap.insert({nums[i], i});
    }

    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    vector<int> pair = twoSum(nums, 9);

    std::cout << pair[0] << ' ' << pair[1] << std::endl;

    return 0;
}