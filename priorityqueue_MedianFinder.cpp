//============================================================================
// Name        : priorityqueue_MedianFinder.cpp
// Author      : Jenny Cheng
// Copyright   : Your copyright notice
//============================================================================
using namespace std;
#include <iostream>
#include <queue>

class UndergroundSystem {
public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {

    }

    void checkOut(int id, string stationName, int t) {

    }

    double getAverageTime(string startStation, string endStation) {

    }
};

int main()
{
	UndergroundSystem s;
	s.checkIn(45, "Leyton", 3);
	s.checkIn(32, "Paradise", 8);
	s.checkIn(27, "Leyton", 10);
	s.checkOut(45, "Waterloo", 15);
	s.checkOut(27, "Waterloo", 20);
	s.checkOut(32, "Cambridge", 22);
	cout<<s.getAverageTime("Paradise", "Cambridge")<<endl;
	s.checkIn(10, "Leyton", 24);
	cout<<s.getAverageTime("Leyton", "Waterloo")<<endl;
	s.checkOut(10, "Waterloo", 38);
	cout<<s.getAverageTime("Leyton", "Waterloo")<<endl;

	return 0;
}
