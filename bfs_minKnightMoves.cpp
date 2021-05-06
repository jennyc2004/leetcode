//============================================================================
// Name        : bfs_minKnightMoves.cpp
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
    int minKnightMoves(int x, int y) {
    	if(x ==0 && y == 0) return 0;
    	queue<pair<int, int>> movesQ;
    	movesQ.push({0, 0});
    	vector<pair<int, int> > directions {{1,2},{2,1},{2,-1},{1,-2},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    	unordered_map<int, unordered_map<int, bool> > visited;
    	visited[0][0] = true;
    	int levels = 1;
    	while(!movesQ.empty()){
    		int levelSize = movesQ.size();
    		for(int i = 0; i < levelSize; i++){
    			pair<int, int> front = movesQ.front();
    			movesQ.pop();
    			for(pair<int, int> dir: directions){
    				int nx = front.first + dir.first;
    				int ny = front.second + dir.second;
    				if(nx == x && ny == y) return levels;
    				if(!visited[nx][ny] && nx*x >= -1 && ny*y >=-1){
    					visited[nx][ny] = true;
    					movesQ.push({nx, ny});
    				}
    			}
    		}
    		levels++;
    	}
    	return -1;
    }
};

int main()
{
	Solution s;
	cout<<s.minKnightMoves(1, 1)<<endl;
	return 0;
}
