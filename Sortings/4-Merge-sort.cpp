#include <iostream>
#include <vector>

#include "TestSorted.hpp"


// Time complexity: O(n Log n)
// Space complexity: O(n)
template <typename T>
void merge(std::vector<T> &v, int l, int m, int r)
{
    const size_t SIZE_LEFT = m - l + 1;
    const size_t SIZE_RIGHT = r - m;

    std::vector<int> leftSubarray(SIZE_LEFT);
    std::vector<int> rightSubarray(SIZE_RIGHT);

    for (size_t i = 0; i < SIZE_LEFT; i++)
        leftSubarray[i] = v[l + i];

    for (size_t i = 0; i < SIZE_RIGHT; i++)
        rightSubarray[i] = v[m + 1 + i];

    // Merging
    size_t i = 0, j = 0, k = l;
    while (i < SIZE_LEFT && j < SIZE_RIGHT)
    {
        if (leftSubarray[i] < rightSubarray[j])
        {
            v[k] = leftSubarray[i];
            ++i;
        }
        else
        {
            v[k] = rightSubarray[j];
            ++j;
        }

        ++k;
    }

    while (i < SIZE_LEFT)
    {
        v[k++] = leftSubarray[i++];
    }

    while (j < SIZE_RIGHT)
    {
        v[k++] = rightSubarray[j++];
    }
}

template <typename T>
void mergeSortRec(std::vector<T> &v, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSortRec(v, l, m);
        mergeSortRec(v, m + 1, r);

        merge(v, l, m, r);
    }
}

template <typename T>
void mergeSort(std::vector<T> &v)
{
    mergeSortRec(v, 0, v.size() - 1);
}

int main()
{

    sortTest(mergeSort);

    return 0;
}