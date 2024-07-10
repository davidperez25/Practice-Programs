//cd [directory of the script]
//type nul > phonebook.csv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_string(char *prompt) {
    printf("%s", prompt);

    char uinput[100];
    scanf("%s", uinput);

    char *input = malloc(strlen(uinput) + 1);
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(input, uinput);

    return input;
}

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    char *name = get_string("Enter a name: ");
    char *number = get_string("Enter a number: ");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);


    return 0;
}
