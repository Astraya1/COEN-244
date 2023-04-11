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

int Edge::getstart() const
{
	return start;
}

int Edge::getfinish() const
{
	return finish;
}

int Edge::getweight() const
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
	if (start == other.start && finish == other.finish)
		return true;
	else
		return false;
}

void Edge::printinfo()
{
	cout << "Vertex 1: " << start << endl;
	cout << "Vertex 2: " << finish << endl;
	cout << "Weight: " << weight << endl;
}

bool Edge::operator!=(const Edge& other)const {
	return !( *this == other );

}

bool Edge::operator==(const Edge& other)const {
	if(start == other.start && finish == other.finish && weight == other.weight)
	return true;
	else{
		return false;
	}

}

const Edge& Edge::operator=(const Edge& other){
	start = other.start;
	finish = other.finish;
	weight = other.weight;
	return *this;

}
std::ostream& operator<<(std::ostream& out, const Edge& e){
 	out << e.getstart() << " " << e.getfinish()<< " " << e.getweight() << endl;
 	return out;
 }

void Edge::operator++() {
	Edge temp;
	++weight;
	temp.weight = weight;


 }

 void Edge::operator++(int) {
	Edge temp;
	++weight;
	temp.weight = weight;

 }


