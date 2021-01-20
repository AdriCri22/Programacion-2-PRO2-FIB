#include "Cjt_estudiants.hh"

void Cjt_estudiants::afegir_estudiant(const Estudiant &est, bool& b) {
    b = false;
    int i = 0;
    while (not b and i < nest and est.consultar_DNI() >= vest[i].consultar_DNI()) {
        if (est.consultar_DNI() == vest[i].consultar_DNI()) b = true;
        i++;
    }
    
    if (not b) {
        for (int j = nest; i < j; j--) vest[j] = vest[j - 1];
        vest[i] = est;
        nest++;
        if (est.te_nota()) {
            suma_notes += est.consultar_nota();
            nest_amb_nota++;
        }
    }
    
    
}

void Cjt_estudiants::esborrar_estudiant(int dni, bool& b) {
    b = false;
    int i = 0;
    while (not b and i < nest and dni >= vest[i].consultar_DNI()) {
        if (dni == vest[i].consultar_DNI()) b = true;
        else i++;
    }
    
    if (b) {
        if (vest[i].te_nota()) {
            nest_amb_nota--;
            suma_notes -= vest[i].consultar_nota();
        }
        nest--;
        for (int j = i; j < nest; j++) vest[j] = vest[j + 1];
        
    }
}
