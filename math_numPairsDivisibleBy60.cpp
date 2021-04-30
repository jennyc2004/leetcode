//============================================================================
// Name        : math_numPairsDivisibleBy60.cpp
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
    int numPairsDivisibleBy60(vector<int>& time) {
    	vector<int> count(60);
    	int result = 0;
    	for(int t: time){
    		result += count[(600-t)%60];
    		count[t%60] += 1;
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int> time {30,20,150,100,40};
	cout<<s.numPairsDivisibleBy60(time)<<endl;
	return 0;
}
