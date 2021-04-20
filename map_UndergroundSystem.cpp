//============================================================================
// Name        : map_UndergroundSystem.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <unordered_map>

class UndergroundSystem {
private:
	unordered_map<int, pair<string, int> > checkinMap;//id, start station and checkin time
	unordered_map<string, pair<int, int> > checkOutMap;//start+end station, total duration time, total counts
public:
    UndergroundSystem() {}

    void checkIn(int id, string stationName, int t) {
    	checkinMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t) {
    	string checkinStation = checkinMap[id].first;
    	int duration = checkOutMap[checkinStation+"-"+stationName].first + t - checkinMap[id].second;
    	int count = checkOutMap[checkinStation+"-"+stationName].second + 1;
    	checkOutMap[checkinStation+"-"+stationName] = {duration, count};
    }

    double getAverageTime(string startStation, string endStation) {
    	string temp = startStation + "-" + endStation;
    	return (double)checkOutMap[temp].first/checkOutMap[temp].second;
    }
};



int main()
{
	UndergroundSystem undergroundSystem;
	undergroundSystem.checkIn(45, "Leyton", 3);
	undergroundSystem.checkIn(32, "Paradise", 8);
	undergroundSystem.checkIn(27, "Leyton", 10);
	undergroundSystem.checkOut(45, "Waterloo", 15);
	undergroundSystem.checkOut(27, "Waterloo", 20);
	undergroundSystem.checkOut(32, "Cambridge", 22);
	cout<<undergroundSystem.getAverageTime("Paradise", "Cambridge")<<endl;
	cout<<undergroundSystem.getAverageTime("Leyton", "Waterloo")<<endl;
	undergroundSystem.checkIn(10, "Leyton", 24);
	cout<<undergroundSystem.getAverageTime("Leyton", "Waterloo")<<endl;
	undergroundSystem.checkOut(10, "Waterloo", 38);
	cout<<undergroundSystem.getAverageTime("Leyton", "Waterloo")<<endl;
	return 0;
}
