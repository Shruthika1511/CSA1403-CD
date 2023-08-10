#include <stdio.h>
#include <string.h>

#define NUM_NON_TERMINALS 3
#define NUM_TERMINALS 3
#define NUM_RULES 4

// Non-terminal symbols
enum NonTerminals {
    E, T, F
};

// Terminal symbols
enum Terminals {
    PLUS, TIMES, ID
};

// Parsing table
int parsingTable[NUM_NON_TERMINALS][NUM_TERMINALS] = {
    {1, 0, 0}, // E
    {0, 1, 0}, // T
    {0, 0, 1}  // F
};

// Production rules
char rules[NUM_RULES][10] = {
    "E -> TG",
    "G -> +TG",
    "G -> e",
    "T -> FZ"
};

int main() {
    char input[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);
    
    // Predictive parsing
    int stack[100]; // Using integers to represent symbols for simplicity
    int top = -1;
    stack[++top] = E; // Push start symbol
    
    int inputIndex = 0;
    
    while (top >= 0) {
        int symbol = stack[top--];
        
        if (symbol >= 0 && symbol < NUM_NON_TERMINALS) {
            int terminal = -1;
            switch (input[inputIndex]) {
                case '+': terminal = PLUS; break;
                case '*': terminal = TIMES; break;
                default: terminal = ID; break;
            }
            
            int production = parsingTable[symbol][terminal];
            if (production == 0) {
                printf("Error: No production in table for non-terminal %d and terminal %d\n", symbol, terminal);
                return 1;
            }
            
            printf("Using production: %s\n", rules[production - 1]);
            
            // Push the symbols of the production onto the stack in reverse order
            int len = strlen(rules[production - 1]);
            char nonTerminal = rules[production - 1][0];
            for (int i = len - 1; i >= 4; i--) {
                char symbol = rules[production - 1][i];
                if (symbol != ' ') {
                    if (symbol >= 'A' && symbol <= 'Z') {
                        stack[++top] = symbol - 'A'; // Convert non-terminal to index
                    } else if (symbol == 'e') {
                        // Skip epsilon
                    }
                }
            }
        } else if (symbol == input[inputIndex]) {
            inputIndex++;
        } else {
            printf("Error: Mismatch between symbol on stack and input\n");
            return 1;
        }
    }
    
    if (inputIndex == strlen(input)) {
        printf("Input successfully parsed!\n");
    } else {
        printf("Error: Parsing incomplete\n");
    }
    
    return 0;
}

