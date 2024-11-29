#include <stdio.h>
#include <string.h>

int currentIndex = 0, pos = 0, top = -1, length;
char symbol, temp, infix[20], postfix[20], stack[20];

void infixtopostfix();
void push(char symbol);
char pop();
int pred(char symb);

int main() {
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixtopostfix();

    printf("\nInfix expression: %s", infix);
    printf("\nPostfix expression: %s\n", postfix);

    return 0;
}

void infixtopostfix() {
    length = strlen(infix);
    push('#'); 

    while (currentIndex < length) {
        symbol = infix[currentIndex];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(') {
                    postfix[pos++] = temp;
                    temp = pop();
                }
                break;
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while (pred(stack[top]) >= pred(symbol)) {
                    temp = pop();
                    postfix[pos++] = temp;
                }
                push(symbol);
                break;
            default: 
                postfix[pos++] = symbol;
        }
        currentIndex++;
    }

    
    while (top > 0) {
        temp = pop();
        postfix[pos++] = temp;
    }

    postfix[pos] = '\0'; 
}

void push(char symbol) {
    top = top + 1;
    stack[top] = symbol;
}

char pop() {
    char symb = stack[top];
    top = top - 1;
    return symb;
}

int pred(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
        case '#':
            return 0;
        default:
            return -1; 
    }
}
