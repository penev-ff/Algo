/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/contains-duplicate/
 *  Time: O(n)
 *  Space: O(n)
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