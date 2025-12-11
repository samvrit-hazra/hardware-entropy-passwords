#include "generator.h"
#include "args.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int length = 20;
    int arg_val = args(argc, argv);

    if (arg_val == -1) return 0;
    else if (arg_val != -2) length = arg_val;

    char *password = generate_password(length);

    if (*password != -1) {
            printf("%s\n", password);
            free(password);
        }

    return 0;
}
