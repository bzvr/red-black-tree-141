#ifndef __RBT_H__
#define __RBT_H__
#define RED 0
#define BLACK 1

typedef struct Node {
    int value;
    int color;
    struct Node *parent, *leftChild, *rightChild;
} Node;


void leftR(Node *);
void rightR(Node *);
void insert(int);
void insertFixup(Node *);
void replace(Node *, Node *);
void delete(Node *);
void deleteFixup(Node *);

Node *createRBT(void);
Node *tree_search(int);
Node *min(Node *);
Node *max(Node *);

#endif
