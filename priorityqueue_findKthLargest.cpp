//============================================================================
// Name        : priorityqueue_findKthLargest.cpp
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
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue<int, vector<int>, greater<int>> kthQ;
    	for(int n:nums){
    		kthQ.push(n);
    		if(kthQ.size() > k) kthQ.pop();
    	}
        return kthQ.top();
    }
};
int main()
{
	Solution s;
	vector<int> nums {3,2,1,5,6,4};
	int k = 2;
	cout<<s.findKthLargest(nums, k)<<endl;
	return 0;
}
