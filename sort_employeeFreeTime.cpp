//============================================================================
// Name        : sort_employeeFreeTime.cpp
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


// Definition for an Interval.
class Interval {
public:
    int start;
    int end;
    Interval() {}
    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
    	vector<Interval> result;
    	vector<int> begin, end;
    	for(auto v:schedule){
    		for(Interval inter:v){
    			begin.push_back(inter.start);
    			end.push_back(inter.end);
    		}
    	}
    	sort(begin.begin(), begin.end());
    	sort(end.begin(), end.end());
    	for(int i = 0; i < begin.size()-1; i++){
    		if(end[i] < begin[i+1]) result.push_back(Interval(end[i], begin[i+1]));
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	vector<vector<Interval> > schedule {{Interval(1,3),Interval(6,7)},{Interval(2,4)},{Interval(2,5),Interval(9,12)}};
	vector<Interval> result = s.employeeFreeTime(schedule);
	for(auto interval: result) cout<<"["<<interval.start<<","<<interval.end<<"]";
	cout<<endl;
	return 0;
}
