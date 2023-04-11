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
	int getstart() const;
	int getfinish() const;
	int getweight() const;

	//Setters
	void setstart(int);
	void setfinish(int);
	void setweight(int);

	//Member functions
	bool isequal(const Edge&); //Checks if two edges are equal
	void printinfo(); //Prints the attributes of the edge (start, finish, weight)
	
	bool operator!=(const Edge&) const; //Checks if two edges are not equal
	bool operator==(const Edge&) const; //Checks if two edges are equal
	const Edge& operator=(const Edge&); //Copies the attributes of the edges
	friend std::ostream& operator<<(std::ostream& out, const Edge& e);
	void operator++();
	void operator++(int);
};

#endif