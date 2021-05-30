//============================================================================
// Name        : math_BinaryMatrix.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

class BinaryMatrix {
	public:
    	int get(int row, int col);
    	vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    	int row = binaryMatrix.dimensions()[0];
    	int col = binaryMatrix.dimensions()[1];
    	int curRow = 0, curCol = col-1;
    	while(curRow < row && curCol >= 0){
    		if(binaryMatrix.get(curRow, curCol) == 0)curRow++;
    		else curCol--;
    	}
    	if(curCol == col-1) return -1;
    	else return curCol+1;
    }
};
int main()
{
	Solution s;

	return 0;
}
