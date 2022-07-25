#include <iostream>
using namespace std;

// class CreateDestroy
// {
// public:
//     CreateDestroy() {cout << "constructor called, ";}
//     ~CreateDestroy() {cout << "destructor called, ";}
// };
int main()
{
    int x = 5;
    int* ptr = &x;
    *ptr = 7;
    cout << x << endl;
    cout << *ptr;
}