#include "bottle.hpp"
#include <iostream>
#include <ctime>
using namespace std;

Bottle::Bottle() {
	cout << "Time: " << ltm->tm_hour << ":";
	cout << ltm->tm_min;
}

void Bottle::Print() {
    
}

void Bottle::ChangeVolume() {
	cout << "type the new volume of your bottle" << endl;
	cin >> bottleVolume;
}

void Bottle::Refill(int bottleQuantity) {
	if (bottleQuantity <= bottleVolume / 10) {
		cout << "milk quantity low " << endl << "please refill the bottle" << endl;
	}
}

void Bottle::Feed() {
	cout << "how much did u fed the baby ?" << endl;
	cin >> quantityFed;
	bottleQuantity -= quantityFed;
}

void Bottle::IsFeedingTime() {
	if (currentTimeH == lastFeedingTimeH + timeIntervalH && currentTimeM == lastFeedingTimeM + timeIntervalM || currentTimeH == lastFeedingTimeH + improvisedFeedH && currentTimeM == lastFeedingTimeM + improvisedFeedM) {
		lastFeedingTimeH = currentTimeH;
		lastFeedingTimeM = currentTimeM;
		Feed();
	}
}

void Bottle::Regurgited() {
	cout << "when will you feed your baby ?" << endl;
	cin >> improvisedFeedH; 
	cin >> improvisedFeedM;
}

int Bottle::GetBottleQuantity() {
	return bottleQuantity;
}

int Bottle::GetBottleVolume() {
	return bottleVolume;
}

int Bottle::GetCurrentTime() {
	return currentTimeH;
}

int Bottle::GetBabyQuantity() {
	return quantityToGive;
}

int Bottle::GetFeedIntervalH() {
	return timeIntervalH;
}

int Bottle::GetFeedIntervalM() {
	return timeIntervalM;
}