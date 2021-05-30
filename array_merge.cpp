//============================================================================
// Name        : array_merge.cpp
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int i = m-1, j = n-1, index = m+n-1;
    	while(i >= 0 && j >= 0){
    		if(nums1[i] > nums2[j]){
    			nums1[index--] = nums1[i--];
    		}else nums1[index--] = nums2[j--];
    	}
    	while(j >= 0){
    		nums1[index--] = nums2[j--];
    	}
    }
};
int main()
{
	Solution s;
	vector<int> nums1 {4, 5, 6, 0, 0, 0};
	vector<int> nums2 {1, 2, 3};
	int m = 3, n = 3;
	s.merge(nums1, m, nums2, n);
	for(int a:nums1)cout<<a<<",";
	cout<<endl;
	return 0;
}
