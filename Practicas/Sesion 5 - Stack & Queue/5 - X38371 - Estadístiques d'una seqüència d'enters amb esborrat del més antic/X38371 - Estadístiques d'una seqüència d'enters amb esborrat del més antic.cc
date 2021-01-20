#include <iostream>
#include <queue>
using namespace std;

int search_min(const queue<int>& cola) {
    queue<int> cola2 = cola;
    int min = cola2.front();
    cola2.pop();
    while (not cola2.empty()) {
        if (cola2.front() < min) min = cola2.front();
        cola2.pop();
    }
    return min;
}

int search_max(const queue<int>& cola) {
    queue<int> cola2 = cola;
    int max = cola2.front();
    cola2.pop();
    while (not cola2.empty()) {
        if (cola2.front() > max) max = cola2.front();
        cola2.pop();
    }
    return max;
}

int main() {
    int n;
    
    int sum = 0;
    int min = 0, max = 0;
    bool first = true;
    queue<int> cola;
    while (cin >> n and -1002 < n and n < 1001) {
        if (-1000 <= n and n <= 1000) {
            if (first) {
                min = n;
                max = n;
                first = false;
            }
            if (not first and n < min) min = n;
            if (not first and max < n) max = n;
            cola.push(n);
            sum += n;
            double media = (double) sum / cola.size();
            cout << "min " << min << "; max " << max << "; media " << media << endl;
        } else if (n == -1001 and cola.size() > 1) {
            int c = cola.front();
            sum -= c;
            cola.pop();
            if (max == c) max = search_max(cola);
            if (min == c) min = search_min(cola);
            double media = (double) sum / cola.size();
            cout << "min " << min << "; max " << max << "; media " << media << endl;
        } else {
            if (cola.size() == 1) cola.pop();
            sum = 0;
            first = true;
            cout << 0 << endl;
        }
    }
}
