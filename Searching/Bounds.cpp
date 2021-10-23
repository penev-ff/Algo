/**
 * @file Bounds.cpp
 *
 * @brief Implementation of lower_bound and upper_bound for searching in sorted vectors.
 *
 * @author Ivan Penev
 *
 */

#include <vector>
#include <cassert>
#include <algorithm>

// Returns an index of the first element in v
// which does not compare less than x.
template <typename T>
int lower_bound(const std::vector<T> &v, const int x)
{
    int l = 0, r = (int)v.size();
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (x <= v[mid])
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

// Returns an index of the first element in v
// which compare greater than x.
template <typename T>
int upper_bound(const std::vector<T> &v, const int x)
{
    int l = 0, r = (int)v.size();
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (x >= v[mid])
            l = mid + 1;
        else
            r = mid;
    }

    return l;
}

// Test utility to generate vector v of SIZE random integers
int generate(std::vector<int> &v, const int SIZE)
{
    for (size_t i = 0; i < SIZE; i++)
        v[i] = rand();

    return v[rand() % SIZE];
}

// Test utility for lower_bound
void testLowerBound()
{
    const int TESTS = 100;
    const int SIZE = 100;

    for (int i = 0; i < TESTS; i++)
    {
        std::vector<int> arr(SIZE);
        int x = generate(arr, SIZE);
        std::sort(arr.begin(), arr.end());

        auto stlLower = std::lower_bound(arr.begin(), arr.end(), x);
        int myLower = lower_bound(arr, x);

        if (stlLower == arr.end())
            assert(myLower == arr.size());
        else
            assert(stlLower - arr.begin() == myLower);
    }
}

// Test utility for upper_bound
void testUpperBound()
{
    const int TESTS = 100;
    const int SIZE = 100;

    for (int i = 0; i < TESTS; i++)
    {
        std::vector<int> arr(SIZE);
        int x = generate(arr, SIZE);
        std::sort(arr.begin(), arr.end());

        auto stlUpper = std::upper_bound(arr.begin(), arr.end(), x);
        int myUpper = upper_bound(arr, x);

        if (stlUpper == arr.end())
            assert(myUpper == arr.size());
        else
            assert(stlUpper - arr.begin() == myUpper);
    }
}

// Driver
int main()
{

    testLowerBound();
    testUpperBound();

    return 0;
}
