//============================================================================
// Name        : priorityqueue_LFUCache.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

class LFUCache {

private:
	int _capacity, t;
	//key, freq, timestamp
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > used;
	unordered_map<int, int> cache;
	unordered_map<int, int> freq;
public:
    LFUCache(int capacity) {
    	_capacity = capacity;
    	t = 0;
    }

    int get(int key) {
    	auto it = cache.find(key);
    	if(it == cache.end()) return -1;
    	put(key, cache[key]);
    	return cache[key];
    }

    void put(int key, int value) {
        if(_capacity == 0) return;
    	if(cache.find(key) == cache.end() && cache.size() == _capacity){
    		while(cache.size()== _capacity){
    			auto x = used.top();
    			if(freq[x.second.second]==x.first){
    			cache.erase(x.second.second);
    		    freq.erase(x.second.second);
    			}
    			used.pop();
    		}
    	}
    	cache[key] = value;
    	freq[key]++;
    	used.push({freq[key],{t++, key}});
    }
};
int main()
{
	LFUCache* lfu = new LFUCache(2);
	lfu->put(1, 1);   // cache=[1,_], cnt(1)=1
	lfu->put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
	cout<<lfu->get(1)<<endl;;      // return 1
	                 // cache=[1,2], cnt(2)=1, cnt(1)=2

	lfu->put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
	                 // cache=[3,1], cnt(3)=1, cnt(1)=2
	cout<<lfu->get(2)<<endl;      // return -1 (not found)
	cout<<lfu->get(3)<<endl;      // return 3
	                 // cache=[3,1], cnt(3)=2, cnt(1)=2
	lfu->put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
	                 // cache=[4,3], cnt(4)=1, cnt(3)=2
	cout<<lfu->get(1)<<endl;      // return -1 (not found)
	cout<<lfu->get(3)<<endl;      // return 3
	                 // cache=[3,4], cnt(4)=1, cnt(3)=3
	cout<<lfu->get(4)<<endl;      // return 4
	                 // cache=[3,4], cnt(4)=2, cnt(3)=3
	return 0;
}
