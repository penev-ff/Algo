#include <vector>

#include "TestSorted.hpp"

// Time complexity: O(n^2) for choosing bad pivot,
// O(nLogn) if the selected pivot is good.
// Space complexity: O(1)

template <typename T>
int partition(std::vector<T> &v, int l, int r)
{
    int pivot = v[r];
    int wr = l;

    for (size_t i = l; i < r; i++)
    {
        if (pivot > v[i])
        {
            std::swap(v[wr], v[i]);
            ++wr;
        }
    }

    std::swap(v[r], v[wr]);
    return wr;
}

template <typename T>
void quickSortRec(std::vector<T> &v, int l, int r)
{
    if (l < r)
    {
        int pivot = partition(v, l, r);

        quickSortRec(v, l, pivot - 1);
        quickSortRec(v, pivot + 1, r);
    }
}

// Realtional operator of T must be defined
template <typename T>
void quickSort(std::vector<T> &v)
{
    quickSortRec(v, 0, v.size() - 1);
}

int main()
{

    sortTest(quickSort);

    return 0;
}