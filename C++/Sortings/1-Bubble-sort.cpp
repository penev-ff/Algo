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
void bubbleSortSimple(std::vector<T> &v)
{
    bool swapped;
    const size_t N = v.size();
    do
    {
        swapped = false;

        for (size_t i = 0; i < N - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);

                swapped = true;
            }
        }

    } while (swapped);
}

// Time Complexity: O(n^2)
template <typename T>
void bubbleSortV2(std::vector<T> &v)
{
    const int SIZE = v.size();
    for (size_t i = 0; i < SIZE - 1; i++)
    {
        for (size_t j = 0; j < SIZE - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{

    sortTest(bubbleSortSimple);
    sortTest(bubbleSortV2);

    return 0;
}