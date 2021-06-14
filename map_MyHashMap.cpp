//============================================================================
// Name        : map_MyHashMap.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <list>


class MyHashMap {
private:
	vector<list<pair<int, int> > > data;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
    	numElements = 0;
    	data.resize(10000);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
    	auto &list = data[key % data.size()];
    	for(auto &val : list){
    		if(val.first == key){
    			val.second = value;
    			return;
    		}
    	}
    	list.push_back({key, value});
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
    	auto list = data[key % data.size()];
    	for(auto val: list){
    		if(val.first == key) return val.second;
    	}
    	return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
    	auto& list = data[key % data.size()];
    	list.remove_if([key](auto n) { return n.first == key; });
    }
};

int main()
{
	MyHashMap* myMap = new MyHashMap();
	myMap->put(1, 1);
	myMap->put(2, 2);
	cout<<myMap->get(1)<<endl;
	cout<<myMap->get(3)<<endl;
	myMap->put(2, 1);
	cout<<myMap->get(2)<<endl;
	myMap->remove(2);
	cout<<myMap->get(2)<<endl;
	return 0;
}
