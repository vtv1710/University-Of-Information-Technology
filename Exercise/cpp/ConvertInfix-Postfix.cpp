#include <iostream>
#include <stack>
using namespace std;

int doUuTien(char toanTu) 
{
    if (toanTu == '^') return 3;
    if (toanTu == '*' || toanTu == '/') return 2;
    if (toanTu == '+' || toanTu == '-') return 1;
    return 0;
}

string chuyenDoi(string bieuThuc) 
{
    stack<char> nganXep;
    string hauTo = ""; 

    for (char kyTu : bieuThuc) 
    {
        if (isalnum(kyTu)) hauTo += kyTu;
        else if (kyTu == '(') nganXep.push(kyTu);
        else if (kyTu == ')') {
            while (!nganXep.empty() && nganXep.top() != '(') 
            {
                hauTo += nganXep.top(); nganXep.pop();
            }
            nganXep.pop(); 
        }
        else 
        {
            while (!nganXep.empty() && doUuTien(nganXep.top()) >= doUuTien(kyTu)) 
            {
                hauTo += nganXep.top(); nganXep.pop();
            }
            nganXep.push(kyTu);
        }
    }
    while (!nganXep.empty()) 
    {
        hauTo += nganXep.top(); nganXep.pop();      
    }
    return hauTo;
}

int main() 
{
    string bieuThuc;
    cout << "Nhap bieu thuc: "; 
    cin >> bieuThuc;
    cout << "Hau to: " << chuyenDoi(bieuThuc) << endl;
}
