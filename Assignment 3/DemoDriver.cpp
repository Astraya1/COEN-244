#include <iostream>
#include <vector>
#include "UGraph.cpp"
#include <algorithm>
using namespace std;

int main()
{
    void testequal(bool, const UGraph&, const UGraph&);
    void testassign(UGraph&, UGraph&);
    void testaddweight(UGraph&);
    void testplus(UGraph&, UGraph&);
    void testsubscript(int, int, UGraph&);
    void teststringcast(string, UGraph&);

    UGraph g1, g2, g3;
    Vertex v1(23, 6), v2(1, 45), v3(4, 8), v4(5, 9), v5(10,6), v6(11,7);
    Edge e1(23, 1, 89), e2(4, 5, 10), e3(1, 5, 78), e4(10,11,67);

    g1.addVertex(v1);
    g1.addVertex(v2);
    g1.addEdge(e1);

    g2.addVertex(v5);
    g2.addVertex(v6);
    g2.addEdge(e4); 
    
    //g1 contains vertices [(23,6),(1,45)] and edge (23,1,89)
    //g2 contains vertices [(10,6),(11,7)] and edge (10,11,67)

    cout <<"Testing == operator: \n";
    testequal(false, g1, g2);

    cout << "Testing + and << operators: \n";
    testplus(g1,g2);

    cout << "Testing ++ operator: \n";
    testaddweight(g1);
    testaddweight(g2);

    cout << "Testing subscript overload: " << endl;
    testsubscript(0,10,g2);
    testsubscript(1,11,g2);
    
    cout << "Testing string cast overload: " << endl;
    teststringcast("10 <--> 11, Weight = 68; 23 <--> 1, Weight = 90; ", g2);
    teststringcast("23 <--> 1, Weight = 90; ", g1);

    return 0;
}

void testequal(bool expected, const UGraph& g, const UGraph& other){
	if(g == other && expected == true)
        cout << "Pass" << endl;
    else if (!(g == other) && expected == false)
        cout << "Pass" << endl;
	else
        cout << "Fail" << endl;
}

void testassign(UGraph& g, UGraph& other){
    other = g;
    if (g == other)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

void testaddweight(UGraph& g){
    vector<int> expected;

    for (int i{0}; i<g.getedges().size(); i++)
        expected.push_back(g.getedges()[i].getweight()+1);

    ++g;
    bool pass = true;
    for (int i{0}; i<g.getedges().size(); i++)
    {
        if (expected[i] != g.getedges()[i].getweight())
            pass = false;
    }

    if (pass == true)
        cout << "Pass" << endl;
    else
        cout << "False" << endl;
    
}

void testplus(UGraph& g, UGraph& other){
    UGraph result = g + other;
    if((string(result).find(string(g)) != string::npos) && (string(result).find(string(other)) != string::npos))
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

void testsubscript(int testval, int expected, UGraph &testgraph)
{
    if (testgraph[testval].getID() == expected)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}

void teststringcast(string expected, UGraph &testgraph)
{
    if (string(testgraph) == expected)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;
}