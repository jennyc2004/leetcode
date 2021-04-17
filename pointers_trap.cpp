//============================================================================
// Name        : pointers_trap.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>

class Solution
{
public:
	int trap(vector<int>& height){
		int result = 0;
		int maxLeft = 0, maxRight = 0;
		int l = 0, r = height.size() -1;
		while(l < r){
			if(height[l] < height[r]){
				if(height[l] > maxLeft){
					maxLeft = height[l++];
				}else{
					result += maxLeft - height[l++];
				}
			}else{
				if(height[r] > maxRight){
					maxRight = height[r--];
				}else{
					result += maxRight - height[r--];
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};
	Solution s;
	cout<<s.trap(height)<<endl;
	return 0;
}
