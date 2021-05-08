//============================================================================
// Name        : deque_maxSlidingWindow.cpp
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

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> result;
    	deque<int> dq;
    	for(int i = 0; i < nums.size(); i++){
    		while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
    		dq.push_back(i);
    		if(i >= k-1) result.push_back(nums[dq.front()]);
    		if(dq.front() <= i-k+1) dq.pop_front();
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums {1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<int> result = s.maxSlidingWindow(nums, k);
	for(int i:result)cout<<i<<",";
	cout<<endl;
	return 0;
}
