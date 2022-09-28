#pragma once
#include <iostream>
using namespace std;
#include <string>  
class horas
{
private:
	int hor, min, seg;
	bool mal = false;
	bool correctDate() const;

public:
	horas() {};
	horas(int d, int m, int y);
	bool estamalahora()const;
	
	bool operator<=(const horas& other) const;
	friend ostream& operator<<(ostream& out, const horas& d);
	friend istream& operator>>(istream& out,  horas& d);
};

