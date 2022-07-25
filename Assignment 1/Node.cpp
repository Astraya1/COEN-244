#include "Node.h"

//Default constructor
Node::Node()
{
    id = "";
    value = "";
}

//Constructor
Node::Node(string x, string y)
{
    id = x;
    value = y;
}

//Getters
string Node::get_id()
{
    return id;
}

string Node::get_value()
{
    return value;
}

//Setters
void Node::set_id(string x)
{
    id = x;
}

void Node::set_value(string x)
{
    value = x;
}

//Clone
Node Node::clone()
{
    string newid = id + "_copy";

    return Node(newid, value);
}