/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/contains-duplicate/
 *  Time: O(n)
 *  Space: O(n)
 * 
 * 
 *  Given an integer array nums, return true if any value
 *  appears at least twice in the array, and return false
 *  if every element is distinct.
 * 
 *  Examples:
 *  Input: nums = [1,2,3,1]
 *  Output: true
 * 
 *  Input: nums = [1,2,3,4]
 *  Output: false 
 * 
 *  Input: nums = [1,1,1,3,3,4,3,2,4,2]
 *  Output: true
 * 
 *  Constraints:
 *  1 <= nums.length <= 105
 * -109 <= nums[i] <= 109
 * 
*/

#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> uSet;

    for (int num : nums)
    {
        if (uSet.find(num) != uSet.end())
            return true;

        uSet.insert(num);
    }

    return false;
}

int main()
{
    vector<int> vec = {1, 2, 3, 4};

    std::cout << containsDuplicate(vec) << std::endl;

    return 0;
}