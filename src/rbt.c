#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

#define COUNT 10
Node *root;
Node *nilLeaf;

Node *createRBT(void) {
    // выделение памяти под черный лист (пустое дерево)
    int k;
    nilLeaf = malloc(sizeof(Node));
    nilLeaf->color = BLACK;
    nilLeaf->leftChild = NULL;
    nilLeaf->rightChild = NULL;
    if (scanf("%d", &k) == 1) {
        if (k == 0){
            free(nilLeaf);
            return NULL;
        }
        root = malloc(sizeof(Node));
        root->color = BLACK;
        root->leftChild = nilLeaf;
        root->rightChild = nilLeaf;
        root->key = k;
        root->parent = NULL;
    } else return NULL;
    while (scanf("%d", &k), k != 0) {
        insert(k);
    }
    return root;
}

void leftR(Node *r) {
    if (r == NULL) { exit(1); }
    Node *d = r->rightChild;
    if (d == NULL) exit(1);

    if ((d->parent = r->parent) == NULL) root = d;
    else if (r->parent->rightChild == r) r->parent->rightChild = d;
    else r->parent->leftChild = d;

    r->rightChild = d->leftChild;
    if (d->leftChild != nilLeaf) d->leftChild->parent = r;
    d->leftChild = r;
    r->parent = d;
}

void rightR(Node *r) {
    if (r == NULL) exit(1);
    Node *d = r->leftChild;
    if (d == NULL) exit(1);

    if ((d->parent = r->parent) == NULL) root = d;
    else if (r->parent->rightChild == r) r->parent->rightChild = d;
    else r->parent->leftChild = d;

    r->leftChild = d->rightChild;
    if (d->rightChild != nilLeaf) d->rightChild->parent = r;
    d->rightChild = r;
    r->parent = d;
}

void insert(int value) {
    Node *ptr, *current;
    if (!root) {
        root = malloc(sizeof(Node));
        nilLeaf = malloc(sizeof(Node));
        nilLeaf->color = BLACK;
        nilLeaf->leftChild = NULL;
        nilLeaf->rightChild = NULL;
        root->color = BLACK;
        root->key = value;
        root->leftChild = nilLeaf;
        root->rightChild = nilLeaf;
        root->parent = NULL;
        return;
    }
    current = root;
    while (!(current->leftChild == nilLeaf && current->rightChild == nilLeaf)) {
        if (current->key > value && current->leftChild != nilLeaf) current = current->leftChild;
        else {
            if (current->key <= value && current->rightChild != nilLeaf) current = current->rightChild;
            else break;
        }
    }
    ptr = malloc(sizeof(Node));
    ptr->key = value;
    ptr->leftChild = nilLeaf;
    ptr->rightChild = nilLeaf;
    ptr->parent = current;
    ptr->color = RED;
    if (value < current->key) current->leftChild = ptr;
    else current->rightChild = ptr;
    insertFixup(ptr);
}

void insertFixup(Node *z) {
    if (z->parent == NULL)
        z->color = BLACK;
    else
        insert_case2(z);
}

void insert_case2(Node *z) {
    if (z->parent->color == BLACK)
        return;
    else
        insert_case3(z);
}

void insert_case3(Node *z) {
    Node *uncle;
    if (z->parent->parent) {
        if (z->parent->parent->leftChild != z->parent) uncle = z->parent->parent->leftChild;
        else uncle = z->parent->parent->rightChild;
        if (uncle->color == RED) {
            uncle->color = BLACK;
            uncle->parent->color ^= 1;
            z->parent->color ^= 1;
            insertFixup(uncle->parent);
        } else
            insert_case4(z);
    }
}

void insert_case4(Node *z) {
    if ((z->parent->rightChild == z) && (z->parent == z->parent->parent->leftChild)) {
        leftR(z->parent);
        z = z->leftChild;
    } else {
        if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->rightChild)) {
            rightR(z->parent);
            z = z->rightChild;
        }
    }
    insert_case5(z);
}

void insert_case5(Node *z) {
    z->parent->color ^= 1;
    z->parent->parent->color ^= 1;
    if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->leftChild))
        rightR(z->parent->parent);
    else
        leftR(z->parent->parent);
}

void replace(Node *a, Node *b) {
    if (a->parent == NULL) {
        root = b;
    } else if (a->parent->leftChild == a) a->parent->leftChild = b;
    else a->parent->rightChild = b;
    b->parent = a->parent;
}

