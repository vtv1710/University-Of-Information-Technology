#include <iostream>
using namespace std;

void InsertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        cout << "Step " << i << ": Chon key = " << key << endl;
        cout << "Bat dau so sanh voi ptu dung truoc no...\n";
        while (j >= 0 && arr[j] > key) {
            cout << "So sanh arr[" << j << "] = " << arr[j] << " voi key = " << key << endl;
            arr[j + 1] = arr[j];
            cout << "Mang sau khi di chuyen: ";
            for (int k = 0; k < n; k++) cout << arr[k] << " ";
            cout << endl;
            j--;
        }
        arr[j + 1] = key;
        cout << "Chen key = " << key << " vao vi tri " << j + 1 << endl;
        cout << "Mang sau step " << i << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    InsertionSort(arr, n);
    return 0;
}