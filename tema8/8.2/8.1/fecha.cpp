#include "fecha.h"

fecha::fecha(int h, int m, int s) : d(h), h(m), m(s) {


}


bool fecha::operator<(const fecha& other)const {
	if (d < other.d) return true;
	else {
		if (d == other.d) {
			if (h < other.h)return true;
			else {
				if (h == other.h) {
					if (m < other.m)return true;
					else return false;
				}
				else return false;
			}
		}
		else return false;
	}

}

bool fecha::operator==(const fecha& other) const
{
	if (d == other.d&&h==other.h&&m==other.m) return true;
	else {
		
		 return false;
	}
}

bool fecha::operator!=(const fecha& other) const
{
	if (d == other.d && h == other.h && m == other.m) return false;
	else {

		return true;
	}
}

ostream& operator<<(ostream& out, const fecha& day) {
	string h = to_string(day.d);
	string m = to_string(day.h);
	string s = to_string(day.m);
	if (day.d < 10)h = "0" + to_string(day.d);
	if (day.h < 10)m = "0" + to_string(day.h);
	if (day.m < 10) {
		s = "0" + to_string(day.m);
	}
	out  << m << ":" << s;
	return out;
}
istream& operator>>(istream& out, fecha& d) {
	int h, m, s;
	char separar = ':';
	char camb = ' ';
	out >> h >> camb >> m >> separar >> s;
	d = fecha(h, m, s);
	return out;
}
