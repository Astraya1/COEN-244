#include "Nodelist.h"  
#include <iostream>
using namespace std;

//Constructors
NodeList::NodeList(Node* x, size_t y) //Constructor
{
    items = x;
    numitems = y;
}

NodeList::NodeList(const NodeList &x) //Copy constructor
{
    numitems = x.numitems;
    items = x.items;
}

size_t NodeList::getnumitems()
{
    return numitems;
}

void NodeList::printattributes()
{
    cout << "Printing IDs of nodes in node list:" << endl;
    for (int i{0}; i<numitems; i++)
    {
        cout << (items+i)->get_id() << endl;
    }

    cout << '\n' << "Printing values of nodes in node list:" << endl;
    for (int i{0}; i<numitems; i++)
    {
        cout << (items+i)->get_value() << endl;
    }
}

void NodeList::checkID(string x)
{
    for (int i{0}; i<numitems; i++)
    {
        if (x==(items+i)->get_id())
        {
            cout << "Node is in node list." << endl;
            return;
        }
    }
    cout << "Node is not in node list." << endl;
}

void NodeList::checkValue(string x)
{
    for (int i{0}; i<numitems; i++)
    {
        if (x==(items+i)->get_value())
        {
            cout << "Node is in node list." << endl;
            return;
        }
    }
    cout << "Node is not in node list." << endl;
}

NodeList::~NodeList()
{
    cout << "Node list destroyed." << endl;
}