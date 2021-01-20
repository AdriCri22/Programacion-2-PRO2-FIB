#include <iostream>
#include <stack>
using namespace std;

bool parentesis(stack<char>& pila) {
    stack<char> pila2;
    pila2.push(pila.top());
    pila.pop();
    while (not pila.empty()) {
        if (pila.top() == ')' or pila.top() == ']') {
            pila2.push(pila.top());
            pila.pop();
        } else if (not pila2.empty() and pila.top() == '(' and pila2.top() == ')') {
            pila.pop();
            pila2.pop();
        } else if (not pila2.empty() and pila.top() == '[' and pila2.top() == ']') {
            pila.pop();
            pila2.pop();
        } else return false;
    }
    
    if (pila2.empty()) return true;
    else return false;
}

int main() {
    char c;
    stack<char> pila;
    while (cin >> c and c != '.') {
        pila.push(c);
    }

    if (parentesis(pila)) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
