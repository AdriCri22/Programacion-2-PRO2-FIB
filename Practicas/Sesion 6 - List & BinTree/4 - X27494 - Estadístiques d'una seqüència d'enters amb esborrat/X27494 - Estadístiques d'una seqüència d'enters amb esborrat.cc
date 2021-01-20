#include <iostream>
#include <list>
using namespace std;

void search(list<int>& l, int& min, int& max) {
    list<int>::const_iterator it = l.begin();
    while (it != l.end()) {
        if (it == l.begin()) {
            min = *it;
            max = *it;
        } else if (max < *it) max = *it;
        else if (*it < min) min = *it;
        it++;
    }
}

void eliminar(list<int>& l, int m, int& sum, int& min, int& max) {
    bool borrado = false;
    list<int>::iterator it = l.begin();
    while (it != l.end() and not borrado) {
        if (*it == m) {
            it = l.erase(it);
            borrado = true;
            sum -=m;
        } else it++;
    }
    if (min == m) search(l, min, max);
    if (max == m) search(l, min, max);
}

void anadir(list<int>& l, int m, int& sum, int& min, int& max) {
    list<int>::iterator it = l.end();
    sum += m;
    if (it == l.begin()) {
        min = m;
        max = m;
    } else if (max < m) max = m;
    else if (m < min) min = m;
    l.insert(it, m);
}

int main() {
    list<int> l;
    int min = 0, max = 0, sum = 0;
    int n, m;
    while (cin >> n >> m and n != 0) {
        if (n == -1) anadir(l, m, sum, min, max);
        else if (n == -2) eliminar(l, m, sum, min, max);
        
        if (sum != 0) cout << min << " " << max << " " << (double) sum / l.size() << endl;
        else cout << 0 << endl;
    }
}
