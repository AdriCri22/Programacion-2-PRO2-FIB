#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int half = n / 2;
    
    bool odd = false;
    if (n % 2 != 0) odd = true;
    
    bool pal = true;
    stack<int> pila;
    for (int i = 1; i <= n and pal; i++) {
        int m;
        cin >> m;
        if (i <= half) pila.push(m);    
        else if (odd) odd = false;
        else if (pila.top() == m) pila.pop();
        else pal = false;
    }

    if (pila.empty()) cout << "SI" << endl;
    else cout << "NO" << endl;
}
