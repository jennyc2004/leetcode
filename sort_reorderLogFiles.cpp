//============================================================================
// Name        : sort_reorderLogFiles.cpp
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
#include <unordered_set>
#include <sstream>

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> result, digitlogs;
        vector<pair<string, string>> letterlogs;
        for(string log:logs){
            int i = 0;
            while(log[i] != ' ')i++;
            if(isalpha(log[i+1])) letterlogs.push_back({log.substr(0, i), log.substr(i+1)});
            else digitlogs.push_back(log);
        }
        sort(letterlogs.begin(), letterlogs.end(), [](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });
        for(auto letterlog:letterlogs)result.push_back(letterlog.first + " " + letterlog.second);
        for(auto digitlog:digitlogs)result.push_back(digitlog);
        return result;
    }
};
int main()
{
	Solution s;
	vector<string> logs{"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
	vector<string> result = s.reorderLogFiles(logs);
	for(string s:result)cout<<s<<",";
	cout<<endl;
	return 0;
}
