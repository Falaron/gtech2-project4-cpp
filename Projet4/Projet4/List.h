#pragma once
class List
{
private:
	char productList [10]; //products name
	char shoppingList [10]; //
	int productMaxQuantity[10]; //qty add on buy of listed product
	int quantityRemaining[10]; //qty in inventory of listed product 


	char productName;
	int listNumber;
	int productQuantity;


public:


	~List();
	List();
	int getEmptyListPosition();
	void AddProductToList(int listNumber, char productName, int productQuantity);
	void CreateProduct();
	void ShowList();
	void ResetList();
	void ReduceMilkQuantity(int qty);
};