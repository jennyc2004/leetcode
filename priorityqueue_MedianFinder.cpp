//============================================================================
// Name        : priorityqueue_MedianFinder.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <queue>

class MedianFinder {
private:
	priority_queue<int> first;//largest on top
	priority_queue<int,vector<int>, greater<int> > second; //smallest on top
public:
    /** initialize your data structure here. */
    MedianFinder() {}

    void addNum(int num) {
    	if(first.empty() || first.top() > num) first.push(num);
    	else second.push(num);
    	if(first.size() > second.size() + 1){
    		second.push(first.top());
    		first.pop();
    	}
    	if(second.size() > first.size() + 1){
    		first.push(second.top());
    		second.pop();
    	}
    }

    double findMedian() {
    	if(first.empty() && second.empty()) return 0;
    	if(first.size() == second.size()) return (first.top() + second.top())/2.0;
    	else return first.size()>second.size()? first.top(): second.top();

    }
};


int main()
{
	MedianFinder f;
	f.addNum(1);
	f.addNum(2);
	cout<<f.findMedian()<<endl;
	f.addNum(3);
	cout<<f.findMedian()<<endl;
	return 0;
}
