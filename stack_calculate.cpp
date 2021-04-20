//============================================================================
// Name        : stack_calculate.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
    	stack<int> opStack;
    	//push global and first + sign
    	opStack.push(1);
    	opStack.push(1);
    	int n = s.size();
    	int result = 0;
    	for(int i = 0; i < n; i++){
    		char c = s[i];
    		//get number
    		if(isdigit(c)){
    			int start = i;
    			while(i < n && isdigit(s[i]))i++;
    			result += opStack.top()*stoi(s.substr(start, i-start));
    			opStack.pop();
    			i--;
    		}else if(c == ')') opStack.pop();//pop the last sign
    		// ( and + will keep the previous sign, - will negative the previous sign.
    		else if(c != ' ') opStack.push(opStack.top() * (c == '-'? -1 : 1));
    	}
        return result;
    }
};

int main()
{
	Solution s;
	cout<<s.calculate("3-(2+(9-4))");
	return 0;
}
