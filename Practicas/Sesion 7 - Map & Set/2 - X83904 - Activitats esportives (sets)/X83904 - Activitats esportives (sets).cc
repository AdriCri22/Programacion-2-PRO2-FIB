#include <set>
#include <iostream>
using namespace std;

void write_cog(set<string> cognoms ) {
    set<string>::const_iterator it = cognoms.begin();
    while (it != cognoms.end()) {
        cout << " " << *it;
        it++;
    }
    cout << endl;
}

int main() {
    set<string> cognoms;
    string str;
    while (cin >> str and str != ".") {
        cognoms.insert(str);
    }
    
    int n_activitats;
    cin >> n_activitats;
    set<string> cog_cap_act = cognoms;
    for (int i = 0; i < n_activitats; i++) {
        set<string> cog_tot;
        while (cin >> str and str != ".") {
            if (cognoms.find(str) != cognoms.end()) cog_tot.insert(str);
            if (cognoms.find(str) != cognoms.end()) cog_cap_act.erase(str);
        }
        cognoms = cog_tot;
    }
    
    cout << "Totes les activitats:";
    write_cog(cognoms);
    cout << "Cap activitat:";
    write_cog(cog_cap_act);
}
