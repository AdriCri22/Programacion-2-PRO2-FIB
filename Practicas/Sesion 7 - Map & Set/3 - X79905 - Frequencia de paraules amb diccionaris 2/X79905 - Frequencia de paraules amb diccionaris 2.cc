#include <map>
#include <iostream>
using namespace std;

int main() {
    map<string, int> d;
    
    char c;
    string str;
    while (cin >> c >> str) {
        if (c == 'a') d[str]++;
        else if (c == 'f') cout << d[str] << endl;
        else if (c == 'e' and d[str] != 0) d[str]--;
    }
}
