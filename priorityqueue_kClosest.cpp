//============================================================================
// Name        : priorityqueue_kClosest.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <queue>

class Solution {
private:
	struct pointsCompare{
		bool operator()(vector<int> &p1, vector<int> &p2){
			return (p1[0]*p1[0] + p1[1]*p1[1]) > (p2[0]*p2[0] + p2[1]*p2[1]);
		}
	};
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    	priority_queue<vector<int>, vector<vector<int> >, pointsCompare> pointsQueue;
    	for(auto p:points){
    		pointsQueue.push(p);
    	}
    	vector<vector<int> > result;
    	for(int i = 0; i < k; i++){
    		result.push_back(pointsQueue.top());
    		pointsQueue.pop();
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	vector<vector<int> > points {{3,3},{5,-1},{-2,4}};
	vector<vector<int> > vec = s.kClosest(points, 2);
	for(auto v : vec){
		cout<<v[0]<<","<<v[1]<<endl;
	}
	return 0;
}
