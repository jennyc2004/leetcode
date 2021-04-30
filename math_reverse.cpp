//============================================================================
// Name        : math_reverse.cpp
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
    int reverse(int x) {
    	long long result = 0;
    	while(x){
    		result = result*10 + x%10;
    		x = x/10;
    	}
		return (result < INT_MIN || result > INT_MAX)? 0:result;
    }
};
int main()
{
	Solution s;
	cout<<s.reverse(120)<<endl;
	return 0;
}
