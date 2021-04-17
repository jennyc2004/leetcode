//============================================================================
// Name        : dp_mindifficulty.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <climits>

class Solution
{
public:
	int minDifficulty(vector<int> jobDifficulty, int D) {
		int n = jobDifficulty.size();
		if(n < D) return -1;//since each day must at least have one job done
		vector<vector<int> > dp (D, vector<int> (n));
		//dp[0] is the max of all job since all jobs are done in 1 day
		dp[0][0] = jobDifficulty[0];
		for(int i = 1; i < n; ++i){
			dp[0][i] = max(jobDifficulty[i], dp[0][i - 1]);
		}
		//for day 2 to D
		for(int i = 1; i < D; ++i){
			//start from i since each day at least one job
			for(int j = i; j < n; ++j){
				int localMax = jobDifficulty[j];
				//update index i day and j job
				dp[i][j] = INT_MAX;
				//k from j job down to i job dp[i-1][k-1]
				for(int k = j; k >= i; --k){
					localMax = max(localMax, jobDifficulty[k]);
					dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + localMax);
				}
			}
		}
		return dp[D - 1][n - 1];
	}
};


int main()
{
	Solution s;
	vector<int> A {11,111,22,222,33,333,44,444};
	int D = 6;
	cout<<s.minDifficulty(A, D)<<endl;
	return 0;
}
