#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.cpp"
#include "Edge.cpp"
#include <string>
#include <vector>

class Graph
{
public:
	Graph();
	Graph(const Graph&);
	virtual ~Graph() = 0;

	//Member functions
	virtual int findvalue(int) const = 0;
	virtual bool addVertex(Vertex) = 0;
	virtual bool removeVertex(int) = 0;
	virtual bool addEdge(Edge&)	= 0;
	virtual bool removeEdge(Edge&) = 0;
	virtual bool searchVertex(const Vertex&) = 0;
	virtual bool searchEdge(const Edge&) = 0;
	virtual void display() const = 0;
	virtual string toString() = 0;
	virtual vector<int> getneighbors(int) = 0;
	virtual bool clean() = 0;
	
private:
};

#endif