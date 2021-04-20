//============================================================================
// Name        : dp_productExceptSelf.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        result[0] = 1;
        //the product left side of i position
        for (int i = 1; i < n; i++) {
            result[i] = result[i-1] * nums[i-1];
        }
        //the product right side of i position
        int rightside = 1;
        for (int i = n-2; i >= 0; i--) {
        	rightside *= nums[i+1];
            result[i] = result[i] * rightside;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> nums {1, 2, 3, 4};
	for(int a : s.productExceptSelf(nums)) cout<<a<<", ";
	cout<<endl;
	return 0;
}
