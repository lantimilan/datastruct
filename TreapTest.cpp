// Treap.cpp
#include "Treap.h"
#include <string>
using namespace std;

int main() {
    Treap<string> tp;
    tp.insert("cc");
    tp.insert("aa");
    tp.insert("bb");
    tp.insert("ee");
    tp.insert("dd");
    tp.insert("ff");
    tp.print();
}
