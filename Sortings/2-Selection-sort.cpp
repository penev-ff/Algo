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
void selectionSort(std::vector<T> &v)
{
    size_t n = v.size();

    for (size_t i = 0; i < n - 1; i++)
    {
        int min_i = i;

        for (size_t j = i + 1; j < n; j++)
        {
            if (v[j] < v[min_i])
            {
                min_i = j;
            }
        }

        if (min_i != i)
            swap(v[i], v[min_i]);
    }
}

int main()
{

    sortTest(selectionSort);

    return 0;
}