#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct match {
    int one, two;
};

struct team {
    int number, points, scored, received;
};

typedef vector<match> Row;
typedef vector<Row> Matrix;

typedef vector<team> Teams;

Matrix read_matrix(int n) {
    Matrix m(n, Row(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            match match;
            cin >> match.one >> match.two;
            m[i][j] = match;
        }
    }
    return m;
}

Teams results(Matrix m, int n) {
    Teams teams(n);
    for (int k = 0; k < n; k++) {
        teams[k].number = k + 1;
        //search by rows
        for (int j = 0; j < n; j++) {
            if (j != k) {
                teams[k].scored += m[k][j].one;
                teams[k].received += m[k][j].two;
                if (m[k][j].one > m[k][j].two) teams[k].points += 3;
                if (m[k][j].one == m[k][j].two) teams[k].points += 1;
            }
        }
        //search by columns
        for (int i = 0; i < n; i++) {
            if (i != k) {
                teams[k].scored += m[i][k].two;
                teams[k].received += m[i][k].one;
                if (m[i][k].one < m[i][k].two) teams[k].points += 3;
                if (m[i][k].one == m[i][k].two) teams[k].points += 1;
            }
        }
    }
    return teams;
}

bool comp(team t1, team t2) {
    if (t1.points != t2.points) return t1.points > t2.points;
    else {
        if (t1.scored - t1.received != t2.scored - t2.received) return t1.scored - t1.received > t2.scored - t2.received;
        else return t1.number < t2.number;
    }
}
 
int main() {
    int n;
    cin >> n;
    Matrix m = read_matrix(n);
    
    Teams teams = results(m, n);
    sort(teams.begin(), teams.end(), comp);
    
    for (int i = 0; i < n; i++) cout << teams[i].number << " " << teams[i].points << " " << teams[i].scored << " " << teams[i].received << endl;
}
