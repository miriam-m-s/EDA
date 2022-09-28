#include "iPud.h"

void iPud::addSong(string tit, string aut, int dur)
{
	if (!ipud.count(tit)) {
		ipud[tit].duration = dur;
	}
	else throw invalid_argument("addSong");
	
}

void iPud::addToPlaylist(string S)
{
	if (ipud.count(S)) {
		if (!ipud[S].playlist) {
			playlist.push_back(S);
			ipud[S].playlist = true;
			time += ipud[S].duration;
			list<string>::iterator it = playlist.end(); --it;
			ipud[S].il = it;


		}
	}
	else {
		throw invalid_argument("addToPlaylist");
	}
}

string iPud::current()
{
	if (!playlist.empty()) {
		list<string>::iterator it = playlist.begin();
		return *it;
	}
	else {
		throw invalid_argument("current");
	}

}

void iPud::play()
{
	if (!playlist.empty()) {
		list<string>::iterator it = playlist.begin();
		string song = *it;
		time -= ipud[song].duration;
		ipud[song].playlist = false;
		it = playlist.erase(it);
		if (ipud[song].reproducidas)reproducidas.erase(ipud[song].rep);
		ipud[song].reproducidas = true;
	
		reproducidas.push_front(song);
		list<string>::iterator il = reproducidas.begin();
		ipud[song].rep = il;
	}
	
}

int iPud::totalTime()
{

	return time;
}

list<string> iPud::recent(int N)
{
	if (N >= reproducidas.size())return reproducidas;
	list<string>canciones;
	list<string>::iterator rep = reproducidas.begin();
	for (int i = 0; i < N; i++) {
		canciones.push_back(*rep);
		++rep;
	}
	return canciones;
	
}

void iPud::deleteSong(string S)
{
	if (ipud.count(S)) {
		if (ipud[S].reproducidas) {
			 reproducidas.erase(ipud[S].rep);
			 
		}
		if (ipud[S].playlist) {
			playlist.erase(ipud[S].il);
			time -= ipud[S].duration;
		}
		

		ipud.erase(S);
	}
}
