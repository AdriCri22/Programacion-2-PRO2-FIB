#include <iostream>
#include "ArbGIOint.hh"
using namespace std;

int main(){
  ArbreGen<int> a;
  cout << "Posa els valors de l'arbre general en preordre" << endl;
  llegir_arbre_int(a,0);
  cout << "Escrivim l'arbre general en preordre" << endl;
  escriure_arbre_int(a);
  cout << endl;
  int num;
  cin >> num;
  cout << endl << a.buscar(num) << endl;
}
/*
1 3 
2 0
3 0 
4 0 
*/
