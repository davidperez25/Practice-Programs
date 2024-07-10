#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main(void)
{
    printf("Enter a string to copy: ");

    char s[MAX];
    scanf("%99s", s);

    char *t = malloc(strlen(s) + 1);

    if(t == NULL) {
        fprintf(stderr, "Program returned 1: Memory allocation failed.");
        return 1;
    }

    strcpy(t, s);

    if (strlen(t)) {
        if((unsigned int)t[0] >= 97 && (unsigned int)t[0] <= 122) {
            t[0] -= 32;
        }
    }
    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);

    return 0;
}
