#include "iPud.h"

void iPud::addSong(song S, artist A, int D)
{
	if (!consult.count(S)) {
		consult[S].t = D;
		consult[S].playlist = false;
		consult[S].repr = false;
	}
		
	else throw invalid_argument("addSong");
}

void iPud::addToPlaylist(song S)
{
	if (consult.count(S)) {
		
		if (!consult[S].playlist) {
			consult[S].playlist = true;
			int punt = consult[S].t;
			totaltim += punt;
			playlist.push_back(S);
			consult[S].id = playlist.rbegin();
		}
				
	}
	else {
		throw invalid_argument("addToPlaylist");
	}
}

song iPud::current()
{
	if (!playlist.empty()) {
		list<artist>::iterator ir = playlist.begin();
		return *ir;
	}
	else throw invalid_argument("current");
}

void iPud::play()
{
	if (!playlist.empty()) {

		list<artist>::iterator ir = playlist.begin();
		song h = *ir;
		int temp = consult[h].t;
		consult[h].playlist = false;
		ir = playlist.erase(ir);
		totaltim =totaltim-temp;
		if (!consult[h].repr) {
			reprodu.push_front(h);
			list<song>::iterator is = reprodu.begin();
			consult[h].it = is;
			consult[h].repr = true;
		}
		else {
			list<song>::iterator is = consult[h].it;
			is = reprodu.erase(is);
			reprodu.push_front(h);
			list<song>::iterator id = reprodu.begin();
			consult[h].it = id;
			consult[h].repr = true;
		}
		
	}
}

int iPud::totalTime()
{
	return totaltim;
}

list<song> iPud::recent(int N)
{
	if (reprodu.size() < N)return reprodu;
	list<song>copia;
	list<song>::iterator is = reprodu.begin();
	for (int i = 0; i < N; i++) {
		copia.push_back(*is);
		++is;
	}
	return copia;
}

void iPud::deleteSong(song S)
{
	if (consult[S].playlist) {
		int temp = consult[S].t;
		totaltim =totaltim-temp;
		list<string>::iterator in=playlist.begin();
		bool hey = true;
		while (in != playlist.end() && hey) {
			if (*in == S) {
				in = playlist.erase(in);
				hey = false;
			}
			else ++in;
		}
	
	}
	if (consult[S].repr) {
		list<song>::iterator is = consult[S].it;
		is = reprodu.erase(is);
	}
	if (consult.count(S))
		consult.erase(S);
}
