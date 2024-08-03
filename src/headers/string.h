#ifndef _STRING_H
#define _STRING_H 1

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// GCC and Clang reserve the right to generate calls to the following
// 4 functions even if they are not directly called.
// Implement them as the C specification mandates.
// DO NOT remove or rename these functions, or stuff will eventually break!
// They CAN be moved to a different .c file.
void *memcpy(void* __restrict, const void* __restrict, size_t);
void *memset(void*, int, size_t);
void *memmove(void*, const void*, size_t);
int memcmp(const void*, const void*, size_t);

// not this one
size_t strlen(const char*);
char* itos(uint64_t);

#ifdef __cplusplus
}
#endif

#endif
