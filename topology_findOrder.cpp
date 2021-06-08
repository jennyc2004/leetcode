//============================================================================
// Name        : topology_findOrder.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

class Solution{
public:
	vector<int> findOrder(int numCourses, vector<vector<int> >& prerequisites){
		vector<vector<int> > graph(numCourses, vector<int>());
		vector<int> indegree(numCourses, 0);
		queue<int> nodesQ;
		int visits = 0;
		vector<int> result;
		for(auto p:prerequisites){
			graph[p[1]].push_back(p[0]);
			indegree[p[0]]++;
		}
		for(int i = 0; i < indegree.size(); i++){
			if(indegree[i] == 0) nodesQ.push(i);
		}
		while(!nodesQ.empty()){
			visits++;
			int id = nodesQ.front();
			nodesQ.pop();
			result.push_back(id);
			for(int neighbor: graph[id]){
				indegree[neighbor]--;
				if(indegree[neighbor] == 0) nodesQ.push(neighbor);
			}
		}
		if(visits == numCourses) return result;
		else return vector<int> ();
	}
};

int main()
{
	Solution s;
	vector<vector<int> > prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
	vector<int> result = s.findOrder(4, prerequisites);
	for(int a:result) cout<<a<<",";
	cout<<endl;
	return 0;
}
