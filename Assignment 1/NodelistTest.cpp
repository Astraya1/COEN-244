#include "Nodelist.cpp"
using namespace std;

int main()
{
    cout << "How many nodes will you place in node list? ";
    size_t numnodes;
    cin >> numnodes;
    cout << endl;

    Node nodes[numnodes];

    string id;
    string value;

    for (int i{0}; i<numnodes; i++)
    {
        cout << "Please enter the ID for node " << i+1 << ": ";
        cin >> id;
        cout << "Please enter the value for node " << i+1 << ": ";
        cin >> value;
        cout << endl;

        nodes[i] = Node(id, value);
    }

    //Creating object of type NodeList
    NodeList nodelist = NodeList(nodes, numnodes);

    string temp;

    cout << "Created a node list object, now testing member functions. Type 'OK' and press enter to continue: ";
    cin >> temp;
    cout << endl;

    //Testing getnumitems method
    cout << "Number of items in node list: " << nodelist.getnumitems() << '\n' << endl;

    //Testing printattributes method
    nodelist.printattributes();
    
    //Testing checkID method
    cout << '\n' << "Enter an ID you wish to check in node list. Type 'Done' to move on: ";
    while (id != "Done")
    {
        cin >> id;
        nodelist.checkID(id);
    }

    //Testing checkValue method
    cout << '\n' << "Enter a value you wish to check in node list. Type 'Done' to move on: ";
    while (value != "Done")
    {
        cin >> value;
        nodelist.checkValue(value);
    }

    cout << '\n' << "Creating new node list object from copy constructor. Type 'OK' and press enter to continue: ";
    cin >> temp;
    cout << endl;

    NodeList nodelist2 = NodeList(nodelist);

    nodelist2.printattributes();
}