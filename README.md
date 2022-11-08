# gtech2-project4-cpp
## GTECH2 - PROJECT 4 OF GAMING CAMPUS 2022-2023


**Features of the software:**
- Possibility to add the hours of taking the bottle
- Possibility to add the quantity of milk ingested by the baby
- Create a reminder at variable intervals to give the bottle to his child
- Take into account the possibility that the baby regurgitates his bottle
- Create a shopping list for the baby

**Structure of the program:**
```cpp
class Biberon {
	private:
		int quantity;			//capacité max du biberon
		int actual_quantity;	//quantité max restante dans le biberon
		char taken_time;		//heure prise du biberon
		bool regurgigated;		//si le bébé régurgite le biberon
		int reminder;			//rappel du prochain biberon à donner
	
	public:
		void refill;			//remplir le biberon s'il n'y a pas assez de quantité dedans
};

//
```