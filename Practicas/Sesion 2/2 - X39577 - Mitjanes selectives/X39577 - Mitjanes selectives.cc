#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

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
        Est[i].escriure();
    }
}
