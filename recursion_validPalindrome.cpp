//============================================================================
// Name        : recursion_validPalindrome.cpp
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

class Solution {
public:
    bool validPalindrome(string s) {
    	int left = 0, right = s.size()-1;
    	return isValid(s, left, right, 0);
    }
    bool isValid(string s, int left, int right, int count){
    	if(count > 1) return false;
    	while(left < right){
    		if(s[left] == s[right]){
    			left++;
    			right--;
    		}else{
    			return isValid(s, left+1, right, count+1) || isValid(s, left, right-1, count+1);
    		}
    	}
    	return true;
    }
};

int main()
{
	Solution s;
	cout<<s.validPalindrome("aeeeee")<<endl;
	return 0;
}
