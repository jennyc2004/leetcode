//============================================================================
// Name        : math_addStrings.cpp
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

class Solution {
public:
    string addStrings(string num1, string num2) {
    	int m = num1.size(), n = num2.size();
    	int c = 0;
    	string result = "";
    	for (int i = m - 1, j = n - 1; i >= 0 || j >= 0 || c; i--, j--) {
    		int a = i >= 0? num1[i] - '0':0;
    		int b = j >= 0? num2[j] - '0':0;
    		int sum = a + b + c;
    		c = sum /10;
    		result = to_string(sum%10) + result;
    	}
    	return result;
    }
};
int main()
{
	Solution s;
	cout<<s.addStrings("12", "123")<<endl;
	return 0;
}
