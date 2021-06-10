//============================================================================
// Name        : recursion_decodeString.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <queue>

class Solution {
public:
    string decodeString(string s) {
    	int i = 0;
    	return decodeString(s, i);
    }
    string decodeString(string s, int& i){
    	string result;
    	while(i < s.size() && s[i] != ']'){
    		if(!isdigit(s[i])) result += s[i++];
    		else{
    			int index = i;
    			int n = 0;
    			while(i < s.size() && isdigit(s[i])){
    				i++;
    			}
    			if(i > index) n = stoi(s.substr(index, i-index));
    			i++;
    			string t = decodeString(s, i);
    			i++;
    			while(n-- > 0) result += t;
    		}
    	}
    	return result;

    }
};

int main()
{
	Solution s;
	cout<<s.decodeString("3[a2[c]]")<<endl;
	return 0;
}
