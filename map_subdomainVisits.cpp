//============================================================================
// Name        : map_subdomainVisits.cpp
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
    vector<string> subdomainVisits(vector<string>& cpdomains) {
    	vector<string> result;
    	unordered_map<string, int> countDomains;
    	for(string s: cpdomains){
    		int i = s.find(" ");
    		int n = stoi(s.substr(0, i));
    		string str = s.substr(i+1);
    		for(int i = 0; i < str.size(); i++){
    			if(str[i] == '.') countDomains[str.substr(i+1)] += n;
    		}
    		countDomains[str] += n;
    	}
    	for(auto count:countDomains){
    		result.push_back(to_string(count.second) + " " + count.first);
    	}
    	return result;
    }
};

int main()
{
	Solution s;
	vector<string> cpdomains {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	vector<string> result = s.subdomainVisits(cpdomains);
	for(string s:result) cout<<s<<",";
	cout<<endl;
	return 0;
}
