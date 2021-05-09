//============================================================================
// Name        : recursion_generateParenthesis.cpp
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

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	if(!n) return {""};
        vector<string> result;
        for(int i = 0; i < n; i++){
        	for(string l:generateParenthesis(i)){
        		for(string r:generateParenthesis(n-1-i)){
        			result.push_back("("+l+")"+r);
        		}
        	}
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<string> result = s.generateParenthesis(3);
	for(string s:result)cout<<s<<",";
	cout<<endl;
	return 0;
}
