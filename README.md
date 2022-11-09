# gtech2-project4-cpp
## GTECH2 - PROJECT 4 OF GAMING CAMPUS 2022-2023


### **Features of the software:**
- Possibility to add the hours of taking the bottle
- Possibility to add the quantity of milk ingested by the baby
- Create a reminder at variable intervals to give the bottle to his child
- Take into account the possibility that the baby regurgitates his bottle
- Create a shopping list for the baby

__

### **Structure of the program:**
```cpp
class Bottle {
	private:
		int max_capacity = 100;	//maximum quantity left in the bottle
		int actual_quantity = max_capacity;	//maximum quantity left in the bottle
		int max_quantity = 15;	//maximum amount the baby must drink
		int min_quantity = 10;	//minimum amount the baby must drink
		
		int taken_time;	//time the bottle was taken
		bool regurgigated;	//if the baby regurgitates the bottle
		int reminder;		//reminder of the next bottle to give
	public:
		Bottle();
		void refill;		//refill the bottle if there is not enough quantity in it
};

//Bottle Management
Bottle() {
	private:
		int max_capacity = 100;
		int actual_quantity = max_capacity;
		int max_quantity = 15;
		int min_quantity = 10;
		
		bool regurgigated = false;
		int taked_time = 3; //hours
	public:
		Bottle();
		Bottle(int, int, int, int);
		Print(); //print information for the parent
		Input(/* element by element */); //entered by the parent
};

//Shop Management
class ShoppingList {
	private:
		
	public:
		ShoppingList();
};
```

### **Bottle feeding**
1. Give the same amount for each feeding

2. Check if the amount for the intake is correct
	- if actual_quantity < min_quantity && not to late in the day : **Fill bottle:**
	- if **regurgitated** is true : note quantity regurgitated

4. **Reminder** after each feeding:
	- Next intake reminder = taken_time + reminder

5. **Shopping** : Runs periodically, using the same amount of milk each time
	- Keep track of necessary products
	- indicates when to boy the products
