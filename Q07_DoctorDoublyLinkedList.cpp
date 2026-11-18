#include <iostream>
using namespace std;

struct Node
{
    char name[30];
    char specialization[30];
    char phone[15];
    Node *prev;
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
    cout << "Enter doctor name: ";
    cin >> newNode->name;
    cout << "Enter specialization: ";
    cin >> newNode->specialization;
    cout << "Enter phone number: ";
    cin >> newNode->phone;
    newNode->prev = NULL;
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
    newNode->prev = temp;
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
        cout << "Name: " << temp->name << endl;
        cout << "Specialization: " << temp->specialization << endl;
        cout << "Phone: " << temp->phone << endl;
        cout << "-------------------\n";
        temp = temp->next;
    }
}

void searchSpecialization()
{
    char spec[30];
    int found = 0;
    cout << "Enter specialization: ";
    cin >> spec;
    Node *temp = head;
    while (temp != NULL)
    {
        if (same(temp->specialization, spec))
        {
            cout << "Doctor: " << temp->name << endl;
            cout << "Phone: " << temp->phone << endl;
            found = 1;
        }
        temp = temp->next;
    }
    if (!found)
        cout << "No doctor found for this specialization.\n";
}

void reverseList()
{
    Node *current = head;
    Node *temp = NULL;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        head = temp->prev;
    cout << "List reversed successfully.\n";
}

int main()
{
    int choice, n;
    do
    {
        cout << "\n1. Create list\n2. Display list\n";
        cout << "3. Find doctors by specialization\n4. Reverse list\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number of doctors: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                append();
                cout << "Doctor added successfully.\n";
            }
            break;
        case 2:
            display();
            break;
        case 3:
            searchSpecialization();
            break;
        case 4:
            reverseList();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);
    return 0;
}
