//============================================================================
// Name        : random_findSecretWord.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>

  class Master {
    public:
      int guess(string word){return 0;};
  };

class Solution {
private:
	  int match(string a, string b){
		  int result = 0;
		  for(int i = 0; i < a.size(); i++){
			  if(a[i] == b[i]) result++;
		  }
		  return result;
	  }
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
    	random_shuffle(wordlist.begin(), wordlist.end());
    	for(int i = 0, x = 0; i < 10 && x < 6; i++){
    		string word = wordlist[0];
    		x = master.guess(word);
    		vector<string> wordlist2;
    		for(string s: wordlist){
    			if(match(s, word) == x) wordlist2.push_back(s);
    		}
    		wordlist = wordlist2;
    	}
    }
};

int main()
{
	Solution s;
	string secret = "acckzz";
	vector<string> wordlist {"acckzz","ccbazz","eiowzz","abcczz"};
	Master master;
	s.findSecretWord(wordlist, master);
	return 0;
}
