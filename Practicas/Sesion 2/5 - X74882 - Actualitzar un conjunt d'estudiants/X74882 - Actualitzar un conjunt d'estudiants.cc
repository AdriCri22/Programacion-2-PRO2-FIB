#include "Cjt_estudiants.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    Cjt_estudiants Cjt_est1;
    Cjt_est1.llegir();
    
    Cjt_estudiants Cjt_est2;
    Cjt_est2.llegir();

    for (int i = 1; i <= Cjt_est1.mida(); i++) {
        Estudiant est_1 = Cjt_est1.consultar_iessim(i);
        Estudiant est_2 = Cjt_est2.consultar_iessim(i);
        
        if (est_1.te_nota() and est_2.te_nota()) {
            if (est_1.consultar_nota() < est_2.consultar_nota()) 
                Cjt_est1.modificar_iessim(i, est_2);
        } else if (est_2.te_nota()) {
            Cjt_est1.modificar_iessim(i, est_2);
        }
    }
    
    Cjt_est1.escriure();
}

/*
5
2299 4.5
1234 3.4
9988 78
4000 0
6666 9
5
9988 5.67
2299 5.6
6666 9.1
4000 -1
1234 7.9
*/
