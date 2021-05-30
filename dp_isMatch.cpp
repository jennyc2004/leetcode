//============================================================================
// Name        : dp_isMatch.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

class Solution {
public:
    bool isMatch(string s, string p) {
    	vector<vector<bool> > result {s.size()+1, vector<bool>(p.size()+1, false)};
    	result[0][0] = true;
    	for(int i = 2; i <= p.size(); i++){
    		if(p[i-1] == '*') result[0][i] = result[0][i-2];
    	}
    	for(int i = 1; i <= s.size(); i++){
    		for(int j = 1; j <= p.size(); j++){
    			if(s[i-1] == p[j-1] || p[j-1] == '.')result[i][j] = result[i-1][j-1];
    			else if(p[j-1] == '*'){
    				result[i][j] = result[i][j-2];
    				if(s[i-1] == p[j-2] || p[j-2] == '.') result[i][j] = result[i][j] || result[i-1][j];
    			}
    		}
    	}
        return result.back().back();
    }
};

int main()
{
	Solution s;
	string str = "aab", p = "c*a*b";
	cout<<s.isMatch(str, p)<<endl;
	return 0;
}
