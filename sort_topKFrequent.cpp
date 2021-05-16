//============================================================================
// Name        : sort_topKFrequent.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_map>
#include <deque>
#include <unordered_set>
#include <sstream>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	vector<int> result;
    	unordered_map<int, int> numMap;
    	for(int n:nums) numMap[n]++;
    	//possible most frequent maybe nums.size();
    	vector<vector<int> > bucket(nums.size() + 1);
    	for(auto m:numMap){
    		bucket[m.second].push_back(m.first);
    	}
    	//go through bucket and push the value in the bucket to result
    	for(auto it = bucket.rbegin(); it != bucket.rend(); it++){
    		for(int n: *it){
    			result.push_back(n);
    			if(result.size() == k) return result;
    		}
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums {1,1,1,2,2,3};
	int k = 2;
	vector<int> result = s.topKFrequent(nums, k);
	for(int i:result) cout<<i<<",";
	cout<<endl;
	return 0;
}
