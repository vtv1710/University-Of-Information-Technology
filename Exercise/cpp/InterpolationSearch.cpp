#include <iostream>
#include <string>
using namespace std;

int interpolationSearch(int a[], int key) {
    int lo = 0, hi = sizeof(a) - 1;
    int step = 1;
    while (lo <= hi && key >= a[lo] && key <= a[hi]) {
        cout << "Step " << step++ << ": Considering range from index " << lo << " to " << hi << " with minimum value " << a[lo] << " and maximum value " << a[hi] << "." << endl;
        if (lo == hi) {
            if (a[lo] == key) {
                cout << "Step " << step++ << ": Key " << key << " found at index " << lo << "." << endl;
                return lo;
            }
            break;
        }
        int pos = lo + (double)(hi - lo) / (a[hi] - a[lo]) * (key - a[lo]);
        cout << "Step " << step++ << ": Estimated position is " << pos << " with value " << a[pos] << "." << endl;
        if (a[pos] == key) {
            cout << "Step " << step++ << ": Success! Key " << key << " found at index " << pos << "." << endl;
            return pos;
        }
        if (a[pos] < key) {
            cout << "Step " << step++ << ": Value " << a[pos] << " is less than key " << key << ". Moving right." << endl;
            lo = pos + 1;
        }
        else {
            cout << "Step " << step++ << ": Value " << a[pos] << " is greater than key " << key << ". Moving left." << endl;
            hi = pos - 1;
        }
    }
    cout << "Step " << step++ << ": Key " << key << " not found in the array." << endl;
    return -1;
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    int key; cin >> key;
    int index = interpolationSearch(a, key);
    cout << "Result: " << (index != -1 ? "Key " + to_string(key) + " found at index " + to_string(index) : "Key does not exist in the array") << "." << endl;
    return 0;
}