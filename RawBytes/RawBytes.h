/* Project:     RawBytes
 * File:        RawBytes.h
 * Author:      @s0lst1c3
 * Contact:     gabriel[<<at>>]specterops[<<dot>>]io
 * Description: This header file contains function declarations
 *              for a mutable byte array.
 */

#ifndef __sLibRawBytes__
#define __sLibRawBytes__

#include <Windows.h>

struct RawBytes;
typedef struct RawBytes RawBytes;

RawBytes *RawBytesCreate(size_t length);
RawBytes *RawBytesCreateWithData(char *data, size_t length);
RawBytes *RawBytesCreateFromUINT32(UINT32 value);
void RawBytesDestroy(RawBytes *bytes);

RawBytes *RawBytesConcat(RawBytes *bytes_a, RawBytes *bytes_b, char free_old_bytes);

char *RawBytesGetData(RawBytes *bytes);
size_t RawBytesGetLength(RawBytes *bytes);

RawBytes *RawBytesCpy(RawBytes *src);

#endif