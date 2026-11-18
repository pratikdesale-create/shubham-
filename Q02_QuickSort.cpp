#include <iostream>
using namespace std;

int count = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void quick_sort(int arr[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < high)
            {
                i++;
                count++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
                count++;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quick_sort(arr, low, j - 1);
        quick_sort(arr, j + 1, high);
    }
}

int main()
{
    int n = 0, choice;
    int *arr = 0;
    do
    {
        cout << "\n1. Enter elements\n2. Quick sort\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            arr = new int[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Enter element: ";
                cin >> arr[i];
            }
            break;
        case 2:
            count = 0;
            quick_sort(arr, 0, n - 1);
            cout << "Array sorted. Comparisons: " << count << endl;
            break;
        case 3:
            display(arr, n);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 4);
    return 0;
}
