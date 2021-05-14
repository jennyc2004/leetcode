//============================================================================
// Name        : bfs_alienOrder.cpp
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
#include <deque>
#include <unordered_set>


class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.empty())
            return "";
        unordered_map<char,unordered_set<char>>graph;
        unordered_map<char,int> inDegree;
        for(string s:words) {
            for(char c: s) inDegree[c]=0;
        }
        for(int i=0;i<words.size()-1;i++) {
            string cur=words[i];
            string next=words[i+1];
            int len=min(cur.size(),next.size());
            for(int j=0;j<len;j++ ) {
                if(cur[j]!=next[j]) {
                    if(graph[cur[j]].find(next[j])==graph[cur[j]].end()) {
                        graph[cur[j]].emplace(next[j]);
                        inDegree[next[j]]++;
                    }
                     break;
                }
                if(j==len-1 && cur.size()>next.size()) return "";
            }
        }
        string res;
        queue<char> bfs;
        for(auto &it:inDegree) {//push only when degree is set to 0
            if(it.second==0) bfs.push(it.first);
        }
        while(!bfs.empty()){ //simply a bfs using indegrees (top sort)
            auto c=bfs.front();
            bfs.pop();
            res+=c;
            for(auto &neighbor:graph[c]){
                inDegree[neighbor]--;
                if(!inDegree[neighbor]) bfs.push(neighbor);
            }
        }
        return res.size()==inDegree.size()?res:"";
    }
};
int main()
{
	Solution s;
	vector<string> words {"wrt","wrf","er","ett","rftt"};
	cout<<s.alienOrder(words)<<endl;
	return 0;
}
