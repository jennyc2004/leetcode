//============================================================================
// Name        : math_isRobotBounded.cpp
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
	bool isRobotBounded(string instructions){
		//north, east, south, west
		vector<vector<int> > steps {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int direction = 0;
		int x = 0, y = 0;
		for(auto instruction: instructions){
			if(instruction == 'L') direction = (direction+3) % 4;
			else if(instruction == 'R') direction = (direction+1) % 4;
			else{
				x += steps[direction][0];
				y += steps[direction][1];
			}
		}
		return (x == 0 && y == 0 )|| direction != 0;
	}
};

int main()
{
	Solution s;
	string instructions = "GGLLGG";
	cout<<s.isRobotBounded(instructions)<<endl;
	instructions = "GG";
	cout<<s.isRobotBounded(instructions)<<endl;
	return 0;
}
