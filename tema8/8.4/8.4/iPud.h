#pragma once
#include<vector>
#include <iostream>
using namespace std;
#include <string>  
#include <list>  
using song = string;
using artist = string;
using puntuacion = int;
#include <map>;
#include<list>

struct hey {
	int t;
	list<string>::reverse_iterator id;
	list<string>::iterator it;
	bool playlist;
	bool repr;
};
using ipud = map<song, hey>;
class iPud
{
private:
	//unordered_map<song,int>playlist;
	list<song>playlist;
	ipud consult;
	int totaltim;
	list<song>reprodu;
	
public:
	iPud() { totaltim = 0; }
	~iPud() {};
	void addSong(song S, artist  A, int D);
	void addToPlaylist(song S);
	song current();
	void play();
	int totalTime();
	list<song>recent(int N);
	void deleteSong(song S);
};

