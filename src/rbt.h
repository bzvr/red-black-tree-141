#ifndef __RBT_H__
#define __RBT_H__
#define RED 0
#define BLACK 1

typedef struct Node {
    int key;
    int color;
    struct Node *parent, *leftChild, *rightChild;
} Node;

static char *Colors[] = {"R", "B"};

Node *nilLeaf;
Node *root;

void leftR(Node *);
void rightR(Node *);

void insert(int);
void insert_case2(Node *);
void insert_case3(Node *);
void insert_case4(Node *);
void insert_case5(Node *);
void insertFixup(Node *);
void replace(Node **, Node *);
void delete(Node *);
void deleteFixup(Node *);
void clear(Node *x);
void print(Node *r, int);
void print_keys(Node *x);

Node *createRBT(void);
Node *search(int);
Node *min(Node *);
Node *max(Node *);

#endif
