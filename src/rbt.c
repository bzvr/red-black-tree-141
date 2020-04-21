#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Node *root;
Node *nilLeaf;

Node *createRBT(void) {
    // выделение памяти под черный лист (пустое дерево)
    // c'mon do something
    return NULL;
}

void leftR(Node **r) {
    if (*r == NULL) exit(1);
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

void insert(int value) {
    // обычная вставка как в бинарное дерево поиска - новая нода всегда красная с 2 черынми пустыми листьями (O(log n))
    // c'mon do something
}

void insertFixup(Node *z) {
    // после вставки восстанавливаем свойства кч-дерева (проверяем от вставленной до корня (O(log n))
    // c'mon do something
}

void replace(Node *a, Node *b) {
    // свап двух нод
    // c'mon do something
}

void delete(Node *z) {
    // удаление нужной вершины (O(log n))
    // c'mon do something
}

void deleteFixup(Node *x) {
    // восстановление свойств кч-дерева после удаления (O(log n))
    // c'mon do something
}

Node *search(int value) {
    // поиск ноды по значению - обычный поиск как в бинарном дереве поиска (O(log n))
    // c'mon do something
    return NULL;
}

void clear(Node *r) {
    if (r == NULL) return;
    clear(r->rightChild);
    clear(r->leftChild);
    free(r);
}

Node *min(Node *x) {
    // поиск минимума
    // c'mon do something
    return NULL;
}

Node *max(Node *x) {
    // поиск максимума
    // c'mon do something
    return NULL;
}
