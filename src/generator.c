#include "generator.h"
#include "entropy.h"
#include <stdio.h>
#include <stdlib.h>

char *generate_password(int length) {
    if (length <= 0) {
        fprintf(stderr, "Invalid length\n");
        return NULL;
    }
    char *password = calloc(length+1, sizeof(char));
    if (password == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    int previous = 0;
    int current = 0;
    for (int i = 0; i < length; i++) {
        srand(get_seed());
        do {
            current = rand() % 4;
        } while (current == previous);
        previous = current;
        switch (current) {
            case 0:
                password[i] = get_lower_case();
                break;
            case 1:
                password[i] = get_upper_case();
                break;
            case 2:
                password[i] = get_digit();
                break;
            case 3:
                password[i] = get_special_char();
                break;
            default:
                break;
        }
    }
    password[length + 1] = '\0';
    return password;
}

char get_lower_case() {
    srand(get_seed());
    return 'a' + (rand() % 26);
}

char get_upper_case() {
    srand(get_seed());
    return 'A' + (rand() % 26);
}

char get_digit() {
    srand(get_seed());
    return '0' + (rand() % 10);
}

char get_special_char() {
    srand(get_seed());
    char special[] = "`~!@#$%^&*()_-=+|\\\"\':;[]{}/?.>,<";
    return special[rand() % (sizeof(special) - 1 )];
}
