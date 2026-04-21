#include <iostream>
using namespace std;

void NhapMang(float a[100][100], int& n, int& m) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }
}

int main() 
{
    int n, m; cin >> m >> n;
    float a[100][100], b[100][100];
    NhapMang(a, m, n);
    int l, k; cin >> l >> k;
    NhapMang(b, l, k);
    float c[m][k];
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            c[i][j] = 0;
            for (int l = 0; l < n; l++) 
            {
                c[i][j] += a[i][l] * b[l][j];
            }
        }
    }
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}