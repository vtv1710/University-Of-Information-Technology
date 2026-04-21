#include <iostream>
using namespace std;

void BubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        cout << "Mang sau khi sort lan " << i + 1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
        if (!swapped) break;
    }
}

int main() 
{
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    BubbleSort(arr, n);
    return 0;
}