#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"
#define COUNT 10
Node *root;
Node *nilLeaf;

Node *createRBT(void){
    // выделение памяти под черный лист (пустое дерево)
    int k;
    nilLeaf = malloc(sizeof(Node));
    nilLeaf->color = BLACK;
    nilLeaf->leftChild = NULL;
    nilLeaf->rightChild = NULL;
    if (scanf("%d", &k)==1) {
        root = malloc(sizeof(Node));
        root->color = BLACK;
        root->leftChild = nilLeaf;
        root->rightChild = nilLeaf;
        root->key = k;
        root->parent = NULL;
    }
    else return NULL;
    while (scanf("%d", &k)==1) insert(k);
    return root;
}

void leftR(Node *r) {
    if (r == NULL) {exit(1);}
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

void insert(int value){
	Node *ptr, *current;
	if (!root){
		root = malloc(sizeof(Node));
        root->color = BLACK;
        root->key = value;
        root->leftChild = nilLeaf;
        root->leftChild = nilLeaf;
        root->parent = NULL;
		return;
	}
	current = root;
	while (!(current->leftChild == nilLeaf && current->rightChild == nilLeaf)){
		if (current->key > value && current->leftChild != nilLeaf) current = current->leftChild;
		else{
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
void insertFixup(Node *z){
	if (z->parent == NULL) 
		z->color = BLACK;
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
		else uncle = z->parent->parent->rightChild;
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
		leftR(z->parent);
		z = z->leftChild;
	}
	else{
		if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->rightChild)){
			rightR(z->parent);
			z = z->rightChild;
		}
	}
	insert_case5(z);
}
void insert_case5(Node *z){
	z->parent->color ^= 1;
	z->parent->parent->color ^= 1;
	if ((z->parent->leftChild == z) && (z->parent == z->parent->parent->leftChild))
		rightR(z->parent->parent);
	else
		leftR(z->parent->parent);
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

void print(Node *r, int s){
    if (r == NULL)
        return;
    if (r->rightChild == NULL && r->leftChild != NULL){
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
    else printf("%d_%s\n", r->key, Colors[r->color]);
    print(r->leftChild, s);
}

void print_keys(Node *x){
    if(x != nilLeaf){
        print_keys(x->leftChild);
        printf("%d\t", x->key);
        print_keys(x->rightChild);
    }
}