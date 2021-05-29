//============================================================================
// Name        : wordsearch.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>


class Solution {
private:
	int m, n;
	bool dfsHelper(vector<vector<char>>& board, string word, int index, int i, int j){
		if(i < 0 || i >= m || j < 0 || j >= n || word[index] != board[i][j]) return false;
		if(index == word.size()-1) return true;
		char temp = board[i][j];
		board[i][j] = '*';
		bool result = dfsHelper(board, word, index+1, i+1, j) ||  dfsHelper(board, word, index+1, i-1, j)
				||  dfsHelper(board, word, index+1, i, j+1) ||  dfsHelper(board, word, index+1, i, j-1);
		board[i][j] = temp;
		return result;
	}
public:
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.empty())return true;
    	if(board.empty() || board[0].empty()) return false;
    	m = board.size();
    	n = board[0].size();
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			return dfsHelper(board, word, 0, i, j);
    		}
    	}
    	return false;
    }
};

int main()
{
	Solution s;
	vector<vector<char> > board {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
	cout<<s.exist(board, "ABCCED")<<endl;
	return 0;
}
