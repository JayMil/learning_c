
struct tnode {              /* tree node: */
    char *word;             /* points to the text */
    int count;              /* number of occurrences */
    struct tnode *left;     /* left child */
    struct tnode *right;    /* right child */
    struct tnode *parent;   /* parent node */
    int treeSize;           /* amount of nodes in tree. Tracked on root node only */
};

/* addtree: add a node with w, at or below child */
struct tnode *addtree(struct tnode *child, char *w, struct tnode *parent);

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p);

/* treeprintsorted: print tree sorted by count desc */
void treeprintsorted(struct tnode *root);

/* gettreesize: get amount of nodes in tree */
int gettreesize(struct tnode *p);
