//============================================================================
// Name        : stack_dailyTemperatures.cpp
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
#include <unordered_set>
#include <sstream>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    	vector<int> result(temperatures.size());
    	stack<pair<int, int> > largeStack;
    	for(int i = temperatures.size()-1; i>= 0; i--){
    		while(!largeStack.empty() && largeStack.top().first <= temperatures[i]) largeStack.pop();
    		result[i] = largeStack.empty()? 0 : largeStack.top().second - i;
    		largeStack.push({temperatures[i], i});
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> result = s.dailyTemperatures(temperatures);
	for(int a:result) cout<<a<<",";
	cout<<endl;
	return 0;
}
