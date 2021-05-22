//============================================================================
// Name        : stack_removeDuplicates.cpp
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
#include <stack>

class Solution {
public:
    string removeDuplicates(string s, int k) {
    	stack<pair<int, char>> chars;
    	chars.push({0, '#'});
    	string result;
    	for(char c:s){
    		if(chars.top().second != c) chars.push({1, c});
    		else if(++chars.top().first == k) chars.pop();
    	}
    	while(chars.size()>1){
    		auto p = chars.top();
    		chars.pop();
    		result.insert(0, p.first, p.second);
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	cout<<s.removeDuplicates("deeedbbcccbdaa", 3)<<endl;
	cout<<endl;
	return 0;
}
