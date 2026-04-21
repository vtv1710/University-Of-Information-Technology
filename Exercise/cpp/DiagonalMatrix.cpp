#include <iostream>
using namespace std;

int main() 
{
    int n, m; cin >> n >> m;
    double a[100][100];
    int cnt = 0, cnt0 = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
            if (a[i][j] == 0) cnt0++;
            if (i == j && a[i][j] == 0) cnt++;
            else if (i != j && a[i][j] != 0) cnt++;
        }
    }
    if (cnt0 == n * m) cout << "Yes";
    else if (cnt == 0) cout << "Yes";
    else cout << "No";
    return 0;
}