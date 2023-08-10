#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent an intermediate code instruction
typedef struct {
    char op[10]; // Operation (e.g., "ADD", "SUB", "MUL")
    char arg1[10]; // First operand
    char arg2[10]; // Second operand
    char result[10]; // Result variable
} IntermediateCode;

// Generate intermediate code for a simple expression
void generateIntermediateCode(IntermediateCode *code, const char *op, const char *arg1, const char *arg2, const char *result) {
    strcpy(code->op, op);
    strcpy(code->arg1, arg1);
    strcpy(code->arg2, arg2);
    strcpy(code->result, result);
}

int main() {
    // Initialize intermediate code array
    IntermediateCode code[10];
    
    // Generate intermediate code for an expression: result = (a + b) * c
    generateIntermediateCode(&code[0], "ADD", "a", "b", "t1");
    generateIntermediateCode(&code[1], "MUL", "t1", "c", "result");
    
    // Print generated intermediate code
    printf("Intermediate Code:\n");
    for (int i = 0; i < 2; i++) {
        printf("%s %s, %s, %s\n", code[i].op, code[i].arg1, code[i].arg2, code[i].result);
    }
    
    return 0;
}

