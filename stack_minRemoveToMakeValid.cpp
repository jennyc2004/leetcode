//============================================================================
// Name        : stack_minRemoveToMakeValid.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

class Solution {
public:
    string minRemoveToMakeValid(string s) {
    	stack<int> indexStack;
    	for(int i = 0; i < s.size(); i++){
    		if(s[i] == '(')indexStack.push(i);
    		else if (s[i] == ')'){
    			if(!indexStack.empty())indexStack.pop();
    			else s[i] = '*';
    		}
    	}
    	while(!indexStack.empty()){
    		s[indexStack.top()] = '*';
    		indexStack.pop();
    	}
    	s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};


int main()
{
	Solution s;
	cout<<s.minRemoveToMakeValid("lee(t(c)o)de)");
	return 0;
}
