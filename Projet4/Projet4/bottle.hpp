#pragma once

class Bottle {
public:
	Bottle();
	void IsFeedingTime();
	void Feed();
	void Refill(int bottleQuantity);
	void ChangeVolume();
	void Regurgited();

	void Print(); //print informations
	//void Input(/* element by element */);

	int GetBottleQuantity();
	int GetBottleVolume();
	int GetCurrentTime();
	int GetBabyQuantity();
	int GetFeedInterval();

private:
	int bottleVolume = 250;
	int bottleQuantity = bottleVolume;
	int quantityToGive = 135;
	int quantityFed = 0;

	int improvisedFeed = 0;
	int timeInterval = 3; //hours
	int lastFeedingTime = 7;
	int currentTime = timeInterval;
};