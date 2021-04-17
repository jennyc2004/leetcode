//============================================================================
// Name        : dp_maxProfit.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <climits>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minprice = INT_MAX;
        int result = 0;
        for(int i = 0; i < prices.size(); i++){
        	//minprice is the min until i
            minprice = min(minprice, prices[i]);
            //difference between price at i and min until i
            result = max(result, prices[i] - minprice);
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> A {7,1,5,3,6,4};
	cout<<s.maxProfit(A)<<endl;
	return 0;
}
