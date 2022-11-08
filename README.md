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
		int quantity;		//max capacity of the bottle
		int actual_quantity;	//maximum quantity left in the bottle
		int min_quantity;	//minimum amount the baby must drink
		char taken_time;	//time the bottle was taken
		bool regurgigated;	//if the baby regurgitates the bottle
		int reminder;		//reminder of the next bottle to give
	public:
		void refill;		//refill the bottle if there is not enough quantity in it
};
```

### **Bottle feeding**
1. Give the same amount for each feeding

2. Check if the amount for the intake is correct
	- if actual_quantity < min_quantity : **Fill bottle:**
	- if **regurgitated** is true : note quantity regurgitated

4. **Reminder** after each feeding:
	- Next intake reminder = taken_time + reminder