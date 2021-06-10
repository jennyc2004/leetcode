//============================================================================
// Name        : math_calculate.cpp
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
    int calculate(string s) {
    	int i = 0, result = 0, cur = 0;
    	char op = '+';
    	while(i < s.size()){
    		if(isdigit(s[i])){
    			int index = i, num = 0;
    			while(i < s.size() && isdigit(s[i]))i++;
    			num = stoi(s.substr(index, i-index));
    			if(op == '+' || op == '-'){
    				result += cur;
    				cur = num *(op == '-'? -1:1);
    			}else if(op == '*') cur *= num;
    			else if(op == '/') cur /= num;
    		}else{
    			if(s[i] != ' ') op = s[i];
    			i++;
    		}
    	}
    	result += cur;
    	return result;
    }
};

int main()
{
	Solution s;
	cout<<s.calculate("3+3/2")<<endl;
	return 0;
}
