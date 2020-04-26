/* Project:     RawBytes
 * File:        Main.cpp
 * Author:      @s0lst1c3
 * Contact:     gabriel[<<at>>]specterops[<<dot>>]io
 * Description: This is a driver file for testing code.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RawBytes.h"

int main(int argc, char **argv) {

	RawBytes *bytes_a;
	RawBytes *bytes_b;
	RawBytes *bytes_c;

	if (argc != 3) {

		fprintf(stderr, "Usage: ./RawBytes.exe \"str_a\" \"str_b\"\n");
		exit(1);
	}

	printf("str_a:     %s\n", argv[1]);
	printf("str_a_len: %d\n", strlen(argv[1]));
	printf("str_b:     %s\n", argv[2]);
	printf("str_b_len: %d\n", strlen(argv[2]));

	bytes_a = RawBytesCreateWithData(argv[1], strlen(argv[1]));
	bytes_b = RawBytesCreateWithData(argv[2], strlen(argv[2])+1);

	bytes_c = RawBytesConcat(bytes_a, bytes_b, 0);

	printf("bytes_c_data: %s\n", RawBytesGetData(bytes_c));
	printf("bytes_c_len:  %d\n", RawBytesGetLength(bytes_c));

	RawBytesDestroy(bytes_a);
	RawBytesDestroy(bytes_b);

	return 0;
}