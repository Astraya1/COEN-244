#include "UGraph.h"
using namespace std;

UGraph::UGraph()
{

}

UGraph::UGraph(const UGraph &other)
{
	edges = other.edges;
	vertices = other.vertices;
}

UGraph::~UGraph()
{
	
}

vector<Vertex> UGraph::getvertices()
{
	return vertices;
}

vector<Edge> UGraph::getedges() 
{
	return edges;
}

bool UGraph::addVertex(Vertex vertex1)
{
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].getID() == vertex1.getID())
			return false;
	}

	vertices.push_back(vertex1);
	return true;
}

bool UGraph::removeVertex(int vertexID)
{
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].getID() == vertexID)
		{
			vertices.erase(vertices.begin()+i);
			return true;
		}
	}
	return false;
}

bool UGraph::addEdge(Edge& newedge)
{
	for (int i{0}; i<edges.size(); i++)
	{
		if (edges[i].isequal(newedge))
		{
			return false;
		}
	}

	edges.push_back(newedge);
	return true;
}

bool UGraph::removeEdge(Edge& edgeremove)
{
	for (int i{0}; i<edges.size(); i++)
	{
		if (edges[i].isequal(edgeremove))
		{
			edges.erase(edges.begin()+i);
			return true;
		}
	}
	
	return false;
}

bool UGraph::searchVertex(const Vertex& other)
{
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].isequal(other))
			return true;
	}
	return false;
}

bool UGraph::searchEdge(const Edge& other)
{
	
}

void UGraph::display() const
{
	for (int i{0}; i<vertices.size(); i++) //For loop iterating over every vertex in vertices, printing its info.
	{
		cout << "ID: " << vertices[i].getID() << endl;
		cout << "Value: " << vertices[i].getValue() << endl;
		cout << "\n";
	}
}