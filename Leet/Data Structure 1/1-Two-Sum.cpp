/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/two-sum/
 *  Time: O(n)
 *  Space: O(n)
 * 
 *  Given an array of integers nums and an integer target, 
 *  return indices of the two numbers such that they add up to target.
 *  You may assume that each input would have exactly one solution, 
 *  and you may not use the same element twice.
 * 
 *  You can return the answer in any order.
 * 
 *  Examples:
 *  Input: nums = [2,7,11,15], target = 9
 *  Output: [0,1]
 *  Output: Because nums[0] + nums[1] == 9, we return [0, 1].
 * 
 *  Input: nums = [3,2,4], target = 6
 *  Output: [1,2]
 * 
 *  Input: nums = [3,3], target = 6
 *  Output: [0,1]
 * 
 *  Constraints:
 *  
 *  2 <= nums.length <= 104
 *  -109 <= nums[i] <= 109
 *  -109 <= target <= 109
 *  Only one valid answer exists.
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