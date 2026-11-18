#include <iostream>
using namespace std;

int mx, mn;

void minmax(int arr[], int n)
{
    mx = arr[0];
    mn = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
        if (arr[i] < mn)
            mn = arr[i];
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element: ";
        cin >> arr[i];
    }
    minmax(arr, n);
    cout << "Max value is " << mx << endl;
    cout << "Min value is " << mn << endl;
    delete[] arr;
    return 0;
}
