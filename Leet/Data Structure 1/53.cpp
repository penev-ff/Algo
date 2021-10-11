/**
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/maximum-subarray/
 *  Time: O(n)
 *  Space: O(1)
 * 
 *  Given an integer array nums, find the contiguous subarray
 *  (containing at least one number) which has the largest sum
 *  and return its sum.
 *  A subarray is a contiguous part of an array.
 * 
 *  Examples:
 *  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 *  Output: 6
 *  Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 *  Input: nums = [1]
 *  Output: 1 
 * 
 *  Input: nums = [5,4,-1,7,8]
 *  Output: 23
 * 
 *  Constraints:
 *  1 <= nums.length <= 105
 *  -104 <= nums[i] <= 104
 * 
*/

#include <vector>
#include <iostream>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int maxSum = 1 << 31, currentSum = 0;
    
    for (int num : nums)
    {
        currentSum += num;
        currentSum = max(num, currentSum);

        maxSum = max(currentSum, maxSum);
    }

    return maxSum;
}

int main()
{
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << maxSubArray(vec) << endl;

    return 0;
}