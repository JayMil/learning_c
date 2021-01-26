#include <stdio.h>
#include <ctype.h>

#include "binarytree.h"
#include "input.h"

#define MAXWORD 100

int main() {
    printf("== binary stree ==\n");

    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);

    treeprint(root);

    return 0;
}



