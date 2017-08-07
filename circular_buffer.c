#include "circular_buffer.h"

void create_circular_buffer(circular_buffer_t *circular_buffer, uint8_t *data, size_t size) {
	circular_buffer->data = data;
	circular_buffer->end  = data+size;
	circular_buffer->size = size;
	circular_buffer->head = data;
	circular_buffer->tail = data;
	circular_buffer->is_empty = true;
}

//overflow = false
//non-overflow = true
bool_t enqueue(circular_buffer_t *circular_buffer, uint8_t value) {
	if (!circular_buffer->is_empty && circular_buffer->tail == circular_buffer->head) return false;

	*circular_buffer->tail = value;

	if (circular_buffer->tail+1 > circular_buffer->end) {
		circular_buffer->tail = circular_buffer->data;
	}
	else {
		circular_buffer->tail++;
	}

	if (circular_buffer->is_empty)
		circular_buffer->is_empty = false;

	return true;
}

//empty = false
//non-empty = true
bool_t dequeue(circular_buffer_t *circular_buffer) {
	if (circular_buffer->tail == circular_buffer->head) return false;

	*(circular_buffer->head)++;

	if (circular_buffer->tail == circular_buffer->head)
		circular_buffer->is_empty = true;

	return true;
}

uint8_t get_current(circular_buffer_t* circular_buffer) {
	return *(circular_buffer->tail);
}

void clear(circular_buffer_t *circular_buffer) {
	circular_buffer->head = circular_buffer->data;
	circular_buffer->tail = circular_buffer->data;
	circular_buffer->is_empty = true;
}
