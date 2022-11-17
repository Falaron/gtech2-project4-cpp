#include "List.h"
#include <iostream>
#include <string>
using namespace std;

void List::CreateProduct() {
	cout << "product name" << endl;
	cin >> productName;
	cout << "product quantity" << endl;
	cin >> productQuantity;
	listNumber = getEmptyListPosition();
	cout << productName << " " << productQuantity << " " << listNumber << endl;
	AddProductToList(listNumber, productName, productQuantity);
}

int List::getEmptyListPosition() {
	for (int i = 0; i < 10; i++) {
		if (productList[i] == "") {
			return i;
		}
	}
}

void List::AddProductToList(int listNumber, std::string productName, int productQuantity) {
	productList[listNumber] = productName;
	productMaxQuantity[listNumber] = productQuantity;
	quantityRemaining[listNumber] = productQuantity;

	//cout << "listNumber = " << listNumber << endl;
	//cout << "product name = " << productList[listNumber] << endl;
	//cout << "product quantity = " << quantityRemaining[listNumber] << endl;
}

void List::ShowList() {
	for (int i = 0; i < 10; i++) {
		cout << productList[i] << ", ";
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << quantityRemaining[i] << ", ";
	}
	cout << endl;
}

void List::ResetList() {
	for (int i = 0; i < 10; i++) {
		productList[i] = "";
		quantityRemaining[i] = 0;
		productMaxQuantity[i] = 0;
	}
}

void List::ReduceMilkQuantity(int qty) {
	quantityRemaining[0] -= qty;
}

List::List() {
	ResetList();
}

List::~List() {

}

