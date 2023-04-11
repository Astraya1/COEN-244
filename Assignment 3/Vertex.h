#include <iostream>
#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
private:
	int ID;
	int value;
	
public:
	Vertex();
	Vertex(int, int);
	Vertex(const Vertex&);

	//Getters
	int getID() const;
	int getValue() const;

	//Setters
	void setID(int);
	void setValue(int);

	bool isequal(const Vertex&); //Checks if two vertices are equal
	void printinfo(); //Prints attributes

	//void operator+(const Vertex&); 
	bool operator!=(const Vertex&) const;
	bool operator==(const Vertex&) const;
	const Vertex& operator=(const Vertex&);
	friend std::ostream& operator<<(std::ostream& out, const Vertex& v);
};

#endif