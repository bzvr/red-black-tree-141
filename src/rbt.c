#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#define COUNT 10
Node *root;
Node *nilLeaf;

Node *createRBT(void){
    // выделение памяти под черный лист (пустое дерево)
    Node* tmp = malloc(sizeof(Node));
    tmp->color = BLACK;
    tmp->leftChild = NULL;
    tmp->rightChild = NULL;
    tmp->parent = NULL;
    return tmp;
}

void leftR(Node **r) {
    if (*r == NULL) {exit(1);}
    Node *d = (*r)->rightChild;
    if (d == NULL) exit(1);

    if ((d->parent = (*r)->parent) != NULL) {
        if ((*r)->parent->rightChild == *r)
            (*r)->parent->rightChild = d;
        else
            (*r)->parent->leftChild = d;
    }
    (*r)->rightChild = d->leftChild;
    if (d->leftChild != NULL) d->leftChild->parent = *r;
    d->leftChild = *r;
    (*r)->parent = d;
    *r = d;
}

void rightR(Node **r) {
    if (*r == NULL) exit(1);
    Node *d = (*r)->leftChild;
    if (d == NULL) exit(1);
    if ((d->parent = (*r)->parent) != NULL) {
        if ((*r)->parent->rightChild == *r)
            (*r)->parent->rightChild = d;
        else
            (*r)->parent->leftChild = d;
    }
    (*r)->leftChild = d->rightChild;
    if (d->rightChild != NULL) d->rightChild->parent = *r;
    d->rightChild = *r;
    (*r)->parent = d;
    *r = d;
}

void insert(int value){
    // обычная вставка как в бинарное дерево поиска - новая нода всегда красная с 2 черынми пустыми листьями (O(log n))
    // c'mon do something
}
void insertFixup(Node *z) {
    // после вставки восстанавливаем свойства кч-дерева (проверяем от вставленной до корня (O(log n))
    // c'mon do something
}
void replace(Node **a, Node *b){
    if((*a)->parent == NULL){
        *a = b;
    }
    if ((*a)->parent->leftChild == *a) (*a)->parent->leftChild = b;
    else (*a)->parent->rightChild = b;
    if (b != NULL) b ->parent = (*a)->parent;
}
void delete(Node *z){
    Node *y, *x;
    int yOriginalColor;

    y = z;
    yOriginalColor = y->color;

    if(z->leftChild == NULL){
        x = z->rightChild;
        replace(&z, z->rightChild);
    }
    else if(z->rightChild == NULL){
        x = z->leftChild;
        replace(&z, z->leftChild);
    }
    else {
        y = min(z->rightChild);
        yOriginalColor = y->color;

        x = y->rightChild;

        if(y->parent == z){
            x->parent = y;
        }
        else{
            replace(&y, y->rightChild);
            y->rightChild = z->rightChild;
            y->rightChild->parent = y;
        }

        replace(&z, y);
        y->leftChild = z->leftChild;
        y->leftChild->parent = y;
        y->color = z->color;
    }
    if(yOriginalColor == BLACK){
        deleteFixup(x);
    }
}

void deleteFixup(Node *x){
    // восстановление свойств кч-дерева после удаления (O(log n))
    // c'mon do something
}

void clear(Node *r) {
    if (r == NULL) return;
    clear(r->rightChild);
    clear(r->leftChild);
    free(r);
}

Node *search(int value){
    // поиск ноды по значению - обычный поиск как в бинарном дереве поиска (O(log n))
    while (root) {
        if ((root->value) > (value)) {
            root = root->leftChild;
            continue;
        }
        else if ((root->value) < value) {
        root = root->rightChild;
        continue;
        }
        else {
            return root;
        }
    }
    return NULL;
}
Node *min(Node *x){
    // поиск минимума
    // c'mon do something
    return NULL;
}
Node *max(Node *x){
    // поиск максимума
    // c'mon do something
    return NULL;
}

void print(Node *r, int s){
    if (r == NULL)
        return;
    s += COUNT;
    print(r->rightChild, s);
    printf("\n");
    for (int i = COUNT; i < s; i++)
        printf(" ");
    printf("%d_%d\n", r->value, r->color);
    print(r->leftChild, s);
}