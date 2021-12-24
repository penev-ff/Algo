#include <iostream>
#include <vector>

#include "TestSorted.hpp"

template <typename T>
void swap(T &lhs, T &rhs)
{
    T temp = lhs;
    lhs = rhs;
    rhs = temp;
}

// Time Complexity: O(n^2)
template <typename T>
void insertionSort(std::vector<T> &v)
{
    const size_t SIZE = v.size();
    int j;
    for (size_t i = 1; i < SIZE; i++)
    {
        j = i;
        while (j > 0 && v[j] < v[j - 1])
        {
            swap(v[j], v[j - 1]);
            --j;
        }
    }
}

int main()
{

    sortTest(insertionSort);

    return 0;
}

