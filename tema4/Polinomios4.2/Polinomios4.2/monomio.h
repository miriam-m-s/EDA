#pragma once
class monomio
{
protected:
	int base;
	int exponente;
public:
	monomio() {};
	monomio(int b, int exp);
	int getbase() { return base; }
	int getexp() { return exponente; }
	monomio operator+(const monomio& other) {
		
		int sumbase = base + other.base;
		monomio m=monomio(sumbase,exponente);
		return m;
		
	}
};

