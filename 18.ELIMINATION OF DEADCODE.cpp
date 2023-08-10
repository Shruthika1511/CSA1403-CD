#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    int z = 0;
    
    if (x > 2) {
        y = x + y;
    } else {
        z = x + y;
    }
    
    // Dead code
    z = z + 5;
    
    printf("Result: %d\n", y);
    
    return 0;
}

