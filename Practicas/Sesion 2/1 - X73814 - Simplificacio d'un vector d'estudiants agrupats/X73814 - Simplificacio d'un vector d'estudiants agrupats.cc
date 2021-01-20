#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<Estudiant> v1(n);
    for (int i = 0; i < n; i++) v1[i].llegir();
    
    vector<Estudiant> v2;
    v2.push_back(v1[0]);
    for (int i = 1; i < n; i++) {
        int last = v2.size() - 1;
        if (v2[last].consultar_DNI() == v1[i].consultar_DNI()) {
            if (v2[last].te_nota() and v1[i].te_nota()) {
                if (v2[last].consultar_nota() < v1[i].consultar_nota())
                    v2[last].modificar_nota(v1[i].consultar_nota());
            } else if (v1[i].te_nota())
                v2[last].afegir_nota(v1[i].consultar_nota());
        } else {
            v2.push_back(v1[i]);
        }
    }
    
    for (int i = 0; i < v2.size(); i++) v2[i].escriure();
}
