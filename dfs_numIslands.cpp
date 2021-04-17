//============================================================================
// Name        : dfs_numIslands.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description : Number of Islands
// vector<vector<char>> grid
//{{'1','1','0','0','0'},
// {'1','1','0','0','0'},
// {'0','0','1','0','0'},
// {'0','0','0','1','1'}}
//============================================================================
using namespace std;
#include <vector>
#include <iostream>


class Solution
{
public:
	int numIslands(vector<vector<char>>& grid){
		int m = grid.size();
		int n = grid[0].size();
		int result = 0;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(grid[i][j] == '1') result++;
				eraseIslands(grid, i, j);
			}
		}
		return result;
	}
private:
	void eraseIslands(vector<vector<char> >& grid, int i, int j){
		int m = grid.size();
		int n = grid[0].size();
		if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') return;
		grid[i][j] = '0';
		eraseIslands(grid, i-1, j);
		eraseIslands(grid, i+1, j);
		eraseIslands(grid, i, j-1);
		eraseIslands(grid, i, j+1);
	}
};

int main()
{
	vector<vector<char>> grid {{'1','1','0','0','0'}, {'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
	Solution s;
	cout<<s.numIslands(grid)<<endl;
	return 0;
}
