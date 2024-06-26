#include <unordered_map>
#include <list>

class LRUCache {
private:
    int capacity;
    std::list<int> order; // Doubly linked list to store the order of keys
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache; // Hash map to store key-value pairs and their position in the list

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            // Key not found
            return -1;
        } else {
            // Key found, move it to the front of the list
            order.erase(it->second.second);
            order.push_front(key);
            it->second.second = order.begin();
            return it->second.first;
        }
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Key exists, update the value and move it to the front
            order.erase(it->second.second);
            order.push_front(key);
            it->second = {value, order.begin()};
        } else {
            // Key does not exist, insert it
            if (cache.size() == capacity) {
                // Cache is full, remove the least recently used item
                int lru = order.back();
                order.pop_back();
                cache.erase(lru);
            }
            // Insert the new key-value pair
            order.push_front(key);
            cache[key] = {value, order.begin()};
        }
    }
};
