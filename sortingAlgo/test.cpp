#include <iostream>

using namespace std;

void test(int **x, int **y) {

        *x = *y;
}

void testSingle(int *x, int *y) {
    *x = 6;
}
int main() {
    int r = 34;
    int * a;
    a = &r;
    
    int q = 3;
    int * b;
    b = &q;
    cout << "address being pointed to " << endl;
    cout << a << endl;
    cout << "value at a " << *a << endl;

    cout << "single pointer result, no memory address change " << endl;
    testSingle(a ,b);
    cout << a << endl;
    cout << "value at a " << *a << endl;

    test(&a, &b);
    cout << "double pointer result, changes memory address of origional" << endl;
    cout << a << endl;
    cout << "value at a " << *a << endl;

}