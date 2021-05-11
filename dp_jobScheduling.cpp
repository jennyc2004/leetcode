//============================================================================
// Name        : dp_jobScheduling.cpp
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
#include <deque>

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    	vector<vector<int> > jobs;
    	int n = profit.size();
    	vector<int> dp(n, 0);
    	for(int i = 0; i < n; i++){
    		jobs.push_back({endTime[i], startTime[i], profit[i]});
    	}
    	sort(jobs.begin(), jobs.end());
    	for(int i = 0; i < n; i++){
    		if(i == 0) {
    			dp[i] = jobs[i][2];
    			continue;
    		}
    		int last = 0;
    		for(int j = i-1; j >= 0; j--){
    			if(jobs[j][0] <= jobs[i][1]) {
    				last = dp[j];
    				break;
    			}
    		}
    		dp[i] = max(dp[i-1], last + jobs[i][2]);
    	}
    	return dp[n-1];
    }
};

int main()
{
	Solution s;
	vector<int> startTime = {1,2,3,3}, endTime = {3,4,5,6}, profit = {50,10,40,70};
	cout<<s.jobScheduling(startTime, endTime, profit)<<endl;
	return 0;
}
