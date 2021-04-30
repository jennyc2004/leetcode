//============================================================================
// Name        : math_threeSum.cpp
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

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int> > result;
    	if(nums.size() < 3) return result;
    	sort(nums.begin(), nums.end());
    	//nums.size()-2, nums.size()-1 for start and end
    	for(int i = 0; i <= nums.size()-3; i++){
    		int start = i+1, end = nums.size()-1;
    		//skip repeated numbers
    		if(i > 0 && nums[i] == nums[i-1]) continue;
    		while(start < end){
    			if(nums[start]+nums[end] == -nums[i]){
    				result.push_back({nums[start], nums[end], nums[i]});
    				start++; end--;
    				while(start < end && nums[start] == nums[start-1]) start++;
    				while(start < end && nums[end] ==nums[end+1]) end--;
    			}else if(nums[start]+nums[end] > -nums[i])end--;
    			else start++;
    		}
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums {-1,0,1,2,-1,-4};
	vector<vector<int> > result = s.threeSum(nums);
	for(auto v:result){
		cout<<v[0]<<","<<v[1]<<","<<v[2]<<endl;
	}
	return 0;
}
