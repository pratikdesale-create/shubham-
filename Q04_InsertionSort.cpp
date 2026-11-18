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

void insertion_sort(char names[][50], int n)
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

int main()
{
    int n = 0, choice;
    char names[50][50];
    do
    {
        cout << "\n1. Enter names\n2. Insertion sort\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of students: ";
            cin >> n;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                cout << "Enter name of student " << i + 1 << ": ";
                cin.getline(names[i], 50);
            }
            break;
        case 2:
            insertion_sort(names, n);
            cout << "Names sorted.\n";
            break;
        case 3:
            for (int i = 0; i < n; i++)
                cout << names[i] << endl;
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
