//============================================================================
// Name        : map_productExceptSelf.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>
class Solution {
public:
	int lengthOfLongestSubstring(string s){
		unordered_map<char, int> letters;
		int n = s.size(), maxLen = 0, start = 0;
		for(int i = 0; i < n; i++){
			char c = s[i];
			// update new start if repeated letter seen
			if(letters.find(c) != letters.end() && letters[c] + 1 > start) start = letters[c] + 1;
			maxLen = max(maxLen, i - start+1);
			letters[c] = i;
		}
		return maxLen;
	}
};

int main()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("abcabcbb")<<endl;
	cout<<s.lengthOfLongestSubstring("pwwkew")<<endl;
	cout<<s.lengthOfLongestSubstring("abba")<<endl;
	cout<<s.lengthOfLongestSubstring(" ")<<endl;
	return 0;
}
