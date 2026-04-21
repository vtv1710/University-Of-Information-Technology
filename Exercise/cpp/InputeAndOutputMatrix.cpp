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

void XuatMaTran(double a[MAXR][MAXC], int n, int m) {
    double s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j) s += a[i][j];
        }
    }
    cout << s;
}

int main() {
    double a[MAXR][MAXC];
    int n, m;
    NhapMaTran(a, n, m);
    XuatMaTran(a, n, m);
    return 0;
}