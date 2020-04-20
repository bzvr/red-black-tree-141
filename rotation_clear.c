#include <stdlib.h>
#include "./src/rbt.h"
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
void clear(Node *r)
{
	if (r == NULL) return;
	clear(r->rightChild);
	clear(r->leftChild);
	free(r);
}
