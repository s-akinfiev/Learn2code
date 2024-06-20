#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door *doors);
void sort(struct door *a);
void closealldoors(struct door *a);

int main(void) {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    closealldoors(doors);

    for (int i = 0; i < DOORS_COUNT; i++) printf("%d, %d\n", doors[i].id, doors[i].status);

    return 0;
}

void sort(struct door *a) {
    int tmp;

    for (int i = 0; i < DOORS_COUNT; i++) {
        int swap_happened = 0;
        for (int j = 0; j < DOORS_COUNT - i - 1; j++) {
            if (a[j].id > a[j + 1].id) {
                tmp = a[j].id;
                a[j].id = a[j + 1].id;
                a[j + 1].id = tmp;
                swap_happened = 1;
            }
        }
        if (!swap_happened) break;
    }
}

void closealldoors(struct door *a) {
    for (int i = 0; i < DOORS_COUNT; i++) a[i].status = 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door *doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
