#include "Edge.h"
#include <iostream>
using namespace std;

Edge::Edge() {
	start = 0;
	finish = 0;
	weight = 0;
}

Edge::Edge(int x, int y, int z)
{
	start = x;
	finish = y;
	weight = z;
}

Edge::~Edge()
{
	
}

int Edge::getstart()
{
	return start;
}

int Edge::getfinish()
{
	return finish;
}

int Edge::getweight()
{
	return weight;
}

void Edge::setstart(int x)
{
	start = x;
}

void Edge::setfinish(int x)
{
	finish = x;
}

void Edge::setweight(int x)
{
	weight = x;
}

bool Edge::isequal(const Edge &other)
{
	if (start == other.getstart() && finish == other.getfinish() && weight == other.getweight())
		return true;
	else
		return false;
}

void Edge::printinfo()
{
	cout << "Starting edge: " << start << endl;
	cout << "Finishing edge: " << finish << endl;
	cout << "Weight: " << weight << endl;
}