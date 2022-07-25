#include "UGraph.cpp"
using namespace std;

int main()
{
    Vertex one = Vertex(2,5);
    Vertex two = Vertex(3,123);
    Vertex three = Vertex(3,132);

    one.printinfo();
    two.printinfo();

    UGraph xd = UGraph();
    cout << xd.addVertex(one) << endl;
    cout << xd.addVertex(two) << endl;
    cout << xd.addVertex(three) << endl;

    xd.display();
} 