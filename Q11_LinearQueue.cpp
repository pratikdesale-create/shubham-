#include <iostream>
using namespace std;

const int MAX = 50;
int q[MAX];
int front = -1, rear = -1;

void insertToken(int token)
{
    if (rear == MAX - 1)
    {
        cout << "Queue is full.\n";
        return;
    }
    if (front == -1)
        front = 0;
    q[++rear] = token;
    cout << "Token " << token << " issued.\n";
}

void serveCustomer()
{
    if (front == -1)
    {
        cout << "No customers waiting.\n";
        return;
    }
    cout << "Serving token: " << q[front++] << endl;
    if (front > rear)
        front = rear = -1;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Waiting tokens: ";
    for (int i = front; i <= rear; i++)
        cout << q[i] << " ";
    cout << endl;
}

int main()
{
    int choice, token;
    do
    {
        cout << "\n1. Issue token\n2. Serve customer\n3. Display tokens\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter token number: ";
            cin >> token;
            insertToken(token);
            break;
        case 2:
            serveCustomer();
            break;
        case 3:
            display();
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
