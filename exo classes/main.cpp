// Classes exos.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
#include "rationnel.h"

int main()
{
	R r;
	R r1(2, 3);
	R r2(3, 5);

	r.Sum(r1, r2);
	r.Print();
}