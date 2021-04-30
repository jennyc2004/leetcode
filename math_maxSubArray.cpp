//============================================================================
// Name        : math_maxSubArray.cpp
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
    int maxSubArray(vector<int>& nums) {
    	if(nums.empty()) return 0;
    	int curSum = nums[0], maxSum = nums[0];
    	for(int i = 1; i < nums.size(); i++){
    		curSum = max(nums[i], curSum+nums[i]);
    		maxSum = max(curSum, maxSum);
    	}
    	return maxSum;
    }
};
int main()
{
	Solution s;
	vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
	cout<<s.maxSubArray(nums)<<endl;
	return 0;
}
