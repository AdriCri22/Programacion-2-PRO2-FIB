#include <iostream>
#include "LlistaIOint.hh"
using namespace std;

int main(){
    Llista<int> l;
    cout << "Entra llista naturals (acabada per -1): " << endl;
    llegir_llista_int(l,-1);
    
    cout << "Número a partir del qual es vol reorganitzar" << endl;
    int num;
    cin >> num;
    cout << "Llista reorganitzada" << endl;
    l.reorganitzar_in(num);
    escriure_llista_int(l);
    l.escriure();
}

// 9 27 3 14 1 5 2 -1 5
