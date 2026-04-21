#include<iostream>
using namespace std;

int const maxn = 1000000;
bool nt[maxn + 1];

void Nhap(int a[], int& n) 
{
    for (int i = 0; i < n; i++) cin >> a[i];
}

void sang() 
{
    for (int i = 2; i <= maxn; i++) nt[i] = true;
    for (int i = 2; i <= sqrt(maxn); i++) 
    {
        if (nt[i]) 
        {
            for (int j = i * i; j <= maxn; j += i) 
            {
                nt[j] = false;
            }
        }
    }
}

int main() 
{
    sang();
    int a[100], n, cnt = 0;
    cin >> n;
    Nhap(a, n);
    for (int i = 0; i < n; i++) 
    {
        if (nt[a[i]]) 
        {
            cout << a[i] << " ";
            cnt++;
        }
    }
    if (cnt == 0) cout << 0;
    return 0;
}