#include "Node.cpp"
#include <iostream>

int main()
{
    //Create new Node called "node1"
    Node node1 = Node("Eiffel", "65");

    //Print attributes of node1
    cout << "ID: " << node1.get_id() << endl;
    cout << "Value: " << node1.get_value() << endl;

    //Change attributes of node1
    cout << '\n' << "Input a new ID for node: ";
    string newid;
    cin >> newid;

    cout << "Input a new value for node: ";
    string newval;
    cin >> newval;

    node1.set_id(newid);
    node1.set_value(newval);

    cout << '\n' << "New ID: " << node1.get_id() << endl;
    cout << "New value: " << node1.get_value() << endl;

    //Cloning node1
    Node node2 = node1.clone();

    //Print attributes of node2
    cout << '\n' << "Printing attributes of cloned node." << endl;
    cout << "ID: " << node2.get_id() << endl;
    cout << "Value: " << node2.get_value() << endl;

    //Change attributes of node2
    cout << '\n' << "Input a new ID for node: ";
    cin >> newid;

    cout << "Input a new value for node: ";
    cin >> newval;

    node2.set_id(newid);
    node2.set_value(newval);

    cout << '\n' << "New ID of node2: " << node2.get_id() << endl;
    cout << "New value of node2: " << node2.get_value() << endl;
}