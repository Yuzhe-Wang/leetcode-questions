/*
Description:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

/*
LRU 
List of references the elements, least recently used element will be at the tail
List<pair<int,int>>

Hashmap of the elements
Hashmap<int,List<pair<int,int>>::iterator>

get(): *[key] -> second, list.splice to update the element to the tail
put(): hashmap find, doesn't exist [] to consturct
else update the value and the list
*/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache {
private:
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> map;
    int cap = 0;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()) {
            int value = map[key] -> second;
            cache.splice(cache.begin(), cache, map[key]);
            return value;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        // element already exists
        if(map.find(key) != map.end()) {
            map[key] -> second = value;
            cache.splice(cache.begin(), cache, map[key]);
            return;
        } 
        // reached capacity 
        else if (map.size() == cap) {
            pair<int,int> it = cache.back();
            map.erase(it.first);
            cache.pop_back();
        }
        cache.emplace_front(key,value);
        map[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */