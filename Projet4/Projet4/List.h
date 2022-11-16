#pragma once
#include <string>
class List
{
private:
	std::string productList [10]; //products name
	char shoppingList [10]; //
	int productMaxQuantity[10]; //qty add on buy of listed product
	int quantityRemaining[10]; //qty in inventory of listed product 

	std::string astring;
	std::string productName;
	int listNumber;
	int productQuantity;


public:


	~List();
	List();
	int getEmptyListPosition();
	void AddProductToList(int listNumber, std::string productName, int productQuantity);
	void CreateProduct();
	void ShowList();
	void ResetList();
	void ReduceMilkQuantity(int qty);
};