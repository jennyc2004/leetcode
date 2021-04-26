//============================================================================
// Name        : math_maxArea.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
	    sort(hCuts.begin(), hCuts.end());
	    sort(vCuts.begin(), vCuts.end());
	    int maxh = max(h-hCuts.back(), hCuts[0]);
	    int maxw = max(w-vCuts.back(), vCuts[0]);
	    for(int i = 0; i < hCuts.size()-1; i++){
	    	maxh = max(maxh, hCuts[i+1] - hCuts[i]);
	    }
	    for(int i = 0; i < vCuts.size()-1; i++){
	    	maxw = max(maxw, vCuts[i+1] - vCuts[i]);
	    }
	    return (long)maxh*maxw%1000000007;
	}
};


int main()
{
	Solution s;
	vector<int> hCuts {3,1};
	vector<int> vCuts {1};
	cout<<s.maxArea(5, 4, hCuts, vCuts)<<endl;
	return 0;
}
