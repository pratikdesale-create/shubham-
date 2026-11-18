#include <iostream>
using namespace std;

const int MAX = 50;
int q[MAX];
int front = -1, rear = -1;

void insertToken(int token)
{
    if ((rear + 1) % MAX == front)
    {
        cout << "Queue is full.\n";
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % MAX;
    q[rear] = token;
    cout << "Token " << token << " issued.\n";
}

void serveCustomer()
{
    if (front == -1)
    {
        cout << "No customers waiting.\n";
        return;
    }
    cout << "Serving token: " << q[front] << endl;
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void display()
{
    if (front == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Waiting tokens: ";
    int i = front;
    while (1)
    {
        cout << q[i] << " ";
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
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
