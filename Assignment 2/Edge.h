#ifndef EDGE_H
#define EDGE_h

class Edge
{
private:
	int start;
	int finish;
	int weight;
	
public:
	Edge();
	Edge(int, int, int);
	~Edge();

	//Getters
	int getstart();
	int getfinish();
	int getweight();

	//Setters
	void setstart(int);
	void setfinish(int);
	void setweight(int);

	//Member functions
	bool isequal(const Edge&); //Checks if two edges are equal
	void printinfo(); //Prints the attributes of the edge (start, finish, weight)
};

#endif