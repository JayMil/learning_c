#include <stdlib.h>

#include "binarytree.h"
#include "sortedarray.h"

/* tsalloc: allocate pointer array to tnodes */
struct tnode **tsalloc(int n);

/* addnodes: recursivly add tree tnodes to nodes array - return count of nodes */
int addnodes(struct tnode **nodes, struct tnode *node, int count);

/* addnode: add tnode to array of tnodes returning count+1 */
int addnode(struct tnode **nodes, struct tnode *node, int count);

/* shiftnodes: shift nodes in array to the right by one starting at start */
void shiftnodes(struct tnode **nodes, int start, int count);

struct tnode **getsortednodes(struct tnode *p) {
    // allocate memorty for 
    int size = gettreesize(p);
    int count = 0;
    struct tnode **tnodes = tsalloc(size);
    count = addnodes(tnodes, p, count);
    return tnodes;
}

struct tnode **tsalloc(int n) {
    return (struct tnode **) malloc(sizeof(struct tnode*) * n);
}

int addnodes(struct tnode **nodes, struct tnode *node, int count) {
    if (node != NULL) {
        count = addnodes(nodes, node->left, count);
        count = addnode(nodes, node, count);
        count = addnodes(nodes, node->right, count);
    }
    return count;
}

int addnode(struct tnode **nodes, struct tnode *node, int count) {
    if (count == 0) {
        nodes[count] = node;
    } else {
        int i = 0;
        while (i < count && nodes[i]->count > node->count)
            i++;
        
        shiftnodes(nodes, i, count);
        nodes[i] = node;
    }
    return count+1;
}

void shiftnodes(struct tnode **nodes, int start, int count) {
    for (int i = count-1; i >= start; i--) {
        nodes[i+1] = nodes[i];
    }
}