void delete(Node *z) {
    Node *d = z;
    Node *x;

    int origColor = d->color;

    if (z->leftChild == nilLeaf) {
        x = z->rightChild;
        replace(z, z->rightChild);
    } else if (z->rightChild == nilLeaf) {
        x = z->leftChild;
        replace(z, z->leftChild);
    } else {
        d = min(z->rightChild);
        origColor = d->color;
        x = d->rightChild;
        if (d->parent == z) {
            x->parent = d;
        } else {
            replace(d, d->rightChild);
            d->rightChild = z->rightChild;
            d->rightChild->parent = d;
        }
        replace(z, d);
        d->leftChild = z->leftChild;
        d->leftChild->parent = d;
        d->color = z->color;
    }
    if (origColor == BLACK) {
        deleteFixup(x);
    }
    if (root == nilLeaf) {
        free(root);
        root = NULL;
    }
}

void deleteFixup(Node *x) {
    Node *v;
    while (x->color == BLACK && x != root) {
        if (x == x->parent->leftChild) {
            v = x->parent->rightChild;
            if (v->color == RED) {
                v->color = BLACK;
                x->parent->color = RED;
                leftR(x->parent);
                v = x->parent->rightChild;
            }
            if (v->leftChild->color == BLACK && v->rightChild->color == BLACK) {
                v->color = RED;
                x->parent->color = BLACK;
                x = x->parent;
            } else {
                if (v->rightChild->color == BLACK) {
                    v->leftChild->color = BLACK;
                    v->color = RED;
                    rightR(v);
                    v = x->parent->rightChild;
                }
                v->color = x->parent->color;
                x->parent->color = BLACK;
                v->rightChild->color = BLACK;
                leftR(x->parent);
                x = root;
            }
        } else {
            v = x->parent->leftChild;
            if (v->color == RED) {
                v->color = BLACK;
                x->parent->color = RED;
                rightR(x->parent);
                v = x->parent->leftChild;
            }
            if (v->rightChild->color == BLACK && v->leftChild->color == BLACK) {
                v->color = RED;
                x->parent->color = BLACK;
                x = x->parent;
            } else {
                if (v->leftChild->color == BLACK) {
                    v->rightChild->color = BLACK;
                    v->color = RED;
                    leftR(v);
                    v = x->parent->leftChild;
                }
                v->color = x->parent->color;
                x->parent->color = BLACK;
                v->leftChild->color = BLACK;
                rightR(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void clear(Node *r) {
    if ((r->leftChild == nilLeaf && r->rightChild == nilLeaf) || r == nilLeaf) {
        if (r == nilLeaf) return;
        if (r->parent == NULL) free(root);
        else if (r == r->parent->leftChild) free(r->parent->leftChild);
        else free(r->parent->rightChild);
    }
    else {
        clear(r->rightChild);
        clear(r->leftChild);
        free(r);
    }
}

Node *search(Node *current, int key) {
    // поиск ноды по значению - обычный поиск как в бинарном дереве поиска (O(log n))
    while (current) {
        if ((current->key) > (key)) {
            current = current->leftChild;
            continue;
        } else if ((current->key) < key) {
            current = current->rightChild;
            continue;
        } else {
            return current;
        }
    }
    return NULL;
}

Node *min(Node *x) {
    Node *tmp_min;
    if (x) {
        tmp_min = x;
        while (tmp_min->leftChild != nilLeaf)
            tmp_min = tmp_min->leftChild;
        return tmp_min;
    }
    return NULL;
}

Node *max(Node *x) {
    Node *tmp_max;
    if (x) {
        tmp_max = x;
        while (tmp_max->rightChild != nilLeaf)
            tmp_max = tmp_max->rightChild;
        return tmp_max;
    }
    return NULL;
}

void print(Node *r, int s) {
    if (r == NULL)
        return;
    if (r->rightChild == NULL && r->leftChild != NULL) {
        for (int i = COUNT; i < s + 2 * COUNT; i++)
            printf(" ");
        printf("NIL\n");
    }
    s += COUNT;
    print(r->rightChild, s);
    printf("\n");
    for (int i = COUNT; i < s; i++)
        printf(" ");
    if (r->leftChild == NULL && r->rightChild == NULL) printf("NIL\n");
    else printf("%d_%s\n", r->key, ColorsShort[r->color]);
    print(r->leftChild, s);
}

void print_keys(Node *x) {
    if (x != nilLeaf) {
        print_keys(x->leftChild);
        printf("%d\t", x->key);
        print_keys(x->rightChild);
    }
}