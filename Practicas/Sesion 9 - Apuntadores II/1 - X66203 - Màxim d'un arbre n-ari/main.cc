#include <iostream>
#include "ArbNIOint.hh"
#include "ArbreN.hh"
using namespace std;

int main() {
    int aritat;
    cin >> aritat;
    ArbreNari<int> a(aritat);
    llegir_arbre_int(a, 0);
    
    int max = a.maxim();
    cout << max << endl;
}
// 2 3 2 0 0 1 0 0 4 0 3 0 0
