#include "BinTreeIOint.hh"
#include "BinTree.hh"
#include <iostream>
using namespace std;

bool find(const BinTree<int>& a, int x) {
    bool found;
    if (a.empty()) found = false;
    else if (a.value() == x) found = true;
    else {
        found = find(a.left(), x);
        if (not found) found = find(a.right(), x);
    }
    return found;
}

void reconstruir(const BinTree<int>& a, BinTree<int>& b, int x) {
    if (not a.empty()) {
        int val = a.value();
        if (val != x) {
            BinTree<int> b1;
            BinTree<int> b2;
            
            reconstruir(a.left(), b1, x);
            reconstruir(a.right(), b2, x);
            
            b = BinTree<int>(val, b1, b2);
        }
    }
}

bool poda_subarbre(BinTree<int> &a, int x) {
    if (find(a, x)) {
        BinTree<int> b;
        reconstruir(a, b, x);
        a = b;
        return true;
    } else return false;
}

int main() {
    cout << "Arbol binario (con el valor de 0 en los extremos):" << endl;
    BinTree<int> a;
    read_bintree_int(a, 0);
    
    cout << "¿Que nodo desea eliminar?" << endl;
    int x;
    cin >> x;
    cout << "Arbol original: ";
    write_bintree_int(a);
    cout << endl;
    cout << poda_subarbre(a, x) << endl;
    cout << "Arbol reconstruido: ";
    write_bintree_int(a);
    cout << endl;
}
/*
Ejemplo:
1
2
5
0
0
4
7
0
0
6
0
0
3
0
0
*/
