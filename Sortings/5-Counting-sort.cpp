#include <iostream>
#include <vector>

#include "TestSorted.hpp"

// Time Complexity: O(n + k)
// Space Complexity: O(n + k)
template <typename T>
void countingSort(std::vector<T> &input)
{
    const size_t n = input.size();

    // Could be passed as parameter with input;
    int k = 1 << 31;

    // Additional loop to find the max element ~ k
    // The range would be [0, k]
    for (int el : input)
    {
        if (el > k)
            k = el;
    }

    std::vector<int> histogram(k + 1);

    for (size_t i = 0; i < n; ++i)
    {
        ++histogram[input[i]];
    }

    // Converting to cumulative frequency histogram
    for (size_t i = 1; i <= k; i++)
    {
        histogram[i] += histogram[i - 1];
    }

    std::vector<int> output(n);
    for (int i = n - 1; i >= 0; --i)
    {
        output[histogram[input[i]] - 1] = input[i];
        --histogram[input[i]];
    }

    input = output;
}

// Working with non-negative values for the input array
void testCountingSort()
{
    std::vector<int> v = {5, 1, 30, 2, 3, 6, 0, 10, 20};

    std::cout << "UNSORTED: " << '\n';
    for_each(v.begin(), v.end(), [](int v)
             { std::cout << v << ' '; });

    countingSort(v);

    std::cout << std::endl;

    std::cout << "SORTED" << '\n';
    for_each(v.begin(), v.end(), [](int v)
             { std::cout << v << ' '; });

    std::cout << std::endl;
}

int main()
{
    // NOTE.
    // This version of counting sort is working only with
    // positive input values that could represent indices.
    // To use sortTest - edit the LOWER_BOUND to a non-negative number.

    sortTest(countingSort);

    // testCountingSort();

    return 0;
}
