//============================================================================
// Name        : map_TweetCounts.cpp
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

class TweetCounts {
private:
	unordered_map<string, vector<int> > tweetMap;
	unordered_map<string, int> freqMap = {{"minute", 60}, {"hour", 3600}, {"day", 86400}};
public:
    TweetCounts() {}

    void recordTweet(string tweetName, int time) {
    	tweetMap[tweetName].push_back(time);
    }

    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
    	int n = (endTime-startTime) / freqMap[freq] + 1;
    	vector<int> result(n, 0);
    	for(int time: tweetMap[tweetName]){
    		if(time >= startTime && time <= endTime){
    			int index = (time - startTime) /freqMap[freq];
    			result[index]++;
    		}
    	}
    	return result;
    }
};
int main()
{
	TweetCounts tweetCounts;
	tweetCounts.recordTweet("tweet3", 0);                              // New tweet "tweet3" at time 0
	tweetCounts.recordTweet("tweet3", 60);                             // New tweet "tweet3" at time 60
	tweetCounts.recordTweet("tweet3", 10);                             // New tweet "tweet3" at time 10
	vector<int> result = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 59); // return [2]; chunk [0,59] had 2 tweets
	for(int v:result)cout<<v<<",";
	cout<<endl;
	result = tweetCounts.getTweetCountsPerFrequency("minute", "tweet3", 0, 60); // return [2,1]; chunk [0,59] had 2 tweets, chunk [60,60] had 1 tweet
	for(int v:result)cout<<v<<",";
	cout<<endl;
	tweetCounts.recordTweet("tweet3", 120);                            // New tweet "tweet3" at time 120
	result = tweetCounts.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);  // return [4]; chunk [0,210] had 4 tweets
	for(int v:result)cout<<v<<",";
	cout<<endl;
	return 0;
}
