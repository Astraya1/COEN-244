#include <iostream>
using namespace std;

class Marks
{
private:
    int subjects[3];
public:
    Marks(int a, int b, int c)
    {
        subjects[0] = a;
        subjects[1] = b;
        subjects[2] = c;
    }

    int &operator[] (int index)
    {
        return subjects[index];
    }
};

int main()
{
    Marks me(54,12,132);

    cout << me[1] << endl;
    cout << me[2] << endl;
    me[2] = 32;
    cout << me[2];
}