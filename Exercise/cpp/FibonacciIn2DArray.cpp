#include <iostream>
using namespace std;

int fibo(int n) {
    if (n == 1 || n == 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

void Nhapmang(int a[MAX][MAX], int& n) {
    cin >> n;
}

void Xuatmang(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = fibo(i + j + 1);
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}