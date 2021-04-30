//============================================================================
// Name        : templatefunctionpointer_binarycalculator.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <functional>

unordered_map<string, function<int(int, int)> > integer_operators;
unordered_map<string, function<string(string, string)> > string_operators;

class Solution {
public:
    void populateOperators(){
    	integer_operators["add"] = [](int x, int y){return x+y;};
    	integer_operators["sub"] = [](int x, int y){return x-y;};
    	integer_operators["bitwise_and"] = [](int x, int y){return x&y;};
    	integer_operators["bitwise_or"] = [](int x, int y){return x|y;};
    	integer_operators["bitwise_xor"] = [](int x, int y){return x^y;};
    	string_operators["pre_concat"] = [](string x, string y){return x+y;};
    	string_operators["post_concat"] = [](string x, string y){return y+x;};
    }
    template <typename T>
    T customeAccumulate(vector<T> vec, function<T(T, T)> op1, function<T(T, T)> op2){
    	T result = vec[0];
    	int option = -1;
    	for(int i = 1; i < vec.size(); i++){
    		if(option == -1) result = op1(result, vec[i]);
    		else result = op2(result, vec[i]);
    		option = -1*option;
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	vector<int> nums{1, 2, 3, 4, 5};
	vector<string> strs{"abc", "def", "ghi", "jkl", "mno"};
	s.populateOperators();
	cout<<integer_operators["add"](3, 1)<<endl;
	cout<<integer_operators["sub"](3, 1)<<endl;
	cout<<integer_operators["bitwise_and"](3, 1)<<endl;
	cout<<integer_operators["bitwise_or"](3, 1)<<endl;
	cout<<integer_operators["bitwise_xor"](3, 1)<<endl;
	cout<<s.customeAccumulate(nums, integer_operators["add"], integer_operators["sub"])<<endl;
	cout<<s.customeAccumulate(strs, string_operators["pre_concat"], string_operators["post_concat"])<<endl;
	return 0;
}
