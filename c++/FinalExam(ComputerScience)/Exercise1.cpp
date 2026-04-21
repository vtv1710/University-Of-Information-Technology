#include <iostream>
using namespace std;

void convert(int** a, int m, int n) {
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            cout << a[top][i] << " ";
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            cout << a[i][right] << " ";
        }
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                cout << a[bottom][i] << " ";
            }
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                cout << a[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    int m, n; cin >> m >> n;
    int** a = new int* [m];
    for (int i = 0; i < m; i++) a[i] = new int[n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    convert(a, m, n);
    return 0;
}