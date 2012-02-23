#ifndef __GNUC__
# error Can be compiled only with GCC.
#endif

#pragma once

#include <stdint.h>

extern size_t slab_pagesize;

struct slab_header {
    struct slab_header *prev, *next;
    uint64_t slots;
    uintptr_t refcount;
    struct slab_header *page;
    uint8_t data[] __attribute__((aligned(sizeof(void *))));
};

struct slab_chain {
    size_t itemsize, itemcount;
    size_t slabsize, pages_per_alloc;
    uint64_t initial_slotmask, empty_slotmask;
    uintptr_t alignment_mask;
    struct slab_header *partial, *empty, *full;
};

void slab_init(struct slab_chain *, size_t);
void *slab_alloc(struct slab_chain *);
void slab_free(struct slab_chain *, void *);
void slab_traverse(struct slab_chain *, void (*)(void *));
void slab_destroy(struct slab_chain *);