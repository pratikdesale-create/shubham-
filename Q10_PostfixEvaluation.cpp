#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *topNode = NULL;
int error = 0;

void push(int value)
{
    Node *n = new Node;
    n->data = value;
    n->next = topNode;
    topNode = n;
}

int pop()
{
    if (topNode == NULL)
    {
        error = 1;
        return 0;
    }
    Node *t = topNode;
    int value = t->data;
    topNode = topNode->next;
    delete t;
    return value;
}

int main()
{
    char exp[100];
    cout << "Enter postfix expression (single digit operands): ";
    cin >> exp;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (ch >= '0' && ch <= '9')
            push(ch - '0');
        else
        {
            int b = pop();
            int a = pop();
            int result = 0;
            if (error)
            {
                cout << "Stack underflow.\n";
                return 0;
            }
            switch (ch)
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                if (b == 0)
                {
                    cout << "Division by zero.\n";
                    return 0;
                }
                result = a / b;
                break;
            default:
                cout << "Invalid operator.\n";
                return 0;
            }
            push(result);
        }
    }
    int answer = pop();
    if (error)
    {
        cout << "Stack underflow.\n";
        return 0;
    }
    cout << "Result = " << answer << endl;
    return 0;
}
