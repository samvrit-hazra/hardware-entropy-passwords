#ifndef ENTROPY_H
#define ENTROPY_H

int get_seed(void);
int hardware_compatibility(void);
int hardware_entropy(void);
int linux_random(void);
int time_entropy(void);

#endif
