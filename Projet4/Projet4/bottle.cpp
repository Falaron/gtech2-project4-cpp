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

void Bottle::Refill() {
	bottleQuantity = bottleVolume;
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

int Bottle::GetFeedTimeLeftH() {
	return feedTimeLeftH;
}

int Bottle::SetBottleVolume(int value) {
	bottleVolume = value;
	return bottleVolume;
}