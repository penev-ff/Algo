#include <iostream>
#include <vector>

#include "TestSorted.hpp"

using namespace std;

void sift_down(vector<int> &arr, int n, int pos)
{
    int left_i = pos * 2 + 1;
    int right_i = pos * 2 + 2;
    int swap_i;

    while (left_i < n)
    {
        swap_i = pos;

        swap_i = arr[swap_i] > arr[left_i] ? swap_i : left_i;

        if (right_i < n)
        {
            swap_i = arr[swap_i] > arr[right_i] ? swap_i : right_i;
        }

        if (pos == swap_i)
        {
            break;
        }

        std::swap(arr[swap_i], arr[pos]);
        pos = swap_i;
        left_i = pos * 2 + 1;
        right_i = pos * 2 + 2;
    }
}

void build_heap(vector<int> &arr)
{
    // The parent of the last element (n-1) => p := (k - 1) / 2 => START = (n - 2) / 2
    const int START = (int)arr.size() - 2 / 2;
    for (int i = START; i >= 0; --i)
    {
        sift_down(arr, arr.size(), i);
    }
}

void heap_sort(vector<int> &arr)
{
    build_heap(arr);

    const int N = (int)arr.size();
    for (int i = N - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        sift_down(arr, i, 0);
    }
}

int main()
{

    sortTest(heap_sort);

    return 0;
}
