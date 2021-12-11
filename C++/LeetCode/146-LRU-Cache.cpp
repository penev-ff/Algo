/**
 * 
 *  Author: Ivan Penev
 *  Source: https://leetcode.com/problems/lru-cache/
 *  Time: O(1)
 *  Space: O(n)
 *
*/

#include <unordered_map>
#include <list>

using namespace std;
typedef list<int>::iterator lit;

class LRUCache
{
public:
    unordered_map<int, pair<int, lit>> storage;
    list<int> lru;
    int capacity;

    LRUCache(int capacity)
        : capacity(capacity) {}

    int get(int key)
    {
        auto it = storage.find(key);
        if (it != storage.end())
        {
            // Make it most recently used if it's not already
            if (it->second.second != lru.begin())
            {
                lru.erase(it->second.second);
                lru.push_front(key);
                it->second.second = lru.begin();
            }

            return it->second.first;
        }

        return -1;
    }

    void put(int key, int value)
    {
        auto it = storage.find(key);
        if (it != storage.end())
        {
            // Update the value in the map
            it->second.first = value;

            lru.erase(it->second.second);
            lru.push_front(key);
            it->second.second = lru.begin();
        }
        else
        {
            if (lru.size() >= capacity)
            {
                // Evict the Least Recently Used
                storage.erase(lru.back());
                lru.pop_back();
            }

            lru.push_front(key);
            storage.insert({key, make_pair(value, lru.begin())});
        }
    }
};

int main()
{
    LRUCache lru(2);

    lru.put(2, 1);
    lru.put(1, 1);
    lru.put(2, 3);
    lru.put(4, 1);
    lru.get(1);
    lru.get(2);

    return 0;
}