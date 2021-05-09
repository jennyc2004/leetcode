//============================================================================
// Name        : map_isAlienSorted.cpp
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
    bool isAlienSorted(vector<string>& words, string order) {
    	unordered_map<char, int> orderMap;
    	for(int i = 0; i < order.size(); i++){
    		orderMap[order[i]] = i;
    	}
    	for(string &s:words){
    		for(char &c:s){
    			c = orderMap[c] + 'a';
    		}
    	}
    	return is_sorted(words.begin(), words.end());
    }
};

int main()
{
	Solution s;
	vector<string> words {"leetcode", "hello"};
	string order = "hlabcdefgijkmnopqrstuvwxyz";
	cout<<s.isAlienSorted(words, order)<<endl;
	return 0;
}
