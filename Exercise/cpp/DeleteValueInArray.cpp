#include <iostream>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int x; cin >> x;
    for (int i = 1; i <= n; i++) 
    {
        if (a[i] == x) a[i] = -1;
    }
    for (int i = 1; i <= n; i++) 
    {
        if (a[i] == -1) cout << "";
        else cout << a[i] << " ";
    }
}