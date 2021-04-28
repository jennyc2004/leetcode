//============================================================================
// Name        : dp_longestPalindrome.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int largestLen(string s, int left, int right){
        while(left >=0 && right < s.size() && s[left] == s[right]){
        	left--;
        	right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
    	int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
        	int len = max(largestLen(s, i, i), largestLen(s, i, i+1));
        	if(len > end - start + 1){
        		start = i - (len-1)/2;
        		end = start + len - 1;
        	}
        }
        return s.substr(start, end-start+1);
    }
};
int main()
{
	Solution s;
	cout<<s.longestPalindrome("cbbd")<<endl;
	cout<<s.longestPalindrome("babad")<<endl;
	return 0;
}
