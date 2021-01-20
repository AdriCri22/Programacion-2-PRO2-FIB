#include <iostream>
#include "ArbIOint.hh"
using namespace std;

int main() {
    Arbre<int> a;
    llegir_arbre_int(a, 0);
    Arbre<int> asum;
    a.arb_sumes(asum);
    escriure_arbre_int(asum);
    cout << endl;
}
// 2 3 2 0 0 1 0 0 4 0 3 0 0
