//============================================================================
// Name        : map_romanToInt.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int romanToInt(string s) {
    	unordered_map<string, int> romans{{"I",1}, {"V",5}, {"X",10}, {"L",50}, {"C",100}, {"D",500}, {"M",1000},
    	{"IV",4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
    	int result = 0;
    	for(int i = 0; i < s.size(); i++){
    		if( i+1 < s.size() && romans.find(s.substr(i, 2)) != romans.end()){
    			result += romans[s.substr(i++, 2)];
    		}else{
    			result += romans[s.substr(i,1)];
    		}
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	cout<<s.romanToInt("LVIII")<<endl;
	return 0;
}
