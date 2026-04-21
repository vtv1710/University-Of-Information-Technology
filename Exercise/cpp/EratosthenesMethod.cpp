#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm tất cả các số nguyên tố nhỏ hơn n bằng phương pháp Eratosthenes
void sieve_of_eratosthenes(int n, vector<bool>& primes) {
    primes[0] = primes[1] = false;  // 0 và 1 không phải là số nguyên tố
    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
}

// Hàm kiểm tra và in các cặp số nguyên tố sinh đôi
void print_twin_primes(int n) {
    vector<bool> primes(n + 1, true);
    sieve_of_eratosthenes(n, primes);

    int count = 0; // Biến đếm số cặp sinh đôi

    // Kiểm tra các cặp sinh đôi
    for (int i = 2; i <= n - 2; i++) {
        if (primes[i] && primes[i + 2]) {
            cout << "(" << i << ", " << i + 2 << ")" << endl;
            count++; // Tăng biến đếm khi tìm được cặp sinh đôi
        }
    }

    cout << "Tong: " << count << " " << "cap so sinh doi < " << n << endl;
}

int main() {
    int n;
    cin >> n;

    print_twin_primes(n);

    return 0;
}
