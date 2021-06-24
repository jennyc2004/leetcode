//============================================================================
// Name        : bit_gameOfLife.cpp
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
    void gameOfLife(vector<vector<int>>& board) {
    	int m = board.size();
    	if(m == 0) return;
    	int n = board[0].size();
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			int count = 0;
    			for(int k = max(0, i-1); k < min(i+2, m); k++){
    				for(int l = max(0, j-1); l < min(j+2, n); l++){
    					count += board[k][l] & 1;
    				}
    			}
    			if(count == 3 || count - board[i][j] == 3)board[i][j] |= 2;

    		}
    	}
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			board[i][j] >>= 1;
    		}
    	}

    }
};

int main()
{
	Solution s;
	vector<vector<int> > board {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	//output [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]
	s.gameOfLife(board);
	for(auto a:board){
		for(int i: a)cout<<i<<",";
		cout<<endl;
	}
	return 0;
}
