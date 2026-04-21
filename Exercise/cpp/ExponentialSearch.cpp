#include <iostream>
#include <string>
using namespace std;

int binarySearch(int a[], int lo, int hi, int key, int& step)
{
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        cout << "Step " << step++ << ": Binary Search checks position " << mid << " with value " << a[mid] << endl;
        if (a[mid] == key)
        {
            cout << "Step " << step++ << ": Key " << key << " found at position " << mid << endl;
            return mid;
        }
        else if (a[mid] < key)
        {
            cout << "Step " << step++ << ": Value " << a[mid] << " is less than key " << key << ". Searching to the right." << endl;
            lo = mid + 1;
        }
        else
        {
            cout << "Step " << step++ << ": Value " << a[mid] << " is greater than key " << key << ". Searching to the left." << endl;
            hi = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(int a[], int n, int key)
{
    int step = 1;
    cout << "Step " << step++ << ": Starting Exponential Search on the sorted array." << endl;
    if (a[0] == key)
    {
        cout << "Step " << step++ << ": The first element matches the key " << key << endl;
        return 0;
    }
    int i = 1;
    while (i < n && a[i] <= key)
    {
        cout << "Step " << step++ << ": Checking position " << i << " with value " << a[i] << endl;
        i *= 2;
    }
    int lo = i / 2;
    int hi = min(i, n) - 1;
    cout << "Step " << step++ << ": Determined search range for Binary Search from index " << lo << " to " << hi << endl;
    return binarySearch(a, lo, hi, key, step);
}

int main()
{
    int n;
    cin >> n;
    int a[100];
    for (int i = 0; i < n; i++) cin >> a[i];
    int key; cin >> key;

    int index = exponentialSearch(a, n, key);
    cout << "Result: " << (index != -1 ? "Key " + to_string(key) + " found at index " + to_string(index)
        : "Key does not exist in the array") << endl;
    return 0;
}
