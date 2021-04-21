//============================================================================
// Name        : math_consecutiveNumbersSum.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <string>
#include <stack>

class Solution {
public:
    int consecutiveNumbersSum(int N) {
    	int result = 0;
    	//3, 4 , 5==> 1,2,3+1,1,1+1,1,1
    	for(int i = 1; i*(i+1)/2 <= N; i++){
    		if ((N-i*(i+1)/2)%i == 0) result++;
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	cout<<s.consecutiveNumbersSum(15)<<endl;
	cout<<s.consecutiveNumbersSum(9)<<endl;
	cout<<s.consecutiveNumbersSum(5)<<endl;
	return 0;
}
