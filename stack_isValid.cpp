//============================================================================
// Name        : stack_isValid.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <stack>

class Solution {
public:
	bool isValid(string s){
		stack<char> brackets;
		for(char c:s){
			if(c == '(' || c == '[' || c == '{'){
				brackets.push(c);
			}
			else if(c == ')' || c == ']' || c == '}'){
				if(brackets.empty()) return false;
				char match = brackets.top();
				if(match == '(' && c == ')')brackets.pop();
				else if(match == '[' && c == ']')brackets.pop();
				else if(match == '{' && c == '}')brackets.pop();
				else return false;
			}

		}
		return brackets.empty();
	}
};

int main()
{
	Solution s;
	cout<<s.isValid("()")<<endl;
	cout<<s.isValid("()[]{}")<<endl;
	cout<<s.isValid("(]")<<endl;
	cout<<s.isValid("{[]}")<<endl;
	cout<<s.isValid("(])")<<endl;
	return 0;
}
