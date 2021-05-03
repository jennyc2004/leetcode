//============================================================================
// Name        : dfs_maxAreaOfIsland.cpp
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	if(grid.size() == 0 || grid[0].size() == 0) return 0;
    	int result = 0;
    	for(int i = 0; i < grid.size(); i++){
    		for(int j = 0; j < grid[0].size(); j++)
    			if(grid[i][j] == 1) result = max(result, dfsHelper(grid, i, j));
    	}
    	return result;
    }
    int dfsHelper(vector<vector<int>>& grid, int i, int j){
    	if(i >= 0 && i <grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
    		grid[i][j] = 0;
    		return 1 + dfsHelper(grid, i-1, j) + dfsHelper(grid, i, j-1) + dfsHelper(grid, i+1, j) + dfsHelper(grid, i, j+1);
    	}
    	return 0;
    }
};

int main()
{
	Solution s;
	vector<vector<int> >grid {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	cout<<s.maxAreaOfIsland(grid)<<endl;
	return 0;
}
