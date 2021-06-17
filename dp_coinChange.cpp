//============================================================================
// Name        : dp_coinChange.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>
#include <list>


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	vector<int> dp(amount+1, amount+1);
    	dp[0] = 0;
    	for(int i = 1; i <= amount; i++){
    		for(int j = 0; j < coins.size(); j++){
    			if(coins[j] <= i) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    		}
    	}
    	if(dp[amount] > amount) return -1;
    	else return dp[amount];
    }
};

int main()
{
	Solution s;
	vector<int> coins {1,2,5};
	int amount = 11;
	cout<<s.coinChange(coins, amount)<<endl;
	return 0;
}
