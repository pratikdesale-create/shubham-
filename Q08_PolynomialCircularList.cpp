#include <iostream>
using namespace std;

struct Node
{
    int coeff;
    int px;
    int py;
    Node *next;
};

Node *createNode(int coeff, int px, int py)
{
    Node *newNode = new Node;
    newNode->coeff = coeff;
    newNode->px = px;
    newNode->py = py;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(Node *&head, int coeff, int px, int py)
{
    Node *newNode = createNode(coeff, px, py);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node *temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
}

void createPolynomial(Node *&head)
{
    int n, coeff, px, py;
    cout << "Enter number of terms: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter coefficient: ";
        cin >> coeff;
        cout << "Enter power of x: ";
        cin >> px;
        cout << "Enter power of y: ";
        cin >> py;
        insertTerm(head, coeff, px, py);
    }
}

void display(Node *head)
{
    if (head == NULL)
    {
        cout << "Polynomial is empty.\n";
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->coeff << "x^" << temp->px << "y^" << temp->py;
        temp = temp->next;
        if (temp != head)
            cout << " + ";
    } while (temp != head);
    cout << endl;
}

Node *addPolynomial(Node *p1, Node *p2)
{
    Node *result = NULL;
    Node *t1 = p1;
    if (t1 != NULL)
    {
        do
        {
            insertTerm(result, t1->coeff, t1->px, t1->py);
            t1 = t1->next;
        } while (t1 != p1);
    }
    Node *t2 = p2;
    if (t2 != NULL)
    {
        do
        {
            Node *temp = result;
            int found = 0;
            if (temp != NULL)
            {
                do
                {
                    if (temp->px == t2->px && temp->py == t2->py)
                    {
                        temp->coeff += t2->coeff;
                        found = 1;
                        break;
                    }
                    temp = temp->next;
                } while (temp != result);
            }
            if (!found)
                insertTerm(result, t2->coeff, t2->px, t2->py);
            t2 = t2->next;
        } while (t2 != p2);
    }
    return result;
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;
    int choice;
    do
    {
        cout << "\n1. Create polynomial 1\n2. Create polynomial 2\n";
        cout << "3. Display polynomial 1\n4. Display polynomial 2\n";
        cout << "5. Add two polynomials\n6. Display result\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            poly1 = NULL;
            createPolynomial(poly1);
            break;
        case 2:
            poly2 = NULL;
            createPolynomial(poly2);
            break;
        case 3:
            cout << "Polynomial 1: ";
            display(poly1);
            break;
        case 4:
            cout << "Polynomial 2: ";
            display(poly2);
            break;
        case 5:
            result = addPolynomial(poly1, poly2);
            cout << "Polynomials added successfully.\n";
            break;
        case 6:
            cout << "Result: ";
            display(result);
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
