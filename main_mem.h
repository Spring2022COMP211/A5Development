#ifndef MAIN_MEM_H
#define MAIN_MEM_H
#include <stdint.h>

typedef struct MainMem {
    uint32_t address_width;
    uint32_t *memory;
} MainMem;

// Enumerated results for functions that return MainMemResult
typedef enum {
    MM_SUCCESS, 
    MM_ADDRESS_MISALIGNED, 
    MM_ADDRESS_OUT_OF_RANGE,
    MM_UNIT_FAIL}
MainMemResult;


// Allocate and return a new MainMem
// using 4-byte words
MainMem *createMainMem(uint32_t address_width );

// Frees MainMem
void freeMainMem(MainMem *mem);

// Returs word from MainMem at address.
// Address must be word aligned.

MainMemResult readWord(MainMem *mem, uint32_t address, uint32_t *value);
MainMemResult writeWord(MainMem *mem, uint32_t address, uint32_t value);

uint32_t mainMemWordCount(MainMem *mem);


#endif
