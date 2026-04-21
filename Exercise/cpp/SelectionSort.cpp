#include <iostream>
using namespace std;

void SelectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        cout << "Step " << i + 1 << ": Tim ptu nho nhat tu vi tri " << i << " den het mang." << endl;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min]) 
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        cout << "Mang sau sort step " << i + 1 << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;
    }
    cout << "Mang sau khi sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}

int main() 
{
    int n; cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++) cin >> arr[i];
    SelectionSort(arr, n);
    return 0;
}