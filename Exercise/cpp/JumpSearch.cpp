#include <iostream>
#include <string>
using namespace std;

int jumpSearch(int a[], int key) {
    int n = sizeof(a);
    int step = 1, blockSize = sqrt(n);
    cout << "Step " << step++ << ": Determined block size is " << blockSize << endl;
    int prev = 0;
    while (a[min(blockSize, n) - 1] < key) {
        cout << "Step " << step++ << ": At position " << min(blockSize, n) - 1 << " the value is " << a[min(blockSize, n) - 1] << ", which is less than key " << key << endl;
        prev = blockSize;
        blockSize += sqrt(n);
        if (prev >= n) {
            cout << "Step " << step++ << ": Exceeded the array bounds." << endl;
            return -1;
        }
    }
    cout << "Step " << step++ << ": Performing linear search in the range from index " << prev << " to " << min(blockSize, n) - 1 << endl;
    for (int i = prev; i < min(blockSize, n); i++) 
    {
        cout << "Step " << step++ << ": Checking index " << i << " with value " << a[i] << endl;
        if (a[i] == key) 
        {
            cout << "Step " << step++ << ": Key " << key << " found at index " << i << endl;
            return i;
        }
    }
    cout << "Step " << step++ << ": Key " << key << " was not found in the determined range." << endl;
    return -1;
}

int main() 
{
    int n; cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    int key; cin >> key;
    int index = jumpSearch(a, key);
    cout << "Result: " << (index != -1 ? "Key " + to_string(key) + " found at index " + to_string(index) : "Key does not exist in the array") << endl;
    return 0;
}