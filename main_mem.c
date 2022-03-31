#include <stdint.h>
#include <stdlib.h>
#include "main_mem.h"


// Allocate and return a new MainMem
// using 4-byte words
MainMem *createMainMem(uint32_t address_width ) {
    MainMem *mem = (MainMem *) malloc(sizeof(MainMem));
    mem->address_width = address_width;
    return mem;
}

// Frees MainMem
void freeMainMem(MainMem *mem) {
    if (mem != NULL) {
        free(mem);
    }
}

// Returs word from MainMem at address.
// Address must be word aligned.

MainMemResult readWord(MainMem *mem, uint32_t address, uint32_t *value) {
    return MM_UNIT_FAIL;
}

MainMemResult writeWord(MainMem *mem, uint32_t address, uint32_t value) {
    return MM_UNIT_FAIL;
}

uint32_t mainMemWordCount(MainMem *mem) {
    return (1 << mem->address_width) / sizeof(uint32_t);
}

