#include <iostream>
using namespace std;

int isPrime(int n) {
    if (n == 1) return -1; // Không phải số nguyên tố cũng không phải số hợp thành
    if (n == 2) return 1;  // Số 2 là số nguyên tố
    if (n % 2 == 0) return 0; // Các số chẵn khác 2 không phải số nguyên tố
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0; // Số n có ước khác 1 và chính nó, không phải số nguyên tố
    }
    return 1; // Nếu không tìm thấy ước nào khác, n là số nguyên tố
}

int main() {
    int n;
    cin >> n;
    int result = isPrime(n);
    if (result == 1) {
        cout << "1" << endl;
    }
    else if (result == 0) {
        cout << "0" << endl;
    }
    else {
        cout << "-1" << endl;
    }
    return 0;
}
