#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binarytree.h"
#include "sortedarray.h"

/* talloc: allocate memory for a new tnode */
struct tnode *talloc(void);

/* updatesize: update tree size in root node */
void updatesize(struct tnode *child, struct tnode *parent);

/* nodeprint: print node */
void nodeprint(struct tnode *p);

struct tnode *addtree(struct tnode *child, char *w, struct tnode *parent) {
    int cond;

    if (child == NULL) {        /* a new word has arrived */
        child = talloc();       /* make a new node */
        child->word = strdup(w);
        child->count = 1;
        child->left = child->right = NULL;
        child->parent = parent;
        child->treeSize = 0;
        updatesize(child, parent);
    } else if ((cond = strcmp(w, child->word)) == 0) {
        child->count++;         /* repeated word */
    } else if (cond < 0) {  /* less than into left subtree */
        child->left = addtree(child->left, w, child);
    } else {                /* greater than into right subtree */
        child->right = addtree(child->right, w, child);
    }


    return child;
}

void updatesize(struct tnode *child, struct tnode *parent) {
    if (parent == NULL) {
        child->treeSize += 1;
    } else {
        updatesize(parent, parent->parent);
    }
}

int gettreesize(struct tnode *p) {
    if (p == NULL) {
        return 0;
    } else if (p->parent == NULL) {
        return p->treeSize;
    } else {
        return gettreesize(p->parent);
    }
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        nodeprint(p);
        treeprint(p->right);
    }
}

void nodeprint(struct tnode *p) {
    printf("%4d %s\n", p->count, p->word);
}

void treeprintsorted(struct tnode *root) {
    if (root != NULL) {
        struct tnode **nodes = getsortednodes(root);
        int size = gettreesize(root);
        for (int i = 0; i < size; i++) {
            nodeprint(nodes[i]);
        }
    }
}

struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}
