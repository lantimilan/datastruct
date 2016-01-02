// Treap.cpp
#include "Treap.h"
#include <string>
using namespace std;

int main() {
    Treap<string> tp;
    tp.insert("cc"); //tp.print(); cout << endl;
    tp.insert("aa"); //tp.print(); cout << endl;
    tp.insert("bb"); //tp.print(); cout << endl;
    tp.insert("ee"); //tp.print(); cout << endl;
    tp.insert("dd"); //tp.print(); cout << endl;
    tp.insert("ff"); //tp.print(); cout << endl;
    tp.print();
}
