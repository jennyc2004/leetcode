//============================================================================
// Name        : math_nextPermutation.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int pos;
        for(pos = nums.size()-2; pos>=0; pos--){
            if(nums[pos] < nums[pos+1]) break;
        }
        //3, 2, 1 case
        if(pos == -1) {
        	reverse(nums.begin(), nums.end());
        	return;
        }
        //1,3,2 case, pos = 0, swapIndex = 2
        int swapIndex;
        for(swapIndex = nums.size()-1; swapIndex> pos; swapIndex--){
        	if(nums[swapIndex] > nums[pos]) break;
        }
        swap(nums[swapIndex], nums[pos]);
        reverse(nums.begin()+pos+1, nums.end());
        return;
    }
};
int main()
{
	Solution s;
	vector<int> nums1 {1, 3, 2};
	s.nextPermutation(nums1);
	for(int n:nums1)cout<<n<<",";
	cout<<endl;
	vector<int> nums2 {3, 2, 1};
	s.nextPermutation(nums2);
	for(int n:nums2)cout<<n<<",";
	cout<<endl;
	vector<int> nums3 {2, 3, 1};
	s.nextPermutation(nums3);
	for(int n:nums3)cout<<n<<",";
	cout<<endl;
	return 0;
}
