#ifndef __RBT_H__
#define __RBT_H__
#define RED 0
#define BLACK 1

typedef struct Node {
    int value;
    int color;
    struct Node *parent, *leftChild, *rightChild;
} Node;


void leftR(Node **);
void rightR(Node **);
void insert(int);
void insertFixup(Node *);
void replace(Node **, Node *);
void delete(Node *);
void deleteFixup(Node *);
void clear(Node *x);
void print(Node *r, int);

Node *createRBT(void);
Node *search(int);
Node *min(Node *);
Node *max(Node *);

#endif
