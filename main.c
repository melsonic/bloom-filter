#include "murmurhash.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define LEN(arr) (sizeof(arr) / sizeof(arr[0]))
#define K 3
#define bytes_len 16

typedef struct bloom_filter_struct {
    int *store;
} bloom_filter;

bloom_filter new_bloom_filter(int size) {
    bloom_filter bloom;
    bloom.store = calloc(size, sizeof(int));
    return bloom;
}

int *indexes(const char **str) {
    int *result = calloc(K, sizeof(int));
    int prev_seed = 0;
    for (int k = 0; k < K; k++) {
        result[k] = murmurhash3(*str, bytes_len, prev_seed) % (bytes_len * 8);
        prev_seed = result[k];
    }
    return result;
}

void bloom_filter_add(bloom_filter *bloom, const char **item) {
    int *ixs = indexes(item);
    for (int i = 0; i < K; i++) {
        int byte_index = (*(ixs + i)) / 8;
        int bit_index = (*(ixs + i)) % 8;
        bloom->store[byte_index] |= (1 << bit_index);
    }
    free(ixs);
}

bool bloom_filter_check(bloom_filter *bloom, const char **item) {
    int *ixs = indexes(item);
    for (int i = 0; i < K; i++) {
        int byte_index = (*(ixs + i)) / 8;
        int bit_index = (*(ixs + i)) % 8;
        if ((bloom->store[byte_index] & (1 << bit_index)) == 0) return false;
    }
    return true;
}

int main() {
    bloom_filter bloom = new_bloom_filter(bytes_len);

    const char *seed[10] = {"xpt", "mza", "rqo", "jiv", "bkw",
                            "tlu", "hcg", "dyf", "sen", "wob"};

    printf("Seed Keys: [");
    for (size_t i = 0; i < LEN(seed); i++) {
        printf(" %s ", seed[i]);
        bloom_filter_add(&bloom, &seed[i]);
    }
    printf("]\n==============================================================\n");

    const char *test[] = {"jkl", "tlu", "def"};
    for (size_t i = 0; i < LEN(test); i++) {
        printf("key \"%s\" present => %s\n", test[i],
               bloom_filter_check(&bloom, &test[i]) ? "true" : "false");
    }
    return 0;
}
