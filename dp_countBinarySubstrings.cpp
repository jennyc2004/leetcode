//============================================================================
// Name        : dp_countBinarySubstrings.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>

class Solution {
public:
    int countBinarySubstrings(string s) {
    	int result = 0;
    	int pre = 0, cur = 1;
    	for(int i = 1; i < s.size(); i++){
    		if(s[i] == s[i-1]) cur++;
    		else{
    			result += min(cur, pre);
    			pre = cur;
    			cur = 1;
    		}
    	}
    	return result + min(cur, pre);
    }
};

int main()
{
	Solution s;
	cout<<s.countBinarySubstrings("00110011");
	return 0;
}
