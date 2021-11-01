#include <vector>
#include <algorithm>

using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    std::sort(nums.end(), nums.begin());
    return nums[nums.size() - k];
}