#include <iostream>
using namespace std;

struct Node
{
    char name[30];
    char location[30];
    int employees;
    Node *next;
};

Node *head = NULL;

int same(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i])
        i++;
    return a[i] == b[i];
}

Node *createNode()
{
    Node *newNode = new Node;
    cout << "Enter company name: ";
    cin >> newNode->name;
    cout << "Enter location: ";
    cin >> newNode->location;
    cout << "Enter number of employees: ";
    cin >> newNode->employees;
    newNode->next = NULL;
    return newNode;
}

void append()
{
    Node *newNode = createNode();
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void createList(int n)
{
    for (int i = 0; i < n; i++)
        append();
}

void addBeginning()
{
    Node *newNode = createNode();
    newNode->next = head;
    head = newNode;
    cout << "Company added at beginning.\n";
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Company: " << temp->name << endl;
        cout << "Location: " << temp->location << endl;
        cout << "Employees: " << temp->employees << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}

void findEmployees()
{
    char name[30];
    cout << "Enter company name: ";
    cin >> name;
    Node *temp = head;
    while (temp != NULL)
    {
        if (same(temp->name, name))
        {
            cout << "Number of employees: " << temp->employees << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Company not found.\n";
}

void findLocation()
{
    char name[30];
    cout << "Enter company name: ";
    cin >> name;
    Node *temp = head;
    while (temp != NULL)
    {
        if (same(temp->name, name))
        {
            cout << "Location: " << temp->location << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Company not found.\n";
}

int main()
{
    int choice, n;
    do
    {
        cout << "\n1. Create list\n2. Display list\n3. Append company\n";
        cout << "4. Add company at beginning\n5. Find number of employees\n";
        cout << "6. Find location\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of companies: ";
            cin >> n;
            createList(n);
            break;
        case 2:
            display();
            break;
        case 3:
            append();
            cout << "Company added successfully.\n";
            break;
        case 4:
            addBeginning();
            break;
        case 5:
            findEmployees();
            break;
        case 6:
            findLocation();
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 7);
    return 0;
}
