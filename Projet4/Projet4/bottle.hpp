#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

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
	int GetFeedIntervalH();
	int GetFeedIntervalM();

private:
	int bottleVolume = 250;
	int bottleQuantity = bottleVolume;
	int quantityToGive = 135;
	int quantityFed = 0;

	time_t now = time(0);
	tm* ltm = localtime(&now);


	int improvisedFeedH = 0; //improvised consumable time interval in hours
	int improvisedFeedM = 0; //improvised consumable time interval in minutes
	int timeIntervalH = 3; //must feed every interval time in hours
	int timeIntervalM = 0; //must feed every interval time in minutes
	int lastFeedingTimeH = 7; //time when last fed in hours
	int lastFeedingTimeM = 30;//time when last fed in minutes 
	int currentTimeH = ltm->tm_hour; //computer's hours
	int currentTimeM = ltm->tm_min;  //computer's minutes
};