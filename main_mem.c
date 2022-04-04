#include <stdint.h>
#include <stdlib.h>
#include "main_mem.h"


// Allocate and return a new MainMem
// using 4-byte words
MainMem *createMainMem(uint32_t address_width ) {
    MainMem *mem = (MainMem *) malloc(sizeof(MainMem));
    mem->address_width = address_width;

    mem->memory = (uint32_t *) calloc(mainMemWordCount(mem), sizeof(uint32_t));
    return mem;
}

// Frees MainMem
void freeMainMem(MainMem *mem) {
    if (mem != NULL) {
        if (mem->memory != NULL) {
            free(mem->memory);
        }
        free(mem);
    }
}

// Returns word from MainMem at address.
// Address must be word aligned.

MainMemResult readWord(MainMem *mem, uint32_t address, uint32_t *value) {
    if (address >= (1<<mem->address_width)) {
        return MM_ADDRESS_OUT_OF_RANGE;
    }

    if (address % sizeof(uint32_t) != 0) {
        return MM_ADDRESS_MISALIGNED;
    }

    *value = mem->memory[address/sizeof(uint32_t)];
    return MM_SUCCESS;
}

// Write value to word in MainMem at address.
// Address must be word aligned.
MainMemResult writeWord(MainMem *mem, uint32_t address, uint32_t value) {
    if (address >= (1<<mem->address_width)) {
        return MM_ADDRESS_OUT_OF_RANGE;
    }

    if (address % sizeof(uint32_t) != 0) {
        return MM_ADDRESS_MISALIGNED;
    }

    mem->memory[address/sizeof(uint32_t)] = value;
    return MM_SUCCESS;
}

// Returns number of words in MainMem
// Calculated as 2^address_width / 4
uint32_t mainMemWordCount(MainMem *mem) {
    return (1 << mem->address_width) / sizeof(uint32_t);
}

