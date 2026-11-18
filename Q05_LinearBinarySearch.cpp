#include <iostream>
using namespace std;

int compare(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i])
        i++;
    return a[i] - b[i];
}

void copy(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void sort_names(char names[][50], int n)
{
    char key[50];
    for (int i = 1; i < n; i++)
    {
        copy(key, names[i]);
        int j = i - 1;
        while (j >= 0 && compare(names[j], key) > 0)
        {
            copy(names[j + 1], names[j]);
            j--;
        }
        copy(names[j + 1], key);
    }
}

int linear_search(char names[][50], int n, char key[], int &steps)
{
    steps = 0;
    for (int i = 0; i < n; i++)
    {
        steps++;
        if (compare(names[i], key) == 0)
            return i;
    }
    return -1;
}

int binary_search(char names[][50], int n, char key[], int &steps)
{
    int low = 0, high = n - 1;
    steps = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        steps++;
        int c = compare(names[mid], key);
        if (c == 0)
            return mid;
        else if (c < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n, choice, steps, result;
    char names[50][50], key[50];
    cout << "Enter the number of students: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of student " << i + 1 << ": ";
        cin.getline(names[i], 50);
    }
    do
    {
        cout << "\n1. Linear search\n2. Binary search\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            cout << "Enter name to search: ";
            cin.getline(key, 50);
            result = linear_search(names, n, key, steps);
            if (result != -1)
                cout << "Student found at position " << result + 1 << endl;
            else
                cout << "Student not found.\n";
            cout << "Comparisons: " << steps << endl;
        }
        else if (choice == 2)
        {
            sort_names(names, n);
            cout << "\nNames after sorting:\n";
            for (int i = 0; i < n; i++)
                cout << names[i] << endl;
            cout << "Enter name to search: ";
            cin.getline(key, 50);
            result = binary_search(names, n, key, steps);
            if (result != -1)
                cout << "Student found at position " << result + 1 << endl;
            else
                cout << "Student not found.\n";
            cout << "Comparisons: " << steps << endl;
        }
        else if (choice == 3)
            cout << "Exiting...\n";
        else
            cout << "Invalid choice\n";
    } while (choice != 3);
    return 0;
}
