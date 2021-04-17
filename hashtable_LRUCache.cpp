//============================================================================
// Name        : hashtable_LRUCache.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description : LRU Cache
// LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // cache is {1=1}
//lRUCache.put(2, 2); // cache is {1=1, 2=2}
//lRUCache.get(1);    // return 1
//lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
//lRUCache.get(2);    // returns -1 (not found)
//lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
//lRUCache.get(1);    // return -1 (not found)
//lRUCache.get(3);    // return 3
//lRUCache.get(4);    // return 4
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>
#include <list>


class LRUCache
{
public:
	LRUCache(int capacity){
		_capacity = capacity;
	}
	int get(int key){
		auto it = cache.find(key);
		if(it == cache.end()) return -1;
		used.erase(it->second.second);
		used.push_front(key);
		it->second.second = used.begin();
		return it->second.first;
	}
	void put(int key, int value){
		auto it = cache.find(key);
		if(it == cache.end()){
			if(cache.size() == _capacity){
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}else {
			used.erase(it->second.second);
			used.push_front(key);
			it->second.second = used.begin();
		}
		cache[key] = {value, used.begin()};
	}
private:
	int _capacity;
	//key list with current key at the front
	list<int> used;
	unordered_map<int, pair<int, list<int>::iterator > > cache;
};

int main()
{
	/*LRUCache* cache = new LRUCache(2);
	cache->put(1, 1); // cache is {1=1}
	cache->put(2, 2); // cache is {1=1, 2=2}
	cout<<cache->get(1)<<endl;    // return 1
	cache->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	cout<<cache->get(2)<<endl;    // returns -1 (not found)
	cache->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	cout<<cache->get(1)<<endl;    // return -1 (not found)
	cout<<cache->get(3)<<endl;    // return 3
	cout<<cache->get(4)<<endl;    // return 4*/
	LRUCache* cache = new LRUCache(3);
	cache->put(1, 1);
	cache->put(2, 2);
	cache->put(3, 3);
	cache->put(1, 4);
	cache->put(2, 5);
	cache->put(3, 6);
	return 0;
}
