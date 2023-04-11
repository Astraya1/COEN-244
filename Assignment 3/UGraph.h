#ifndef UGRAPH_H
#define UGRAPH_H

#include "Graph.cpp"
#include <vector>

class UGraph: public Graph
{
public:
	UGraph();
	UGraph(const UGraph&);
	~UGraph();

	//Getter functions
	vector<Vertex> getvertices();
	vector<Edge> getedges();

	//Member functions
	int findvalue(int) const;
	bool addVertex(Vertex); //Adds a vertex to the vector, returns true if added successfully
	bool removeVertex(int);
	bool addEdge(Edge&);
	bool removeEdge(Edge&);
	bool searchVertex(const Vertex&);
	bool searchEdge(const Edge&);
	void display() const;
	string toString();
	vector<int> getneighbors(int);
	bool clean();

	bool operator==(const UGraph&) const;
	UGraph& operator=( UGraph&);
	UGraph operator+( UGraph&);
	void operator++();
	void operator++(int);
	Vertex &operator[](int);
	friend std::ostream& operator<<(std::ostream& out, const UGraph& g);
	operator string();
 
private:
	vector<Vertex> vertices;
	vector<Edge> edges;
};

#endif