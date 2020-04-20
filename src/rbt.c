#include <stdio.h>
#include "rbt.h"

Node *root;
Node *nilLeaf;

Node *createRBT(void){
    // выделение памяти под черный лист (пустое дерево)
    // c'mon do something
    return NULL;
}

void leftR(Node **r)
{
    if (*r == NULL) exit(1);
    Node* d=(*r)->rightChild;
    if (d == NULL) exit(1);
    if ((d->parent = (*r)->parent) != NULL)
    {
        if((*r)->parent->rightChild == *r)  
            (*r)->parent->rightChild = d;
        else
            (*r)->parent->rightChild = d;
    }
    (*r)->rightChild = d->leftChild;
    d->leftChild->parent = d->parent;
    d->leftChild = *r;
    (*r)->parent = d;
    *r=d;
}
void rightR(Node **r)
{
    if (*r == NULL) exit(1);
    Node* d=(*r)->leftChild;
    if (d == NULL) exit(1);
    if ((d->parent = (*r)->parent) != NULL)
    {
        if((*r)->parent->rightChild == *r)  
            (*r)->parent->rightChild = d;
        else
            (*r)->parent->rightChild = d;
    }
    (*r)->leftChild = d->rightChild;
    d->rightChild->parent = d->parent;
    d->rightChild = *r;
    (*r)->parent = d;
    *r=d;
}
void rightR(Node *x){
    // правый поворот O(1)
    // c'mon do something
}

void insert(int value){
    // обычная вставка как в бинарное дерево поиска - новая нода всегда красная с 2 черынми пустыми листьями (O(log n))
    // c'mon do something
}
void insertFixup(Node *z) {
    // после вставки восстанавливаем свойства кч-дерева (проверяем от вставленной до корня (O(log n))
    // c'mon do something
}
void replace(Node *a, Node *b){
    // свап двух нод
    // c'mon do something
}
void delete(Node *z){
    // удаление нужной вершины (O(log n))
    // c'mon do something
}

void deleteFixup(Node *x){
    // восстановление свойств кч-дерева после удаления (O(log n))
    // c'mon do something
}

void clear(Node *x){
    // очистка памяти от всех нод
    // c'mon do something
}

Node *search(int value){
    // поиск ноды по значению - обычный поиск как в бинарном дереве поиска (O(log n))
    // c'mon do something
    return NULL;
}

void clear(Node *r)
{
    if (r == NULL) return;
    clear(r->rightChild);
    clear(r->leftChild);
    free(r);
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
