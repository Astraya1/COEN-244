#include <iostream>
#include <vector>
#include "UGraph.cpp"
using namespace std;

int main() {
    UGraph g;
    int id1, id2, w, value;
    char option;
    bool check;

    do {
        cout << "Welcome to simple undirected graph program!" << endl;
        cout << "What operation do you want to perform? " <<
            " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Add Vertex" << endl;
        cout << "2. Delete Vertex" << endl;
        cout << "3. Add Edge" << endl;
        cout << "4. Delete Edge" << endl;
        cout << "5. Search Vertex" << endl;
        cout << "6. Search Edge" << endl;
        cout << "7. Display Graph" << endl;
        cout << "8. Print paths" << endl;
        cout << "9. Clear Screen" << endl;
        cout << "a. Duplicate Graph and Display" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        Vertex v1;
        Edge e;

        switch (option) {
        case '0':

            break;

        case '1':
            cout << "Add Vertex Operation -" << endl;
            cout << "Enter ID: ";
            cin >> id1;
            cout << "Enter Value: ";
            cin >> value;
            v1.setID(id1);
            v1.setValue(value);
            if (g.addVertex(v1) == true)
                cout << "Vertex added successfully." << endl;
            else
                cout << "Vertex could not be added." << endl;
            break;


        case '2':
            cout << "Delete Vertex Operation -" << endl;
            cout << "Enter ID of Vertex to Delete: ";
            cin >> id1;
            if (g.removeVertex(id1) == true)
                cout << "Vertex deleted successfully." << endl;
            else
                cout << "Vertex could not be deleted." << endl;
            break;

        case '3':
            cout << "Add Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            cout << "Enter Weight of Edge: ";
            cin >> w;
            e = Edge(id1, id2, w);
            if (g.addEdge(e) == true)
                cout << "Edge added successfully." << endl;
            else   
                cout << "Edge could not be added." << endl;
            break;


        case '4':
            cout << "Delete Edge Operation -" << endl;
            cout << "Enter ID of Source Vertex: ";
            cin >> id1;
            cout << "Enter ID of Destination Vertex: ";
            cin >> id2;
            if (g.removeEdge(e) == true)
                cout << "Edge deleted successfully." << endl;
            else
                cout << "Edge could not be deleted." << endl;
            break;

        case '5':
        {
            cout << "Search Vertex Operation -" << endl;
            int id;
            int value;
            cout << "Enter ID of vertex to search: ";
            cin >> id;
            cout << "Enter value of vertex to search: ";
            cin >> value;

            Vertex *search = new Vertex(id,value);
            if (g.searchVertex(*search) == true)
                cout << "Vertex found." << endl;
            else
                cout << "Vertex not found." << endl;
            break;
        }

        case '6':
        {
            cout << "Search Edge Operation -" << endl;
            int start;
            int finish;

            cout << "Enter first vertex of edge: ";
            cin >> start;
            cout << "Enter second vertex of edge: ";
            cin >> finish;

            Edge *search = new Edge (start,finish,0);
            if (g.searchEdge(*search) == true)
                cout << "Edge found." << endl;
            else
                cout << "Edge not found." << endl;
            break;
        }
        case '7':
            cout << "Display Graph : " << endl;
            g.display();
            break;

        case '8':
            cout << "Get graph as string -" << endl;
            cout << g.toString() << endl;
            break;

        case '9':
            cout << "Clear graph" << endl;
            if (g.clean() == true)
                cout << "Graph cleared successfully." << endl;
            else
                cout << "Graph could not be cleared." << endl;
            break;
        
        case 'a':
        {
            cout << "Duplicate graph and display" << endl;
            UGraph newg = UGraph(g);
            newg.display();
            break;
        }

        default:
            cout << "Enter Proper Option number " << endl;
        }
        cout << endl;

    } while (option != '0');

    return 0;

}