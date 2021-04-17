//============================================================================
// Name        : map_twoSum.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description : Two Sum
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>
#include <vector>


class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target){
		unordered_map<int, int> indexMap;
		for(int i = 0; i < nums.size(); i++){
			if(indexMap.find(target-nums[i]) != indexMap.end()) return {indexMap[target-nums[i]], i};
			indexMap[nums[i]] = i;
		}
		return {};
	}
};

int main()
{
	vector<int> nums {2, 7, 11, 15};
	int target = 9;
	Solution s;
	cout<<s.twoSum(nums, target)[0] <<", "<<s.twoSum(nums, target)[1]<<endl;
	return 0;
}
