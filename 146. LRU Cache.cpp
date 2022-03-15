/*
Description:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.
*/

// basic idea: hashmap +  list (doubly linked list)
// the reason why a queue wouldn't work: after eviction, the key may remain in the middle of the queue, removing all the appearance of that evicted key will take linear time

#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>

using namespace std;

class LRUCache {
private: 
    int mCapacity = 0;
    list<pair<int,int> > mList;
    unordered_map<int, list<pair<int,int> >::iterator> mCache;
public:
    LRUCache(int capacity) {
        mCapacity = capacity;
    }
    
    int get(int key) {
        const auto& it = mCache.find(key);
        if(it == mCache.end()) {
            return -1;
        } else {
            mList.splice(mList.begin(), mList, it -> second);
            return it -> second -> second;
        }
    }
    
    void put(int key, int value) {
        const auto& it = mCache.find(key);
        
        if(it != mCache.end()) {
            it -> second ->second = value;
            mList.splice(mList.begin(), mList, it -> second);
            return;
        } 
        
        if(mCapacity == mCache.size()) {
            const auto& last = mList.back();
            mCache.erase(last.first);
            mList.pop_back();
        }
        
        mList.emplace_front(key,value);
        mCache[key] = mList.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */