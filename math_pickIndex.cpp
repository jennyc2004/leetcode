//============================================================================
// Name        : math_pickIndex.cpp
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
private:
	vector<int> accSum;
public:
    Solution(vector<int>& w) {
    	for(int v:w) accSum.push_back(accSum.empty()? v:(v+accSum.back()));
    }

    int pickIndex() {
    	int r = rand()% accSum.back();
    	auto it = upper_bound(accSum.begin(), accSum.end(), r);
    	return it - accSum.begin();
    }
};

int main()
{
	vector<int> w{1, 3};
	Solution s(w);
	cout<<s.pickIndex()<<endl;
	return 0;
}
