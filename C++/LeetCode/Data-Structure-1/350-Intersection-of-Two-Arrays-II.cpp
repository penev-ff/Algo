/* 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 *  Time: O(m + n)
 *  Space: O(m) (It's better to initialize the map with min(m, n))
 *
*/

#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> uMap;
    vector<int> intersection;

    int n = nums1.size(), m = nums2.size();

    for (int i = 0; i < n; i++)
        ++uMap[nums1[i]];

    for (int i = 0; i < m; i++)
    {
        if (uMap.find(nums2[i]) != uMap.end())
        {
            if (uMap[nums2[i]] > 0)
                intersection.push_back(nums2[i]);

            --uMap[nums2[i]];
        }
    }

    return intersection;
}

int main()
{
    // Driver
    //

    // Input
    vector<int> nums1 = {4, 9, 5, 4}, nums2 = {9, 4, 9, 8, 4};

    // Function call
    vector<int> intersection = intersect(nums1, nums2);

    // Printing the result
    std::for_each(intersection.begin(),
                  intersection.end(),
                  [](int val)
                  { std::cout << val << ' '; });

    return 0;
}