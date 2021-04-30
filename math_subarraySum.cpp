//============================================================================
// Name        : math_subarraySum.cpp
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
    int subarraySum(vector<int>& nums, int k) {
    	unordered_map<int, int> sumMap;
        int sum = 0;
        int result = 0;
        sumMap[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            result += sumMap[sum-k];
            sumMap[sum]++;
        }
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums {1, 2, 3};
	int k = 3;
	cout<<s.subarraySum(nums, k)<<endl;
	return 0;
}
