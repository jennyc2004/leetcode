//============================================================================
// Name        : string_letterCombinations.cpp
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
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return {};
        result.push_back("");
        vector<vector<char> > letters{{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'},
        {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        for(char c: digits){
    		vector<string> temp;
        	for(char curChar:letters[c-'2']){
        		for(string s:result){
        			temp.push_back(s+curChar);
        		}
        	}
        	result.swap(temp);
        }
        return result;
    }
};

int main()
{
	Solution s;
	vector<string> result = s.letterCombinations("23");
	for(string s: result) cout<<s<<",";
	cout<<endl;
	return 0;
}
