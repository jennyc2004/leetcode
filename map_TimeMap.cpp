//============================================================================
// Name        : map_TimeMap.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>
#include <map>

class TimeMap {
private:
	unordered_map<string, map<int, string> > tMap;
public:
    /** Initialize your data structure here. */
    TimeMap() {}
    void set(string key, string value, int timestamp) {
    	tMap[key].insert({timestamp, value});
    }

    string get(string key, int timestamp) {
    	auto it = tMap[key].upper_bound(timestamp);
    	if(it == tMap[key].begin()) return "";
    	return prev(it)->second;
    }
};


int main()
{
	TimeMap kv;
	kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1
	cout<<kv.get("foo", 1)<<endl;  // output "bar"
	cout<<kv.get("foo", 3)<<endl; // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"
	kv.set("foo", "bar2", 4);
	cout<<kv.get("foo", 4)<<endl; // output "bar2"
	cout<<kv.get("foo", 5)<<endl; //output "bar2"
	return 0;
}
