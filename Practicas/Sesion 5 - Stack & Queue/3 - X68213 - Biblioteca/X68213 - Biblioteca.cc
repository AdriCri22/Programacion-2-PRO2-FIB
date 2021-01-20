#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void escriure(const vector<stack<string> >& v, int c) {
    cout << "Pila de la categoria " << c << endl;
    stack<string> llibres = v[c-1];
    while (not llibres.empty()) {
        cout << llibres.top() << endl;
        llibres.pop();
    }
    cout << endl;
}

void retirar(vector<stack<string> >& v, int n, int c) {
    stack<string> llibres = v[c-1];
    for (int i = 0; i < n; i++) {
        llibres.pop();
    }
    v[c-1] = llibres;
}

int main() {
    int n;
    cin >> n;
    
    vector<stack<string> > v(n);
    int m;
    while (cin >> m and m != -4) {
        if (m == -1) {          //llibre a la pila de devolucions de la seva categoria
            int c;
            string titol;
            cin >> titol >> c;
            v[c-1].push(titol);
        } else if (m == -2) {   //retiren nombre de llibres
            int x, c;
            cin >> x >> c;
            retirar(v, x, c);
        } else if (m == -3) {   //escriure contengut d'1 de les piles
            int c;
            cin >> c;
            escriure(v, c);
        }
    }
}
