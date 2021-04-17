//============================================================================
// Name        : string_fullJustify.cpp
// Author      : Jenny Cheng
// Version     :
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>

class Solution
{
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result {};
		int start = 0, end = 0;
		while(end < words.size()){
			//insert space in front of each word.
			int len = -1;
			while(end < words.size() && len + words[end].size() + 1 <= maxWidth){
				len += words[end++].size() + 1;
			}
			int k = start;
			int space = maxWidth - len + end - start - 1;
			while(space){
				words[k++] += " ";
				space--;
				if(end != words.size() && (k == end - 1 || k == end)) k = start;
				if(end == words.size() && k == end) k = end - 1;
			}
			string line = "";
			for(int l = start ; l < end; l++){
				line += words[l];
			}
			result.push_back(line);
			start = end;
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<string> words {"This", "is", "an", "example", "of", "text", "justification."};
	int maxWidth = 16;
	vector<string> result = s.fullJustify(words, maxWidth);
	for(string s: result)cout<<s<<endl;
	return 0;
}
