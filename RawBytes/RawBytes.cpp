/* Project:     RawBytes
 * File:        RawBytes.cpp
 * Author:      @s0lst1c3
 * Contact:     gabriel[<<at>>]specterops[<<dot>>]io
 * Description: This header file contains function definitions
 *              for a mutable byte array.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include "RawBytes.h"

struct RawBytes {

	char *data;
	size_t length;
};

// CTOR / DTOR ----------------------------------------------------------------

void RawBytesDestroy(RawBytes *bytes) {

	if (bytes == NULL) {

		fprintf(stderr, "In RawBytesDestroy(): value of bytes was NULL\n");
		exit(1);
	}
	free(bytes->data);
	free(bytes);
	return;
}

RawBytes *RawBytesCreateWithData(char *data, size_t length) {

	RawBytes *bytes;

	if (length <= 0) {

		fprintf(stderr, "In RawBytesCreateWithData(): value of length not > 0\n");
		exit(1);
	}

	if (data == NULL) {

		fprintf(stderr, "In RawBytesCreateWithData(): value of data was NULL\n");
		exit(1);
	}

	bytes = (RawBytes*)malloc(sizeof(RawBytes));
	bytes->data = (char*)malloc((size_t)sizeof(char) * length);
	bytes->length = length;

	memcpy(bytes->data, data, length);

	return bytes;

}

RawBytes *RawBytesCreate(size_t length) {

	RawBytes *bytes;

	if (length <= 0) {

		fprintf(stderr, "In RawBytesCreate(): value of length not > 0\n");
		exit(1);
	}

	bytes = (RawBytes*)malloc(sizeof(RawBytes));
	bytes->data = (char*)malloc((size_t)sizeof(char) * length);
	bytes->length = length;
	return bytes;
}

RawBytes *RawBytesCreateFromUINT32(UINT32 value) {

	RawBytes *bytes;

	bytes = RawBytesCreate((size_t)4);
	memcpy(bytes->data, &value, (size_t)4);
	return bytes;
}

// MODIFERS -------------------------------------------------------------------

RawBytes *RawBytesConcat(RawBytes *bytes_a, RawBytes *bytes_b, char free_old_bytes) {

	RawBytes *new_bytes;
	char *new_data;

	// safety checks
	if (bytes_a == NULL) {

		fprintf(stderr, "In RawBytesConcat(): value of bytes_a was NULL\n");
		exit(1);
	}

	if (bytes_b == NULL) {

		fprintf(stderr, "In RawBytesConcat(): value of bytes_b was NULL\n");
		exit(1);
	}



	// combine the lengths of bytes_a and bytes_b
	new_data = (char*)malloc(bytes_a->length + bytes_b->length);

	memcpy(new_data, bytes_a->data, bytes_a->length);
	memcpy(new_data + bytes_a->length, bytes_b->data, bytes_b->length);

	new_bytes = RawBytesCreateWithData(new_data, bytes_a->length + bytes_b->length);

	free(new_data);

	if (free_old_bytes) {

		free(bytes_a);
		free(bytes_b);
	}

	return new_bytes;
}

// GETTERS --------------------------------------------------------------------

char *RawBytesGetData(RawBytes *bytes) {

	if (bytes == NULL) {

		fprintf(stderr, "In RawBytesGetData(): value of bytes was NULL\n");
		exit(1);
	}
	return bytes->data;
}

size_t RawBytesGetLength(RawBytes *bytes) {

	if (bytes == NULL) {

		fprintf(stderr, "In RawBytesGetLength(): value of bytes was NULL\n");
		exit(1);
	}
	return bytes->length;
}

// AUX ------------------------------------------------------------------------

RawBytes *RawBytesCpy(RawBytes *src) {

	RawBytes *dst;

	if (src == NULL) {

		fprintf(stderr, "In RawBytesCpy(): value of src was NULL\n");
		exit(1);
	}
	dst = RawBytesCreate(src->length);
	memcpy(dst->data, src->data, src->length);
	return dst;
}
