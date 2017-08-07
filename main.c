#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include "circular_buffer.h"

#define BUFFER_SIZE 80
#define DELAY 100

int main() {
    uint8_t buffer[BUFFER_SIZE];
    int array1[BUFFER_SIZE/4];
    circular_buffer_t circular_buffer;

    srand(time(NULL));
    create_circular_buffer(&circular_buffer, buffer, BUFFER_SIZE);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (!enqueue(&circular_buffer, rand() % 256)) break;
        usleep(DELAY * 1000);
#ifdef DEBUG
        printf("%.f%%\n", (i+1.0)/BUFFER_SIZE * 100);
#endif //DEBUG
    }

    memcpy(array1, (int*)circular_buffer.data, sizeof(array1));

#ifdef DEBUG
    for (int i = 0; i < BUFFER_SIZE/4; i++) {
        printf("%x, ", array1[i]);
    }
    printf("\n");
#endif //DEBUG

    return 0;
}
