#include "CuaIOint.hh"
#include "program.hh"
#include <iostream>
using namespace std;

int main() {
    Cua<int> cA;
    llegir_cua_int(cA, 0);
    
    Cua<int> cB;
    llegir_cua_int(cB, 0);
    
    cA.concat(cB);
    escriure_cua_int(cA);
}
