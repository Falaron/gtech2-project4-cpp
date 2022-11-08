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
class Biberon {
	private:
		int quantity;		//capacité max du biberon
		int actual_quantity;		//quantité max restante dans le biberon
		int min_quantity;		//quantité minimum que le bébé doit boire
		char taken_time;		//heure prise du biberon
		bool regurgigated;		//si le bébé régurgite le biberon
		int reminder;		//rappel du prochain biberon à donner
	
	public:
		void refill;		//remplir le biberon s'il n'y a pas assez de quantité dedans
};
```

### **Prise de biberon**
1. Vérifier que la quantité pour la prise est bonne
	- **Remplissage du biberon :** Remplir le biberon si : actual_quantity < min_quantity
2. Donner la même quantité à chaque prise de biberon
3. **Rappel** après chaque prise :
	- Prochain rappel de prise = taken_time + reminder