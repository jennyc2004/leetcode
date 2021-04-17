//============================================================================
// Name        : sort_merge.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
// Description : Merge Intervals
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>


class Solution
{
public:
	vector<vector<int> > merge(vector<vector<int> >& intervals){
		vector<vector<int> > result;
		sort(intervals.begin(), intervals.end(), intervalSort);
		for(vector<int> interval: intervals){
			if(!result.empty() && result.back()[1] >= interval[0]){
				result.back()[1] = max(result.back()[1], interval[1]);
			}else result.push_back(interval);
		}
		return result;
	}
private:
	static bool intervalSort(vector<int>& a, vector<int>& b){
		return a[0] < b[0];
	}
};

int main()
{
	vector<vector<int> > intervals {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
	Solution s;
	vector<vector<int> > result = s.merge(intervals);
	for(vector<int> a: result){
		cout<<"["<<a[0]<<","<<a[1]<<"]"<<",";
	}
	cout<<endl;
	return 0;
}
