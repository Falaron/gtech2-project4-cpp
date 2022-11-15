#include "bottle.hpp"
#include <iostream>
using namespace std;

Bottle::Bottle() {
	//stuff
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
	if (currentTime == lastFeedingTime + timeInterval || currentTime == lastFeedingTime + improvisedFeed) {
		lastFeedingTime = currentTime;
		Feed();
	}
}

void Bottle::Regurgited() {
	cout << "when will you feed your baby ?" << endl;
	cin >> improvisedFeed; 
}