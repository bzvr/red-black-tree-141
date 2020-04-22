#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

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
#include <stdio.h>

void insert(Node **r, int value){
	Node *ptr, *current;
	if (!*r){
		ptr = malloc(sizeof(Node));
		ptr->key = value;
		ptr->leftChild = nilLeaf;
		ptr->leftChild = nilLeaf;
		ptr->parent = NULL:
		*r = ptr;
		return
	}
	current = *r;
	while (!(current->leftChild == nilLeaf && current->rightChild == nilLeaf)){
		if (current->key > value && current->leftChild) current = current->leftChild;
		else{
			if (current->key <= value && current->rightChild) current = current->rightChild;
			else break;
		}
	}
	ptr = malloc(sizeof(Node));
	ptr->key = value;
	ptr->leftChild = nilLeaf;
	ptr->leftChild = nilLeaf;
	ptr->parent = current:
	if (value < current->key) current->leftChild = ptr;
	else current->rightChild = ptr;
	insertFixup(ptr);
}
void insertFixup(Node *z){
	if (z->parent == NULL) 
		z.color = BLACK;
	else 
		insert_case2(z);
}
void insert_case2(Node *z){
	if (z->parent->color == BLACK)
		return;
	else 
		insert_case3(z);
}
void insert_case3(Node *z){
	Node *uncle;
	if (z->parent->parent){
		if (z->parent->parent->leftChild != z->parent) uncle = z->parent->parent->leftChild;
		else z->parent->parent->rightChild;
		if (uncle->color == RED){
			uncle->color = BLACK;
			uncle->parent->color ^= 1;
			z->parent->color ^= 1;
			insertFixup(uncle->parent);
		}
		else 
			insert_case4(z);
		}
}
void insert_case4(Node *z){
	if ((z->parent->rightChild == z) && (z->parent == z->parent->parent->leftChild)){
		leftR(&(z->parent));
		z = z->left;
	}
	else{
		if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->rightChild)){
			rightR(&(z->parent));
			z = z->right;
		}
	}
	insert_case5(z);
}
void insert_case5(Node *z){
	z->parent->color ^= 1;
	z->parent->parent->color ^= 1;
	if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->leftChild)){
		rightR(&(z->parent->parent));
	else
		leftR(&(z->parent->parent));
	}
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
