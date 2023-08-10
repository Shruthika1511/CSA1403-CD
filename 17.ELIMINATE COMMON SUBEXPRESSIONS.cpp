#include <stdio.h>

int main() {
    int a, b, c;
    
    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);
    
    // Common subexpression elimination
    int temp1 = a * b;
    int temp2 = temp1 + c;
    int result1 = temp2 - a;
    
    int temp3 = a * b;
    int temp4 = temp3 + c;
    int result2 = temp4 - b;
    
    printf("Result 1: %d\n", result1);
    printf("Result 2: %d\n", result2);
    
    return 0;
}

