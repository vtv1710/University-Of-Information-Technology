#include <iostream>
using namespace std;
#define MAXR 100
#define MAXC 100

void NhapMaTran(double a[MAXR][MAXC], int& n, int& m) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

bool check(double a[MAXR][MAXC], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != a[j][i]) return false;
        }
    }
    return true;
}

int main() {
    double a[MAXR][MAXC];
    int n, m;
    NhapMaTran(a, n, m);
    if (check(a, n, m)) cout << "Yes";
    else cout << "No";
    return 0;
}