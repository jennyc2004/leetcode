//============================================================================
// Name        : array_moveZeroes.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	int index = 0;
    	int i = 0;
    	while(i < nums.size()){
    		if(nums[i] != 0) nums[index++] = nums[i];
    		i++;
    	}
    	while(index < nums.size()){
    		nums[index++] = 0;
    	}
    }
};

int main()
{
	Solution s;
	vector<int> nums {0,1,0,3,12};
	s.moveZeroes(nums);
	for(int a:nums) cout<<a<<",";
	cout<<endl;
	return 0;
}
