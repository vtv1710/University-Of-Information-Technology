#include <iostream>
using namespace std;

bool isPalindrome(int n) {
    int original = n;  
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;  
        reversed = reversed * 10 + digit;  
        n /= 10;  
    }
    return original == reversed;
}

int main() {
    int number;
    cin >> number;

    if (isPalindrome(number)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
