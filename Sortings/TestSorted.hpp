#include <vector>
#include <cassert>
#include <cstdlib>
#include <algorithm>

#define TESTS_COUNT 1000
#define ELEMENTS 10
#define LOWER_BOUND -100
#define UPPER_BOUND 100

void generateVector(std::vector<int> &v)
{
    for (size_t i = 0; i < ELEMENTS; i++)
    {
        v[i] = (rand() % (abs(UPPER_BOUND - LOWER_BOUND) + 1)) + LOWER_BOUND;
    }
}

void sortTest(void (*sort)(std::vector<int> &v))
{
    for (size_t i = 0; i < TESTS_COUNT; i++)
    {
        std::vector<int> v(ELEMENTS);
        generateVector(v);
        sort(v);

        assert(std::is_sorted(v.begin(), v.end()));

        v.clear();
    }
}
