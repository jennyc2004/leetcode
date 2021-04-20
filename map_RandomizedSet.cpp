//============================================================================
// Name        : map_RandomizedSet.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>
#include <vector>

class RandomizedSet {
private:
	vector<int> nums;
	unordered_map<int, int> numsMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(numsMap.find(val) != numsMap.end()) return false;
        numsMap[val] = nums.size();
        nums.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(numsMap.find(val) == numsMap.end()) return false;
        int index = numsMap[val];
        int last = nums.size()-1;
        swap(nums[index], nums[last]);
        nums.pop_back();
        numsMap[nums[index]] = index;
        numsMap.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

int main()
{
	RandomizedSet* s = new RandomizedSet();
	s->insert(1);
	s->insert(2);
	for(int i = 0 ; i < 10; i++) cout<<s->getRandom()<<" ";
	cout<<endl;
	s->remove(1);
	for(int i = 0 ; i < 10; i++) cout<<s->getRandom()<<" ";
	cout<<endl;

	return 0;
}
