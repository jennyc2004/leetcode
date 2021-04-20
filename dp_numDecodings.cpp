//============================================================================
// Name        : dp_numDecodings.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>

class Solution
{
public:
	int numDecodings(string s){
		if(s.empty() || s[0] == '0') return 0;
		int n = s.size();
		int pre = 1, cur = 1;
		//dp "116216" = way("11621") + way("1162")
		for(int i = 2; i <=n; i++){
			if(s[i-1] == '0'){
				if(s[i-2] == '1' || s[i-2] == '2') cur = pre;
				else return 0;
			}else{
				int num = stoi(s.substr(i-2, 2));
				int temp = cur;
				cur = cur + (num >= 11 && num <= 26? pre:0);
				pre = temp;
			}
		}
		return cur;
	}
};
int main()
{
	Solution s;
	cout<<s.numDecodings("116216");
	return 0;
}
