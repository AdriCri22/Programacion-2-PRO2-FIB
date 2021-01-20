#include "Estudiant.hh"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(Estudiant est1, Estudiant est2) {
    if (est1.consultar_nota() != est2.consultar_nota()) return est1.consultar_nota() > est2.consultar_nota();
    else return est1.consultar_DNI() < est2.consultar_DNI();
}

int main() {
    int m, n, s;
    cin >> m >> n >> s;
    
    vector<int> S(s);
    for (int i = 0; i < s; i++) cin >> S[i];
    
    vector<Estudiant> Est(m);
    vector<double> A(n);
    for (int i = 0; i < m; i++) {
        int dni;
        cin >> dni;
        
        for (int j = 0; j < n; j++) cin >> A[j];
        
        double sum = 0;
        for (int j = 0; j < s; j++) sum += A[S[j] - 1];
        
        Est[i] = Estudiant(dni);
        Est[i].afegir_nota(sum / s);
    }
    sort(Est.begin(), Est.end(), comp);
    for (int i = 0; i < m; i++) Est[i].escriure();
}
