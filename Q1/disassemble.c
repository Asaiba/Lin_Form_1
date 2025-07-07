#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <ELF binary>\n", argv[0]);
        return 1;
    }

    char command[512];
    snprintf(command, sizeof(command),
             "objdump -d --section=.text %s > disassembled_output.txt", argv[1]);

    int status = system(command);

    if (status == -1) {
        perror("system");
        return 1;
    }

    printf("Disassembly saved to disassembled_output.txt\n");
    return 0;
}
