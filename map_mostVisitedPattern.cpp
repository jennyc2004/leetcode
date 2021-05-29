//============================================================================
// Name        : map_mostVisitedPattern.cpp
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

class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    	unordered_map<string, map<int, string> > data;//map<int, string> is sorted
    	for(int i = 0; i < username.size(); i++) data[username[i]][timestamp[i]] =  website[i];
    	map<vector<string>, int > counter;
    	for(auto m:data){
    		vector<string> webs;
    		for(auto visits:m.second) webs.push_back(visits.second);
    		set<vector<string> > seqs;
    		for(int i = 0; i < webs.size(); i++){
    			for(int j = 0; j < i; j++){
    				for(int k = 0; k < j; k++){
    					seqs.insert({webs[k], webs[j], webs[i]});
    				}
    			}
    		}
    		for(auto seq: seqs) counter[seq]++;
    	}
    	//sorted by frenquency then by alphabet order
    	return max_element(counter.begin(), counter.end(), [](auto& p1, auto& p2){return p1.second<p2.second ||
    			(p1.second == p2.second && p1.first > p2.first);})->first;
    }
};
int main()
{
	Solution s;
	vector<string> username {"zkiikgv","zkiikgv","zkiikgv","zkiikgv"};
	vector<int> timestamp {436363475,710406388,386655081,797150921};
	vector<string> website {"wnaaxbfhxp","mryxsjc","oz","wlarkzzqht"};
	vector<string> result = s.mostVisitedPattern(username, timestamp, website);
	for(string s:result)cout<<s<<",";
	cout<<endl;
	return 0;
}
