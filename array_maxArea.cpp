//============================================================================
// Name        : array_maxArea.cpp
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

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int i = 0, j = height.size()-1;
    	int result = 0;
    	while(i<j){
    		int h = min(height[i], height[j]);
    		result = max(result, (j-i)*h);
    		if(height[i]<=h && i < j) i++;
    		if(height[j]<=h && i < j) j--;
    	}
        return result;
    }
};
int main()
{
	Solution s;
	vector<int> height {1,8,6,2,5,4,8,3,7};
	cout<<s.maxArea(height)<<endl;
	return 0;
}
