#ifndef MURMURHASH_H
#define MURMURHASH_H

#include <stdint.h>
#include <stddef.h>

// Computes MurmurHash3 (32-bit, x86)
// key  : pointer to input data
// len  : length of data in bytes
// seed : seed value (for reproducibility / variation)
// returns: 32-bit hash value
uint32_t murmurhash3(const void *key, size_t len, uint32_t seed);

#endif // MURMURHASH3_H
