#ifndef _PATH_H_
#define _PATH_H_
#include "Coord.h"
#include "Absis.h"

#include <iostream>

using namespace std;

class Path {
public:
	Path();
	Path(Absis<Coord> path);
	Coord getCoordAt(int index)const;
	int getLength()const;
	int getCost();
	int setCost(int cost);
	void setValid(bool valid);
	bool getValid();
	Absis<Coord> getPath();
	void print();
private:
	Absis<Coord> path;
	int cost = 254;
	bool valid = false;
};
#endif