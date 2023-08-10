#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Quadruple {
    char op;
    char arg1[10];
    char arg2[10];
    char result[10];
};

struct Quadruple createQuadruple(char op, const char *arg1, const char *arg2, const char *result) {
    struct Quadruple quad;
    quad.op = op;
    strcpy(quad.arg1, arg1);
    strcpy(quad.arg2, arg2);
    strcpy(quad.result, result);
    return quad;
}

int main() {
    struct Quadruple quadruples[100];
    int quadCount = 0;

    // Sample input expression: a = b + c * d
    quadruples[quadCount++] = createQuadruple('+', "c", "d", "t1");
    quadruples[quadCount++] = createQuadruple('*', "b", "t1", "t2");
    quadruples[quadCount++] = createQuadruple('=', "t2", "-", "a");

    printf("Intermediate Code Quadruples:\n");
    printf("-----------------------------\n");
    printf("OP\tARG1\tARG2\tRESULT\n");
    printf("-----------------------------\n");
    for (int i = 0; i < quadCount; i++) {
        printf("%c\t%s\t%s\t%s\n", quadruples[i].op, quadruples[i].arg1, quadruples[i].arg2, quadruples[i].result);
    }

    return 0;
}

