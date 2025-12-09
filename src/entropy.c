#include "entropy.h"
#include <stdio.h>
#include <immintrin.h>
#include <cpuid.h>
#include <time.h>

int get_seed() {
    int seed = 0;
    if (hardware_compatibility() != -1) {
        seed = hardware_entropy();
        if (seed != 1) return seed;
    }
    seed = linux_random();
    if (seed != -1) return seed;
    return time_entropy();
}

int hardware_compatibility() {
    unsigned int eax, ebx, ecx, edx;
    if (__get_cpuid(1, &eax, &ebx, &ecx, &edx)) {
        // printf("Hardware supports RDRAND\n");
        return (ecx & (1 << 30)) != 0;
    }
    // printf("Hardware does not support RDRAND\n");
    return -1;
}

int hardware_entropy() {
    unsigned int value;
    int success = _rdrand32_step(&value);
    if (success == 1) {
        return value;
    }
    else {
        return -1;
    }
}

int linux_random() {
    unsigned int value;
    FILE *fptr = fopen("/dev/random", "r");
    if (fptr == NULL) {
        return -1;
    }
    else if (fread(&value, sizeof(value), 1, fptr)) {
        fclose(fptr);
        return value;
    }
    else {
        fclose(fptr);
        return -1;
    }
}

int time_entropy() {
    int value = (int) time(NULL);
    if (value == -1) return -1;
    else return value;
}
