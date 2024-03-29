#include "UGraph.h"
using namespace std;

UGraph::UGraph()
{
	cout << "Created a new graph" << endl;
}

UGraph::UGraph(const UGraph &other): edges{other.edges}, vertices{other.vertices}
{
	// edges = other.edges;
	// vertices = other.vertices;
	// cout << "Copy constructed a new graph" << endl;
}

UGraph::~UGraph()
{
	cout << "Destroyed graph" << endl;
}

vector<Vertex> UGraph::getvertices()
{
	return vertices;
}

vector<Edge> UGraph::getedges() 
{
	return edges;
}

int UGraph::findvalue(int id) const
{
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].getID() == id)
			return vertices[i].getValue();
	}

	return 0;
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
	//Check if vertex is in vector of vertices and sets variable inlist to true if it is.
	bool inlist = false;
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].getID() == vertexID)
		{
			inlist = true;
		}
	}

	//Executes code if the vertex is in the list of vertices
	if (inlist = true)
	{
		//Creates another vector of edges to store edges which we want to delete that are adjacent to the vertex being deleted
		vector<Edge> todelete;

		//For loop over all edges in graph
		for (int i{0}; i<edges.size(); i++)
		{
			//Checks if an edge in the list of edges is adjacent to the vertex we want to delete
			if (edges[i].getstart() == vertexID || edges[i].getfinish() == vertexID)
			{
				//Add the edge to the list of edges to be deleted
				todelete.push_back(edges[i]);
			}
		}

		//For loop over list of edges to be deleted, and deletes them all from list of edges
		for (int i{0}; i<todelete.size(); i++)
		{
			removeEdge(todelete[i]);
		}
		
		//Deletes the vertex from list of vertices
		for (int i{0}; i<vertices.size(); i++)
		{
			if (vertices[i].getID() == vertexID)
			{
				vertices.erase(vertices.begin()+i);
				return true;
			}
		}
	}
	return false;
}

bool UGraph::addEdge(Edge& newedge)
{
	//Check if edge already exists
	for (int i{0}; i<edges.size(); i++)
	{
		if (edges[i].isequal(newedge))
		{
			return false;
		}
		
	}
	
	//Check if edge start and finish are the same
	if (newedge.getstart() == newedge.getfinish()) 
	{
		return false;
	}

	//Check if start and finish vertices are legit vertices (ie. they are in the vertices vector)
	bool validstart = false;
	bool validfinish = false;
	for (int i{0}; i<vertices.size(); i++)
	{
		if (vertices[i].getID() == newedge.getstart())
			validstart = true;
		else if (vertices[i].getID() == newedge.getfinish())
			validfinish = true;
	}
	if (validstart == false || validfinish == false)
		return false;

	//Add edge to the list of edges if all 3 conditions are passed
	edges.push_back(newedge);
	return true;
}

bool UGraph::removeEdge(Edge& edgeremove)
{
	//Goes through all edges in edges, and removes it if it's equal to the edge we want to remove.
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
	for (int i{0}; i<edges.size(); i++)
	{
		if (edges[i].isequal(other))
			return true;
	}
	return false;
}

void UGraph::display() const
{
	cout << "Printing Graph" << "\n" << endl;

	cout << "All vertices:" << "\n" << endl;
	for (int i{0}; i<vertices.size(); i++)
	{
		cout << "ID: " << vertices[i].getID() << endl;
		cout << "Value: " << vertices[i].getValue() << "\n" << endl;
	}
	cout << "Graph connections:" << "\n" << endl;
	for (int i{0}; i<edges.size(); i++)
	{
		cout << "Edge " << i+1 << ":" << endl;
		cout << "ID = " << edges[i].getstart() << " (Value = " << findvalue(edges[i].getstart()) << ")" << " <---> ID = " << edges[i].getfinish() << " (Value = " << findvalue(edges[i].getfinish()) << ")" << endl;
		cout << "Weight: " << edges[i].getweight() << "\n" << endl;
	}
}

string UGraph::toString()
{
    string output;
	vector<int> neighbors;

	for (int i{0}; i<vertices.size(); i++) //Iterate over all vertices in the graph, adding them each individually
	{
		output += "ID: ";
		output += to_string(vertices[i].getID());
		output += " Value: ";
		output += to_string(vertices[i].getValue());
		output += " Adjacent Vertices: ";
		
		neighbors = getneighbors(vertices[i].getID());
		for (int j{0}; j<neighbors.size(); j++)
		{
			output += to_string(neighbors[j]);
			if (j < neighbors.size() - 1)
				output += ", ";
		}
		output += "; ";
	}
	return output;
}

vector<int> UGraph::getneighbors(int vertexid)
{
	vector<int> neighbors;
	for (int i{0}; i<edges.size(); i++)
	{
		if (vertexid == edges[i].getstart())
			neighbors.push_back(edges[i].getfinish());
		else if (vertexid == edges[i].getfinish())
			neighbors.push_back(edges[i].getstart());
	}
	return neighbors;
}

bool UGraph::clean()
{
	edges.clear();
	vertices.clear();
	if (edges.empty() && vertices.empty())
		return true;
	return false;
}
