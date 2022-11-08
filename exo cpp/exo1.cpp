// exo1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
using namespace std;

// EXO 1 - introduction
/*int main()
{
    int value1, value2;
    cout << "ENTER 2 NUMBERS" << endl;
    cout << "number : "; cin >> value1;
    cout << "number : "; cin >> value2; cout << endl;

    if (value1 < 0 || value2 < 0) cout << "Result is negative";
    else cout << "Result is positive or null";
}*/

// EXO 2 - calculator
/*void Calculate(float value1, float value2, char opera)
{
    switch (opera)
    {
    case '+':
        cout << "The result is " << value1 + value2 << endl;
        break;
    case '-':
        cout << "The result is " << value1 - value2 << endl;
        break;
    case '*':
        cout << "The result is " << value1 * value2 << endl;
        break;
    case '/':
        if (value2 == 0 ? cout << "Can't divide by 0" : cout << "The result is " << value1 / value2 << endl)
        break;
    default:
        cout << "error";
        break;
    }
}



int main()
{
    //init variables
    float value1, value2;
    char opera;

    //get user inputs
    cout << "ENTER 2 NUMBERS" << endl;
    cout << "number : "; cin >> value1;
    cout << "select an operator between (+,-,*,/) : "; cin >> opera;
    cout << "number : "; cin >> value2;

    Calculate(value1, value2, opera);  //do the calculation depending of the operator
} */

// EXO 3 - calculator
/*void Permutation(int value1, int value2)
{
    int _value1 = value1;
    value1 = value2;
    value2 = _value1;

    cout << "First value changed : " << value1 << endl;
    cout << "Second value changed : " << value2 << endl;
}

int main()
{
    //init variables
    int value1, value2;

    //get user inputs
    cout << "ENTER 2 NUMBERS" << endl;
    cout << "number : "; cin >> value1;
    cout << "number : "; cin >> value2; cout << endl;

    Permutation(value1, value2); //permutate the numbers
}*/

//EXO 4 - tables
/*float sum; //init global values
int minValue, maxValue;

void CreateTable(int * tab, int sizeTab)
{
    for (auto i = 0; i < sizeTab; i++)
    {
        tab[i] = 0;
    }
}

void FillTable(int* tab, int sizeTab)
{
    int input;
    bool doOnce = true;

    for (auto i = 0; i < sizeTab; i++)
    {
        cout << "Enter the value you want to insert : "; cin >> input;
        tab[i] = input;
        sum += tab[i];
        
        if (doOnce)
        {
            minValue = input;
            maxValue == input;
            doOnce = false;
        }

        if (input < minValue) minValue = input;
        if (input > maxValue) maxValue = input;
    }
}

void PrintTable(int* tab, int sizeTab)
{
    cout << "\n\nsum of all table numbers is : " << sum << endl;
    cout << "moy of all table numbers is : " << sum / sizeTab << endl;
    cout << "standard deviation : " << maxValue - minValue << endl;
}

int main()
{
    //Init values
    int tab[100];
    int sizeTab;

    cout << "Please give table size : "; cin >> sizeTab; cout << endl;

    //Create table
    CreateTable(tab, sizeTab);
    FillTable(tab, sizeTab);
    PrintTable(tab, sizeTab);
}*/

//TESTS
int main()
{
    //Init values
    int var = 4;
    int tab[5];
    tab[1] = var;
    cout << (tab + 1) << endl;
}