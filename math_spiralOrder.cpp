//============================================================================
// Name        : math_spiralOrder.cpp
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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m < 1) return result;
        int n = matrix[0].size();
        int up = 0, down = m-1, left = 0, right = n-1;
        while(up<=down && left<=right){
        	for(int i = left; i <= right; i++) result.push_back(matrix[up][i]);
        	if(++up > down) break;
        	for(int j = up; j <= down; j++) result.push_back(matrix[j][right]);
        	if(--right < left) break;
        	for(int i = right; i >= left; i--) result.push_back(matrix[down][i]);
        	if(--down < up) break;
        	for(int j = down; j >= up; j--) result.push_back(matrix[j][left]);
        	if(++left > right) break;
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int> > matrix {{1,2,3}, {4, 5, 6}, {7,8,9}};
	vector<int> result = s.spiralOrder(matrix);
	for(int a: result) cout<<a<<",";
	cout<<endl;
	return 0;
}
