#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter your full name: ");

    char str[20];

    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    printf("Your initials are: ");

    char *token;

    token = strtok(str, " ");

    while (token != NULL) {
        if ((int)*token >= 97) { token[0]-= 32;}
        printf("%c", token[0]);
        token = strtok(NULL, " ");
    }

    return 0;
}
