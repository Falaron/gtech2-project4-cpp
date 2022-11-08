#pragma once

class R
{
public:
	R();
	R(int, int);

	void Print();
	void Sum(const R&, const R&);

protected:
	int n, d;
};