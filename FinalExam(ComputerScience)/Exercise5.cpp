#include <iostream>
#include <string>
using namespace std;

void convert(string s) {
    string ans = "";
    int n = s.length();
    for (int i = 0; i < n;) {
        int cur = s[i];
        int cnt = 0;
        while (i < n && s[i] == cur) {
            cnt++; i++;
        }
        if (cnt > 1) {
            ans += cur;
            ans += to_string(cnt);
        }
        else ans += cur;
    }
    cout << ans << endl;
}

int main() {
    string s; cin >> s;
    convert(s);
    return 0;
}