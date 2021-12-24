/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/rotate-array/
 *  Time: O(N)
 *  Space: rotateInPlace: O(1); rotate: O(N); 
 *
*/

#include <vector>

using namespace std;

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end) {
            std::swap(nums[start++], nums[end--]);
        }
    }

    void rotateInPlace(vector<int> &nums, int k)
    {
        if (k == 0 || nums.size() <= 1)
        {
            return;
        }

        int modk = k % nums.size();

        if (modk == 0)
        {
            return;
        }

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, modk - 1);
        reverse(nums, modk, nums.size() - 1);
    }

    void rotate(vector<int> &nums, int k)
    {
        if (k == 0 || nums.size() <= 1)
        {
            return;
        }

        int modk = k % nums.size();

        if (modk == 0)
        {
            return;
        }

        vector<int> rotated(nums.size());

        for (size_t i = 0; i < k; i++)
        {
            rotated[i] = nums[nums.size() - k + i];
        }

        for (size_t i = k; i < rotated.size(); i++)
        {
            rotated[i] = nums[i - k];
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            nums[i] = rotated[i];
        }
    }
};
