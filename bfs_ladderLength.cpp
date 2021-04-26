//============================================================================
// Name        : bfs_ladderLength.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_set<string> wordSet(wordList.begin(), wordList.end());
    	//queue for BFS
    	queue<string> wordQ;
    	wordQ.push(beginWord);
    	int result = 1;
    	while(!wordQ.empty()){
    		int n = wordQ.size();
    		//each level of BFS
    		for(int i = 0; i < n; i++){
    			string word = wordQ.front();
    			wordQ.pop();
    			//shortest path of BFS
    			if(word == endWord) return result;
    			wordSet.erase(word);
    			//go through each letter
    			for(int j = 0; j < word.size(); j++){
    				char c = word[j];
    				for(int k = 0; k < 26; k++){
    					word[j] = 'a' + k;
    					if(wordSet.find(word) != wordSet.end())wordQ.push(word);
    				}
    				//change back to the original word
    				word[j] = c;
    			}
    		}
    		result++;
    	}
    	return 0;
    }
};


int main()
{
	Solution s;
	vector<string> wordList {"hot","dot","dog","lot","log","cog"};
	cout<<s.ladderLength("hit", "cog", wordList);
	return 0;
}
