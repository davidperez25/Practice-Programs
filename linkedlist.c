#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE 1

typedef struct node {
    int number;
    struct node *next;

} node;

int main(int argc, char *argv[]) {
    node *list = NULL;

    for (int i = argc -1; i > 0; i--) {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL) {
            return FAILURE;
        }
        n->number = number;
        n->next = NULL;

        n->next = list;
        list = n;

    }

    node *ptr = list;

    for (node *ptr = list; ptr != NULL; ptr = ptr ->next) {
        printf("%i\n", ptr->number);
    }

    ptr = list;

    while (ptr != NULL) {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return SUCCESS;
}
