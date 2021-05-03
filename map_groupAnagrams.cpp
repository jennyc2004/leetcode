//============================================================================
// Name        : map_groupAnagrams.cpp
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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > result;
        unordered_map<string, vector<string> > strMap;
        for(string s:strs){
        	string t = s;
        	sort(t.begin(), t.end());
        	strMap[t].push_back(s);
        }
        for(auto m:strMap){
        	result.push_back(m.second);
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<string> strs{"eat","tea","tan","ate","nat","bat"};
	vector<vector<string> > result = s.groupAnagrams(strs);
	for(vector<string> v:result){
		for(string str:v)cout<<str<<",";
		cout<<endl;
	}
	return 0;
}
