#include <iostream>
using namespace std;

char st[100];
int top = -1;

void push(char x)
{
    st[++top] = x;
}

char pop()
{
    return st[top--];
}

int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int k = 0;
    cout << "Enter infix expression: ";
    cin >> infix;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            postfix[k++] = ch;
        else if (ch == '(')
            push(ch);
        else if (ch == ')')
        {
            while (top != -1 && st[top] != '(')
                postfix[k++] = pop();
            if (top != -1)
                pop();
        }
        else
        {
            while (top != -1 && st[top] != '(' && precedence(st[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
