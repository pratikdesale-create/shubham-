#include <iostream>
using namespace std;

struct Node
{
    int token, priority;
    Node *next;
};

Node *front = NULL;

void insertToken(int token, int priority)
{
    Node *n = new Node;
    n->token = token;
    n->priority = priority;
    n->next = NULL;
    if (front == NULL || priority < front->priority)
    {
        n->next = front;
        front = n;
    }
    else
    {
        Node *t = front;
        while (t->next != NULL && t->next->priority <= priority)
            t = t->next;
        n->next = t->next;
        t->next = n;
    }
    cout << "Token added to priority queue.\n";
}

void serveCustomer()
{
    if (front == NULL)
    {
        cout << "Priority queue is empty.\n";
        return;
    }
    Node *t = front;
    cout << "Serving token " << t->token << " with priority " << t->priority << endl;
    front = front->next;
    delete t;
}

void display()
{
    if (front == NULL)
    {
        cout << "Priority queue is empty.\n";
        return;
    }
    cout << "Token  Priority\n";
    Node *t = front;
    while (t != NULL)
    {
        cout << t->token << "      " << t->priority << endl;
        t = t->next;
    }
}

int main()
{
    int choice, token, priority;
    do
    {
        cout << "\n1. Insert token\n2. Serve customer\n3. Display queue\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter token number: ";
            cin >> token;
            cout << "Enter priority (1 is highest): ";
            cin >> priority;
            insertToken(token, priority);
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
