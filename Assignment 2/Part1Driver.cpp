#include "Edge.cpp"
#include "Vertex.cpp"
using namespace std;

int main()
{
    int id;
    int value;

    cout << "Testing Vertex class" << "\n" << endl;
    cout << "Enter the ID for vertex: ";
    cin >> id;

    cout << "Enter the value for vertex: ";
    cin >> value;

    Vertex *vertex1 = new Vertex(id, value);

    cout << "\n" << "Printing info of vertex:" << endl;

    vertex1->printinfo();
    
    int start;
    int finish;
    int weight;

    cout << "\n" << "Testing Edge class" << "\n" << endl;
    cout << "Enter the starting vertex ID for edge: ";
    cin >> start;

    cout << "Enter the finishing vertex ID for edge: ";
    cin >> finish;

    cout << "Enter the weight for edge: ";
    cin >> weight;

    Edge *edge1 = new Edge(start, finish, weight);

    cout << "\n" << "Printing info of edge:" << endl;

    edge1->printinfo();
}