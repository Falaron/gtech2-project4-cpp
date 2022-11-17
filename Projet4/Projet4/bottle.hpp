#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>

class Bottle {
public:
	//constructor
	Bottle();
	//check if it's feeding time
	void IsFeedingTime();
	//substract quantity fed to bottle quantity
	void Feed();
	//refill quantity bottle to volume bottle
	void Refill();
	//change volume bottle to int in parameter
	int SetBottleVolume(int);
	//create a new timestamp to feed after regurgitation
	void Regurgited();

	void Print(); //print informations
	//void Input(/* element by element */);

		//those are function to get Bottle's variables//
	int GetBottleQuantity();
	int GetBottleVolume();
	int GetCurrentTime();
	int GetBabyQuantity();
	int GetFeedIntervalH();
	int GetFeedIntervalM();
	int GetFeedTimeLeftH();

	
private:
	//maximum volume of the bottle
	int bottleVolume = 250;
	//milk quantity in the bottle 
	int bottleQuantity = bottleVolume;
	//quantity to give to the baby
	int quantityToGive = 135;
	//quantity of milk given to the baby
	int quantityFed = 0;

	  //get time//
	time_t now = time(0);
	tm* ltm = localtime(&now);


	int improvisedFeedH = 0; //improvised consumable time interval in hours
	int improvisedFeedM = 0; //improvised consumable time interval in minutes
	int timeIntervalH = 3; //must feed every interval time in hours
	int timeIntervalM = 0; //must feed every interval time in minutes
	int lastFeedingTimeH = 9; //time when last fed in hours
	int lastFeedingTimeM = 30;//time when last fed in minutes 
	int currentTimeH = ltm->tm_hour; //computer's hours
	int currentTimeM = ltm->tm_min;  //computer's minutes
	int feedTimeLeftH = - currentTimeH + lastFeedingTimeH + timeIntervalH; //time left until the alarm in hours
	int feedTimeLeftM = - currentTimeM + lastFeedingTimeM + timeIntervalM; //time left until the alarm in minutes
};