#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Cjt_estudiants Cjt_est;
    Cjt_est.llegir();
    
    int n;
    while (cin >> n and n != -7) {
        if (n == -1) {          //borrar estudiante
            int dni;
            cin >> dni;
            Cjt_est.esborrar_estudiant(dni);
        } else if (n == -2) {   //nota maxima
            Estudiant est = Cjt_est.estudiant_nota_max();
            cout << est.consultar_nota() << endl;
        } else if (n == -3) {      //añadir estudiante
            int dni;
            double nota;
            cin >> dni >> nota;
            
            if (Cjt_est.existeix_estudiant(dni)) cout << "el estudiante " << dni << " ya estaba" << endl << endl;
            else if (Cjt_est.mida() == Cjt_est.mida_maxima()) cout << "el conjunto esta lleno" << endl << endl;
            else {
                Estudiant est;
                est = Estudiant(dni);
                if (0<= nota and nota <= 10) est.afegir_nota(nota);
                Cjt_est.afegir_estudiant(est);
            }
        }else if (n == -4) {   //modificar la nota mediante DNI
            int dni;
            double nota;
            cin >> dni >> nota;
            if (Cjt_est.existeix_estudiant(dni)) {
                Estudiant est = Cjt_est.consultar_estudiant(dni);
                if (est.te_nota()) {
                    est.modificar_nota(nota);
                    Cjt_est.modificar_estudiant(est);
                } else {
                    est.afegir_nota(nota);
                    Cjt_est.modificar_estudiant(est);
                }
            } else cout << "el estudiante " << dni << " no esta" << endl << endl;
        } else if (n == -5) {   //modificar la nota
            int i, dni;
            double nota;
            cin >> i >> dni >> nota;
            Estudiant est = Estudiant(dni);
            est.afegir_nota(nota);
            Cjt_est.modificar_iessim(i, est);
        } else if (n == -6) Cjt_est.escriure();
    }
}
/*
3
4444 7.6
2222 5.1
3333 14
 */
