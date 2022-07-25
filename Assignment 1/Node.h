#ifndef NODE_H
#define NODE_H

#include <string>
using namespace std;

class Node
{
private:
    string id;
    string value;

public:
    //Constructors
    Node(); //Default
    Node(string, string);

    //Getters
    string get_id();
    string get_value();

    //Setters
    void set_id(string);
    void set_value(string);

    //Clone method
    Node clone();
};

#endif