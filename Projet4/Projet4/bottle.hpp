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

private:
	int bottleVolume = 100;
	int bottleQuantity = bottleVolume;
	int max_quantity = 15;
	int min_quantity = 10;
	int quantityFed = 0;

	int improvisedFeed = 0;
	int timeInterval = 3; //hours
	int lastFeedingTime = 7;
	int currentTime = 8;
};