#include <stdio.h>
#include "rbt.h"

int main() {
    createRBT();
    print(root, 0);
    print_keys(root);
    printf("\n");
    return 0;

}
