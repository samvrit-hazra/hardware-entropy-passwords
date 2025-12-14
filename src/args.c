#include "args.h"
#include <stdio.h>
#include <stdlib.h>

int args(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        int val = atoi(argv[i]);
        if (val <= 100 && val > 0) {
            return (int) val;
        }
        else {
            printf("Password length must be between 0 and 100\n");
            return -1;
        }
    }
    return -2;
}