#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
using namespace std;

double redondear(double r) {  
    return int(10.*(r + 0.05)) / 10.0;
}

int main() {
    Cjt_estudiants Cjt_est1;
    Cjt_est1.llegir();
    
    int n;
    while (cin >> n and n != -6) {
        if (n == -1) {      //añadir estudiante
            int dni;
            double nota;
            cin >> dni >> nota;
            
            if (Cjt_est1.existeix_estudiant(dni)) cout << "el estudiante " << dni << " ya estaba" << endl << endl;
            else if (Cjt_est1.mida() == Cjt_est1.mida_maxima()) cout << "el conjunto esta lleno" << endl << endl;
            else {
                Estudiant est;
                est = Estudiant(dni);
                if (0<= nota and nota <= 10) est.afegir_nota(nota);
                Cjt_est1.afegir_estudiant(est);
            }
        } else if (n == -2) {   //consultar nota mediante DNI
            int dni;
            cin >> dni;
            if (Cjt_est1.existeix_estudiant(dni)) {
                Estudiant est = Cjt_est1.consultar_estudiant(dni);
                if (est.te_nota()) cout << "el estudiante " << dni << " tiene nota " << est.consultar_nota() << endl << endl;
                else cout << "el estudiante " << dni << " no tiene nota" << endl << endl;
            } else cout << "el estudiante " << dni << " no esta" << endl << endl;
        } else if (n == -3) {   //modificar la nota
            int dni;
            double nota;
            cin >> dni >> nota;
            if (Cjt_est1.existeix_estudiant(dni)) {
                Estudiant est = Cjt_est1.consultar_estudiant(dni);
                if (est.te_nota()) {
                    est.modificar_nota(nota);
                    Cjt_est1.modificar_estudiant(est);
                } else {
                    est.afegir_nota(nota);
                    Cjt_est1.modificar_estudiant(est);
                }
            } else cout << "el estudiante " << dni << " no esta" << endl << endl;
        } else if (n == -4) {   //redondear nota
            for (int i = 1; i <= Cjt_est1.mida(); i++) {
                Estudiant est = Cjt_est1.consultar_iessim(i);
                if (est.te_nota()) {
                    double r = redondear(est.consultar_nota());
                    est.modificar_nota(r);
                    Cjt_est1.modificar_iessim(i, est);
                }
            }
        } else if (n == -5) { //escribir conjunto
            Cjt_est1.escriure();
            cout << endl;
        }
    }
}
