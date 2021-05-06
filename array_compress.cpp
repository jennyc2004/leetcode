//============================================================================
// Name        : array_compress.cpp
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
    int compress(vector<char>& chars) {
    	int charSize = chars.size();
    	if(charSize<2) return charSize;
    	int  index = 1, num = 1;
    	for(int i = 1; i < charSize; i++){
    		if(chars[i]== chars[i-1]){
    			num++;
    		}else{
    			chars[index-1] = chars[i-1];
    			if(num > 1){
    				string str = to_string(num);
    				for(char c:str) chars[index++] = c;
    			}
    			index++;
    			num = 1;
    		}
    	}
    	chars[index-1] = chars.back();
    	if(num > 1){
			string str = to_string(num);
			for(char c:str) chars[index++] = c;
		}
    	chars.erase(chars.begin() + index, chars.end());
    	return index;
    }
};

int main()
{
	Solution s;
	vector<char> chars {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
	vector<char> chars2 {'a','a','a','b','b','a','a','a'};
	cout<<s.compress(chars)<<endl;
	for(char c:chars) cout<<c;
	cout<<endl;
	cout<<s.compress(chars2)<<endl;
	for(char c:chars2) cout<<c;
	cout<<endl;
	return 0;
}
