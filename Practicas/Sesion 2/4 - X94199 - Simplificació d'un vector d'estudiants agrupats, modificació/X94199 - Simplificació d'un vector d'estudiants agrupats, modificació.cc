#include "Estudiant.hh"
//#include <iostream>
#include <vector>
using namespace std;

void swap(Estudiant& est1, Estudiant& est2) {
    Estudiant est3 = est1;
    est1 = est2;
    est2 = est3;
}

/* Pre: v=V, v.size() > 0 i les notes d'un mateix estudiant son consecutives */
/* Post: pos+1 es el nombre d'estudiants diferents de V; cada estudiant de V
    nomes hi apareix un cop a v[0..pos], amb la nota mes alta i en el mateix
    ordre que a V */
void simplificar_vector(vector<Estudiant>& v, int& pos) {
    pos = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[pos].consultar_DNI() == v[i].consultar_DNI()) {
            if (v[pos].te_nota() and v[i].te_nota()) {
                if (v[pos].consultar_nota() > v[i].consultar_nota()) swap(v[pos], v[i]);
            } if (v[i].te_nota()) swap(v[pos], v[i]);
        } else {
            pos++;
            swap(v[pos], v[i]);
        }
    }
}
 

/*int main() {
    int n;
    cin >> n;
    
    vector<Estudiant> v(n);
    for (int i = 0; i < n; i++) v[i].llegir();
    
    simplificar_vector(v, n);    
    cout << endl;
    for (int i = 0; i < v.size(); i++) v[i].escriure();
}*/
