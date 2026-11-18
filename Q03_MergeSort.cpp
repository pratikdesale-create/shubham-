#include <iostream>
using namespace std;

int count = 0;

void merge(int array[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *R = new int[n2];
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        count++;
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
    delete[] L;
    delete[] R;
}

void merge_sort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(array, left, mid);
        merge_sort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

int main()
{
    int n = 0, choice;
    int *array = 0;
    do
    {
        cout << "\n1. Enter elements\n2. Merge sort\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            array = new int[n];
            for (int i = 0; i < n; i++)
            {
                cout << "Enter element: ";
                cin >> array[i];
            }
            break;
        case 2:
            count = 0;
            merge_sort(array, 0, n - 1);
            cout << "Array sorted. Comparisons: " << count << endl;
            break;
        case 3:
            for (int i = 0; i < n; i++)
                cout << array[i] << " ";
            cout << endl;
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
