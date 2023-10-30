#include <stdio.h>

int XORnums(int x, int y);

int main() {
    int inputNum = 0;
    while (inputNum != 1) {

        printf("Input char1\n");
        char c1;
        inputNum = scanf("%c", &c1);
        printf("%c is %d\n", c1, c1);
        if (inputNum != 1) continue;

        inputNum = 0;
        printf("Input char2\n");
        char c2;
        inputNum = scanf(" %c", &c2);
        printf("%c is %d\n",c2, c2);
        if (inputNum != 1) continue;

        char out;
        out = c1 ^ c2;

        printf("output is %d", out);
    }
    return 0;
}
