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
	if (ID == other.ID && value == other.value)
		return true;
	else
		return false;
}

void Vertex::printinfo() {
	cout << "ID: " << ID << endl;
	cout << "Value: " << value << endl;
}

 /* void Vertex::operator+(const Vertex &other){
	

	
}  */

bool Vertex::operator!=(const Vertex& other) const{
	return !( *this == other );

}

bool Vertex::operator==(const Vertex& other) const {
	if(ID == other.ID && value == other.value)
	return true;
	else{
		return false;
	}
}



const Vertex& Vertex::operator=(const Vertex & other){
		if(&other != this){
			ID = other.ID;
			value = other.value;
		}
		return *this;
		
}

std::ostream& operator<<(std::ostream& out, const Vertex& v){
 	out << v.getID() << " " << v.getValue() << endl;
 	return out;
 }