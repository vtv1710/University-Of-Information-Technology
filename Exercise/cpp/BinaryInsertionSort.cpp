#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        cout << "So sanh voi arr[" << mid << "] = " << arr[mid] << endl;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

void BinaryInsertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        cout << "Chon key: " << key << endl;
        int j = binarySearch(arr, i, key);
        cout << "Tim vi tri de chen: " << j << endl;
        cout << "Mang truoc khi di chuyen cac ptu: ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
        for (int k = i; k > j; k--) 
        {
            arr[k] = arr[k - 1];
            cout << "Di chuyen arr[" << k << "] = " << arr[k] << " sang phai." << endl;
        }
        arr[j] = key;
        cout << "Chen key vao vi tri " << j << ": " << key << endl;
        cout << "Mang sau khi chen key: ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
}

int main() 
{
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    BinaryInsertionSort(arr, n);
    return 0;
}