//============================================================================
// Name        : binarysearch_findMedianSortedArrays.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	if(nums1.size() > nums2.size()) nums1.swap(nums2);
    	int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
    	int left = 0, right = n1 -1;
    	int mid = (n-1)/2;
    	//until we find left>right
    	while(left <= right){
    		int m1 = left + (right-left)/2, m2 = mid-m1;
    		if(nums1[m1] > nums2[m2]) right = m1-1;
    		else left = m1 + 1;
    	}
    	int a = max(right >= 0? nums1[right]:INT_MIN, mid-left >= 0? nums2[mid-left]:INT_MIN);
    	if(n%2) return a;
    	int b = min(left < n1? nums1[left]:INT_MAX, mid-right < n2? nums2[mid-right]:INT_MAX);
    	return (a+b)/2.0;
    }
};

int main()
{
	Solution s;
	vector<int> a{1, 3, 5, 7, 9, 10};
	vector<int> b{2, 4, 6, 8, 11, 12, 13, 14, 15};
	cout<<s.findMedianSortedArrays(a, b)<<endl;
	return 0;
}
