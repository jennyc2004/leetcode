//============================================================================
// Name        : dp_maximalSquare.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    	if(matrix.empty()) return 0;
    	int m = matrix.size(), n = matrix[0].size();
    	vector<vector<int> > dp(m, vector<int> (n, 0));
    	int maxLen = 0;
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(i == 0 || j == 0 || matrix[i][j] == '0')
    				dp[i][j] = matrix[i][j]-'0';
    			else
    				dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
    			maxLen = max(maxLen, dp[i][j]);
    		}
    	}
    	return maxLen*maxLen;
    }
};
int main()
{
	Solution s;
	vector<vector<char> > matrix {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	cout<<s.maximalSquare(matrix)<<endl;
	return 0;
}
