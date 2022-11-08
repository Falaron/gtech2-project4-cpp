#include <iostream>
#include "rationnel.h"
using namespace std;

R::R() {
	n = 0;
	d = 1;
}

R::R(int a, int b) {
	n = a;
	d = b;
}

void R::Print() {
	cout << "n / d = " << n << "/" << d << endl;
}

void R::Sum(const R& r1, const R& r2) {
	n = r1.n * r2.d + r1.d * r2.n;
	d = r1.d * r2.d;
}
