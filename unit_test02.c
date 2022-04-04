#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "main_mem.h"

int main() {

    MainMem *mem = createMainMem(6);

    if (mem == NULL) {
        printf("Failed! mem is null\n");
        exit(-1);
    }

    // All words in main mem should be
    // initialized to 0
    
    for (uint32_t i=0; i<mainMemWordCount(mem); i++) {
        uint32_t word_address = i * sizeof(uint32_t);
        uint32_t value = 1;

        if (readWord(mem, word_address, &value) != MM_SUCCESS) {
            printf("readWord not successful\n");
            exit(-1);
        }

        if (value != 0) {
            printf("Expected word value at address %x to be zero.\n", word_address);
            exit(-1);
        }
    }

    // Write new values into memory.
    uint32_t test_data[16] = {
        0x30d6874b, 0x531b2d40, 0xd423d09a, 0x620cc950,
        0x0787748c, 0xa6029cad, 0xeee5fa16, 0x586eb0ac,
        0xb025b8a3, 0x99796a16, 0xc4bdf050, 0x1486e8da,
        0x70595e3a, 0x4dcb6476, 0x65d4feee, 0xe36e6a42};

    for (uint32_t i=0; i<16; i++) {
        uint32_t value_check = 0;

        if (writeWord(mem, i*4, test_data[i]) != MM_SUCCESS) {
            printf("writeWord not successful\n");
            exit(-1);
        }

        if (readWord(mem, i*4, &value_check) != MM_SUCCESS) {
            printf("readWord not successful\n");
            exit(-1);
        }

        if (value_check != test_data[i]) {
            printf("Write word at address %x with value %x failed.\n",
                    i*4, test_data[i]);
            exit(-1);
        }
    }

    // Try to read / write at misaligned address.
   
    uint32_t value; 
    if (readWord(mem, 1, &value) != MM_ADDRESS_MISALIGNED) {
        printf("Attempt to read misaligned addresss should have returned MM_ADDRESS_MISALIGNED\n");
        exit(-1);
    }

    if (writeWord(mem, 1, value) != MM_ADDRESS_MISALIGNED) {
        printf("Attempt to write misaligned addresss should have returned MM_ADDRESS_MISALIGNED\n");
        exit(-1);
    }

    // Try to read / write address out of range.
    if (readWord(mem, 17*4, &value) != MM_ADDRESS_OUT_OF_RANGE) {
        printf("Attempt to read out of range address should have returned MM_ADDRESS_OUT_OF_RANGE\n");
        exit(-1);
    }

    if (writeWord(mem, 17*4, value) != MM_ADDRESS_OUT_OF_RANGE) {
        printf("Attempt to write out of range address should have returned MM_ADDRESS_OUT_OF_RANGE\n");
        exit(-1);
    }

    printf("Test passed\n");
}
