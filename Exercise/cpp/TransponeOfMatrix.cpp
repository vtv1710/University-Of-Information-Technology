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

void ChuyenViMaTran(double a[MAXR][MAXC], double b[MAXR][MAXC], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }
}

void XuatMaTran(double a[MAXR][MAXC], int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    double a[MAXR][MAXC], b[MAXR][MAXC];
    int n, m;
    NhapMaTran(a, n, m);
    ChuyenViMaTran(a, b, n, m);
    XuatMaTran(b, n, m);
    return 0;
}