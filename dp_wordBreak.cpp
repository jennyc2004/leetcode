//============================================================================
// Name        : dp_wordBreak.cpp
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
    bool wordBreak(string s, vector<string>& wordDict) {
    	vector<int> dp(s.size() + 1, false);
    	dp[0] = true;
    	for(int i = 1; i <= s.size(); i++){
    		for(int j = 0; j < i; j++){
    			if(dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end()){
    				dp[i] = true;
    				break;
    			}
    		}
    	}
        return dp.back();
    }
};
int main()
{
	Solution s;
	vector<string> wordDict {"leet","code"};
	cout<<s.wordBreak("leetcode", wordDict)<<endl;
	return 0;
}
