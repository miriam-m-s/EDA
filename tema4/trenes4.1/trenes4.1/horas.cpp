#include "horas.h"
horas::horas(int h, int m, int s) : hor(h), min(m), seg(s) {
	if (!correctDate())mal = true;

}
bool horas::correctDate() const {
	bool correct;
	if (( hor< 0) || (hor > 23) || (min < 0) || (min >59) || (seg < 0) ||(seg>59))
		correct = false;
	else
		correct = true;
	return correct;
}
bool horas::estamalahora() const{
	return mal;
}
bool horas::operator<=(const horas& other)const {
	if (hor < other.hor) return true;
	else {
		if (hor == other.hor) {
			if (min < other.min)return true;
			else {
				if (min == other.min) {
					if (seg <= other.seg)return true;
					else return false;
				}
				else return false;
			}
		}
		else return false;
	}
	
}
ostream& operator<<(ostream& out, const horas& d) {
	string h = to_string(d.hor);
	string m= to_string(d.min);
	string s = to_string(d.seg);
	if (d.hor < 10)h = "0" + to_string(d.hor);
	if (d.min  < 10)m= "0" + to_string(d.min);
	if (d.seg < 10) { 
		s = "0" + to_string(d.seg); }
	out << h << " " << m << ":" << s;
	return out;
}
istream& operator>>(istream& out,  horas& d) {
	int h, m, s;
	char separar=':';
	out >> h >> separar >> m >> separar >> s;
	d = horas(h, m, s);
	return out;
}
