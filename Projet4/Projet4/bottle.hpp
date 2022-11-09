#pragma once

class Bottle {
public:
	Bottle();
	Bottle(int taked_time, int min_quantity, int max_quantity, int max_bottle);

	void Print(); //print informations
	//void Input(/* element by element */);

private:
	int max_bottle = 100;
	int actual_quantity = max_bottle;
	int max_quantity = 15;
	int min_quantity = 10;

	bool regurgigated = false;
	int taked_time = 3; //hours
};