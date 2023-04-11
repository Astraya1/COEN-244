#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <fstream>
using namespace std;

class Block
{
    friend ostream &operator<<(ostream &,const Block&);

public:
    int x;
    int y;
    float z;

    Block();
    Block(int a, int b, int c);
    Block &operator=(const Block&);
    bool operator==(const Block&);
    void save(string);
};

Block::Block()
{

}

Block::Block(int a, int b, int c)
{
    x = a;
    y = b;
    z = c;
}

Block& Block::operator=(const Block&rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}

bool Block::operator==(const Block&rhs)
{
    if ((x==rhs.x) && (y==rhs.y) && (z=rhs.z))
        return true;
    return false;
}

ostream &operator<<(ostream & out,const Block&block)
{
    out << "x = " << block.x << ", y = " << block.y << ", z = " << block.z;
    return out;
}

void Block::save(string path)
{
    ofstream myfile(path);
    if (myfile.is_open())
    {
        myfile << "x = " << x << ", y = " << y << ", z = " << z;
        myfile.close();
    }
    else
        cout << "File not open.";
}



int main()
{
    map<string, Block> Database;
    Block Ablob;

    Ablob.x=7;
    Ablob.y=2;
    Ablob.z=4.2355;
    Database["A"] = Ablob;

    Ablob.x=5;
    Database["B"] = Ablob;

    Ablob.z=3.2355;
    Database["C"] = Ablob;

    Ablob.x = 3;
    Ablob.y = 7;
    Ablob.z = 7.2355;
    Database["D"] = Ablob;

    
}