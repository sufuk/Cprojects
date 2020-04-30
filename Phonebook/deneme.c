#include <stdio.h>
#include <string.h>
#include "PhonebookFunctions.h"

int main() {
    char operator;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operator);
    printf("Enter two operands: ");
    scanf("%lf %lf",&n1, &n2);

    switch(operator)
    {
        case '+':
            printf("");
            break;

        case '-':
            printf();
            break;

        case '*':
            printf();
            break;

        case '/':
            printf();
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}
