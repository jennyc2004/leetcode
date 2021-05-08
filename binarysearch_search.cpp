//============================================================================
// Name        : binarysearch_search.cpp
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
    int search(vector<int>& nums, int target) {
    	int low = 0, high = nums.size();
    	while(low < high){
    		int mid = low + (high-low)/2;
    		int midNum;
    		if((nums[0] > target) == (nums[0] > nums[mid]))midNum = nums[mid];
    		else{
    			if(target < nums[0])midNum = INT_MIN;
    			else midNum = INT_MAX;
    		}
    		if(midNum < target) low = mid + 1;
    		else if(midNum > target) high = mid;
    		else return mid;
    	}
    	return -1;
    }
};

int main()
{
	Solution s;
	vector<int> nums {3, 1};
	int target = 3;
	cout<<s.search(nums, target)<<endl;
	return 0;
}
