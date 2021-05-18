//============================================================================
// Name        : string_longestCommonPrefix.cpp
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
#include <sstream>

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string result = "";
    	int index = 0;
    	if(strs.empty() || strs[0].size() == 0) return result;
    	result += strs[0][0];
    	while(true){
    		for(string s:strs){
    			if(result.empty()) return result;
    			if(index >= s.size() || s[index] != result.back()){
    				result.erase(result.size()-1);
    				return result;
    			}
    		}
    		index++;
    		if(index >= strs[0].size())return result;
    		result += strs[0][index];
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<string> strs{"flower","flow","flight"};
	cout<<s.longestCommonPrefix(strs)<<endl;
	return 0;
}
