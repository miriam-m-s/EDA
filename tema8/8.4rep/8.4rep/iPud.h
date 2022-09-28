#pragma once
#include <iostream>
#include<map>
#include<list>
using namespace std;

struct cancion {
	int duration;
	bool playlist = false;
	bool reproducidas = false;
	list<string>::iterator il;
	list<string>::iterator rep;
};
using Ipud = map<string, cancion>;
class iPud
{
	int time=0;
	list<string>playlist;
	list<string>reproducidas;
	Ipud ipud;
public:
	iPud() {};
	~iPud() {

	}
	void addSong(string tit, string aut, int dur);
	void addToPlaylist(string S);
	string current();
	void play();
	int totalTime();
	list<string>recent(int N);
	void deleteSong(string S);
};

