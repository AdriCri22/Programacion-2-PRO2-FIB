#include <vector>
using namespace std;
 
 struct parint {int prim, seg;};
 
 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
    parint p;
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            p.prim = v[i];
            p.seg = v[i];
        } else {
            if (v[i] < p.seg) p.seg = v[i];
            if (v[i] > p.prim) p.prim = v[i];
        }
    }
    return p;
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {
     pair<int,int> pair;
     for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            pair.first = v[i];
            pair.second = v[i];
        } else {
            if (v[i] < pair.second) pair.second = v[i];
            if (v[i] > pair.first) pair.first = v[i];
        }
    }
    return pair;
 }
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
    for (int i = 0; i < v.size(); i++) {
        if (i == 0) {
            x = v[i];
            y = v[i];
        } else {
            if (v[i] < y) y = v[i];
            if (v[i] > x) x = v[i];
        }
    }
 }
