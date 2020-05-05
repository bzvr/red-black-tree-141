#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rbt.h"


void help(){
    printf("All commands:\n");
    printf("\tcreate\t\tCreate a red-black tree from keys in stdin\n");
    printf("\tinsert <key>\tInsert a new integer key to the tree\n");
    printf("\tsearch <key>\tSearch for the key in the tree\n");
    printf("\tdelete <key>\tDelete the key if it exists\n");
    printf("\tmax\t\tReturn node with greatest key\n");
    printf("\tmin\t\tReturn node with least key\n");
    printf("\tclear\t\tDelete all nodes\n");
    printf("\tprint\t\tPrint the tree\n");
    printf("\texit\t\tAuto-clear the tree and exit\n");
}

int main() {
    Node* n;
    char line[100];
    int k;
    char * fg;
    printf("Type 'help' to see all commands\n");
    printf(">");
    fg = fgets(line, sizeof(line), stdin);
    char * cmd = strtok(line, " ");

    while (strcmp(cmd, "exit\n") != 0 && fg) {
        if (strcmp(cmd, "create\n") == 0) {
            if (root != NULL) {
                printf("The tree already exist. Please, clear it before creating a new tree.\n");
            }
            else {
                printf("Input the keys separated by spaces (0 - stop input): ");
                n = createRBT();
                if (n) printf("The tree was created successfully!\n");
            }
        } else if (strcmp(cmd, "insert") == 0) {
            cmd = strtok(NULL, " ");
            k = atoi(cmd);
            if (k == 0) printf("Bad command. Use 'help' to check all valid commands.\n");
            else {
                printf("Insertion %d in the tree...\n", k);
                insert(k);
                printf("Insertion completed!\n");
            }

        } else if (strcmp(cmd, "search") == 0) {
            cmd = strtok(NULL, " ");
            k = atoi(cmd);
            printf("Searching %d in the tree...\n", k);
            n = search(root, k);
            if (n){
                printf("The key (%d) was found! Its color is %s.\n", k, Colors[n->color]);
            } else printf("The key (%d) was not found!\n", k);


        } else if (strcmp(cmd, "delete") == 0) {
            cmd = strtok(NULL, " ");
            k = atoi(cmd);
            if (k == 0) printf("Bad command. Use 'help' to check all valid commands.\n");
            else {
                printf("Deleting %d from the tree...\n", k);
                n = search(root, k);
                if (n) {
                    delete(n);
                    printf("Deletion completed!\n");
                } else printf("The key (%d) was not found! Deletion was cancelled.\n", k);
            }

        } else if (strcmp(cmd, "clear\n") == 0) {
            if (root == NULL) printf("The tree is already empty.\n");
            else {
                clear(root);
                root = NULL;
                free(nilLeaf);
            }
        } else if (strcmp(cmd, "print\n") == 0) {
            if (root == NULL) printf("The tree is empty! Create it before. \n");
            else {
                print(root, 0);
                printf("\n");
            }
        } else if (strcmp(cmd, "max\n") == 0) {
            if (root == NULL) printf("The tree is empty! Create it before. \n");
            else printf("Max key: %d\n", max(root)->key);
        } else if (strcmp(cmd, "min\n") == 0) {
            if (root == NULL) printf("The tree is empty! Create it before. \n");
            else printf("Min key: %d\n", min(root)->key);
        } else if (strcmp(cmd, "help\n") == 0) {
            help();
        }
        else if ((strcmp(cmd, "\n") != 0)){
            printf("Bad command. Use 'help' to check all valid commands.\n");
        }
        printf(">");
        fg = fgets(line, sizeof(line), stdin);
        cmd = strtok(line, " ");
    }
    if (root != NULL)  clear(root);
    return 0;
}
