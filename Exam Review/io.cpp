#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void testthrow() {
    int i;
    cin >> i;
    if (i<0)
        throw i;
}

int main() {
    try {
        testthrow();
    }
    catch (int x) {
        cout << "is in an index should be more than 0";
    }
}