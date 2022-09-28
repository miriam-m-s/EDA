#pragma once
#include <iostream>
using namespace std;
#include <string>  
class fecha
{
private:
	int d, h, m;
public:
	fecha() {};
	fecha(int d, int h, int m);
	bool operator<(const fecha& other) const;
	bool operator==(const fecha& other) const;
	bool operator!=(const fecha& other) const;
	int dia() { return d; }
	friend ostream& operator<<(ostream& out, const fecha& d);
	friend istream& operator>>(istream& out, fecha& d);
};

