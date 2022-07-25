#include "Vertex.h"
#include <iostream>
using namespace std;

Vertex::Vertex() {
	value = 0;
	ID = 0;
}

Vertex::Vertex(int x, int y) {
	ID = x;
	value = y;
}

Vertex::Vertex(const Vertex &other)
{
	ID = other.ID;
	value = other.value;
}

int Vertex::getID() const {
	return ID;
}

int Vertex::getValue() const {
	return value;
}

void Vertex::setID(int x) {
	ID = x;
}

void Vertex::setValue(int x) {
	value = x;
}

bool Vertex::isequal(const Vertex &other)
{
	if (ID == other.getID() && value == other.getValue())
		return true;
	else
		return false;
}

void Vertex::printinfo() {
	cout << "ID: " << ID << endl;
	cout << "Value: " << value << endl;
}