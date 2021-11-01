/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/merge-sorted-array/
 *  Time: O(m + n)
 *  Space: O(1)
 * 
*/

#include <vector>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1; 
    int j = n - 1;  
    int k = nums1.size() - 1;

    while (i > 0 && j > 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }

    while (j > 0)
        nums1[k--] = nums2[j--];
}
