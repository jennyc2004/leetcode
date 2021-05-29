//============================================================================
// Name        : math_rotate.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	if(matrix.empty() || matrix[0].empty()) return;
    	int m = matrix.size(), n = matrix[0].size();
    	reverse(matrix.begin(), matrix.end());
    	for(int i = 0; i < m; i++){
    		for(int j = i+1; j < n; j++){
    			swap(matrix[i][j], matrix[j][i]);
    		}
    	}
    }
};

int main()
{
	Solution s;
	vector<vector<int>> matrix {{1,2,3},{4,5,6},{7,8,9}};
	s.rotate(matrix);
	for(auto m:matrix){
		for(int a: m) cout<<a<<",";
		cout<<endl;
	}
	return 0;
}
