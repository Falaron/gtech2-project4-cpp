#pragma once
#include <string>
class List
{
private:
	std::string productList [10]; //array of products name
	char shoppingList [10]; //array of products name to be shipped
	int productMaxQuantity[10]; //qty add on buy of listed product
	int quantityRemaining[10]; //qty in inventory of listed product 

	std::string productName; //product's name
	int listNumber; //number of the product in the array
	int productQuantity; //quantity of a product


public:


	~List();
	List();
	int getEmptyListPosition(); // get the listnumber of the next product
	void AddProductToList(int listNumber, std::string productName, int productQuantity); //add a product's name and quantity to the list
	void CreateProduct(); // create a product's name and quantity
	void ShowList(); //print the list in terminal
	void ResetList(); //reset every member of the array
	void ReduceMilkQuantity(int qty); //reduce the actual quantity of milk in stock 
};