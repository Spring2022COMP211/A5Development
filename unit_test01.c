#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "main_mem.h"

int main() {

    MainMem *mem = createMainMem(6);

    if (mem == NULL) {
        printf("Failed, mem is null!\n");
        exit(-1);
    }

    uint32_t words_in_memory = mainMemWordCount(mem);

    if (words_in_memory != 16) {
        printf("Failed! expected word count to be 16\n");
        exit(-1);
    }
}
