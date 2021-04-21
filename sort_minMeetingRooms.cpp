//============================================================================
// Name        : sort_minMeetingRooms.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
private:
	struct intervalCompare{
		bool operator()(vector<int> &a, vector<int> &b){
			return a[0]<b[0];
		}
	};
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
    	int rooms = 1;
    	priority_queue<int, vector<int>, greater<int> > timeQ;
    	//sort by starting time and end time.
    	sort(intervals.begin(), intervals.end(), intervalCompare());
    	timeQ.push(intervals[0][1]);
    	for(int i = 1; i < intervals.size(); i++){
    		if(intervals[i][0] < timeQ.top()) rooms++;
    		else timeQ.pop();
    		timeQ.push(intervals[i][1]);
    	}
    	return rooms;
    }
};

int main()
{
	Solution s;
	vector<vector<int> > intervals1{{4,9},{4,17}, {9,10}};
	vector<vector<int> > intervals2{{0,30},{5,10},{15,20}};
	cout<<s.minMeetingRooms(intervals1)<<endl;
	cout<<s.minMeetingRooms(intervals2)<<endl;
	return 0;
}
