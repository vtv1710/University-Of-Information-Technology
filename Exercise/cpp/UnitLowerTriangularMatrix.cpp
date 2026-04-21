#include <iostream>
using namespace std;

bool check(double a[][100], int n) 
{
    int cnt = -1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (i == j) 
            {
                if (a[i][j] != 1) return false;
            }
            else if (i > j) 
            {
                if (a[i][j] != 0) 
                {
                    if (cnt == -1) cnt = j;
                    else if (cnt != j) return false;
                }
            }
            else 
            {
                if (a[i][j] != 0) return false;
            }
        }
    }
    return true;
}

int main() 
{
    int n, m; cin >> n >> m;
    double a[100][100];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> a[i][j];
        }
    }
    if (check(a, n)) cout << "Yes";
    else cout << "No";
    return 0;
}