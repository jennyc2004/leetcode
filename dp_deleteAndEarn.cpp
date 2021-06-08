//============================================================================
// Name        : dp_deleteAndEarn.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
    	int maxN = 10001;
    	vector<int> basket(maxN, 0);
    	for(int n:nums) basket[n] += n;
    	int keep = 0, skip = 0;
    	for(int i = 0; i < maxN; i++){
    		//if we have ith basket
    		int keepi = skip + basket[i];
    		//if we don't have ith basket
    		int skipi = max(skip, keep);
    		keep = keepi;
    		skip = skipi;
    	}
    	return max(keep, skip);
    }
};

int main()
{
	Solution s;
	vector<int> nums {3, 3, 4, 4, 2};
	cout<<s.deleteAndEarn(nums)<<endl;
	return 0;
}
