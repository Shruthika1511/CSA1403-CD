#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isNum(char c) {
    return isdigit(c);
}

bool isOperator(char c) {
    return c == '+' || c == '*';
}

bool E(char* str, int* index);

bool T(char* str, int* index) {
    return E(str, index);
}

bool F(char* str, int* index) {
    char c = str[*index];
    if (isNum(c)) {
        (*index)++;
        return true;
    } else if (c == '(') {
        (*index)++;
        bool result = E(str, index);
        if (str[*index] == ')') {
            (*index)++;
            return result;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool E(char* str, int* index) {
    int start = *index;
    if (T(str, index)) {
        if (isOperator(str[*index])) {
            (*index)++;
            bool result = T(str, index);
            if (result && str[*index] != ')' && str[*index] != '\0') {
                printf("Ambiguous expression: %.*s\n", *index - start, str + start);
                return true;
            } else {
                return result;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {
    char input[100];
    printf("Enter an expression: ");
    scanf("%s", input);

    int index = 0;
    if (E(input, &index) && input[index] == '\0') {
        printf("Expression is not ambiguous.\n");
    } else {
        printf("Expression is ambiguous.\n");
    }

    return 0;
}

