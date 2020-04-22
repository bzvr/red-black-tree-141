#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Node *root;
Node *nilLeaf;

Node *createRBT(void){
    // выделение памяти под черный лист (пустое дерево)
    int k;
    nilLeaf = malloc(sizeof(Node));
    nilLeaf->color = BLACK;
    nilLeaf->leftChild = NULL;
    nilLeaf->rightChild = NULL;
    if (scanf("%d", k)==1) {
        Node* tmp = malloc(sizeof(Node));
        tmp->color = BLACK;
        tmp->leftChild = nilLeaf;
        tmp->rightChild = nilLeaf;
        tmp->key = k;
        tmp->parent = NULL;
    }
    else return NULL;
    while (scanf("%d", k)==1) insert(&tmp, k);
    return tmp;
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

void insert(int key){
    // обычная вставка как в бинарное дерево поиска - новая нода всегда красная с 2 черынми пустыми листьями (O(log n))
    // c'mon do something
}
void insertFixup(Node *z) {
    // после вставки восстанавливаем свойства кч-дерева (проверяем от вставленной до корня (O(log n))
    // c'mon do something
}
void replace(Node *a, Node *b){
    // свап двух нод
    Node* parentA;
    Node* parentB;
    parentA = a->parent;
    parentB = b->parent;
    if (parentA->leftChild == a) parentA->leftChild = b;
    else parentA->rightChild = b;
    if (parentB->leftChild == b) parentB->leftChild = a;
    else parentB->rightChild = a;
    a->parent = parentB;
    b->parent = parentA;
}
void delete(Node *z){
    // удаление нужной вершины (O(log n))
    // c'mon do something
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

Node *search(int key){
    // поиск ноды по значению - обычный поиск как в бинарном дереве поиска (O(log n))
    while (root) {
        if ((root->key) > (key)) {
            root = root->leftChild;
            continue;
        }
        else if ((root->key) < key) {
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
    Node *tmp_min;
    if (x){
		tmp_min = x;
		while (tmp_min -> leftChild)
			tmp_min = tmp_min -> leftChild;
		return tmp_min;
	}
    return NULL;
}

Node *max(Node *x){
    Node *tmp_max;
    if (x){
		tmp_max = x;
		while (tmp_max -> leftChild)
			tmp_max = tmp_max -> leftChild;
		return tmp_max;
	}
    return NULL;
}
