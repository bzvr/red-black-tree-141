#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

int main() {
    Node *tree = createRBT();
    Node *left = createRBT();
    Node *right =  createRBT();
    Node *lr =  createRBT();
    Node *rr =  createRBT();

    /* # Тестирование 1 (т.к пока не реализована вставка)
    left->value = 5;
    right->value = 10;
    left->parent = tree;
    right->parent = tree;
    tree->value = 7;
    tree->leftChild = left;
    tree -> rightChild = right;


    lr->value = 8;
    rr->value = 11;
    right->leftChild = lr;
    right->rightChild = rr;
    lr->parent = right;
    rr->parent = right;*/

    right->value = 10;
    right->parent = tree;
    tree-> value = 5;
    tree -> rightChild = right;
    tree ->color = BLACK;
    right -> color = RED;


    print(tree, 0);
    printf("\n");
    delete(tree);
    print(tree, 0);

    return 0;

}
