#ifndef NODELIST_H
#define NODELIST_H

#include "Node.cpp"

class NodeList
{
private:
    static const size_t listsize = 500;
    Node *items;
    size_t numitems;

public:
    NodeList(Node*, size_t); //Constructor
    NodeList(const NodeList&); //Copy constructor

    size_t getnumitems(); //Getter

    void printattributes(); //Prints all node IDs and values
    void checkID(string); //Check if a node exists by ID
    void checkValue(string); //Check if a node exists by value

    ~NodeList(); //Destructor
};

#endif