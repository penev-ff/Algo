/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/maximum-subarray/
 *  Time: O(n)
 *  Space: O(1)
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