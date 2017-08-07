#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum {
	false,
	true
} bool_t;

typedef struct {
	uint8_t *data;
	uint8_t *end;
	size_t size;
	uint8_t *head;
	uint8_t *tail;
	bool_t is_empty;
} circular_buffer_t;

void create_circular_buffer(circular_buffer_t* circular_buffer, uint8_t *data, size_t size);
bool_t enqueue(circular_buffer_t* circular_buffer, uint8_t value);
bool_t dequeue(circular_buffer_t* circular_buffer);
uint8_t get_current(circular_buffer_t* circular_buffer);
void clear(circular_buffer_t* circular_buffer);

#endif //CIRCULAR_BUFFER_H
