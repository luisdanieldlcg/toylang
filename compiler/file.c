#include "file.h"
#include <stdio.h>
#include "types.h"
#include <stdlib.h>

char* file_read_whole(const char* filepath) {
    FILE* f = fopen(filepath, "r");
    fseek(f, 0, SEEK_END);
    u32 len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char* file_buffer = malloc(len * sizeof(char));
    fread(file_buffer, sizeof(char), len, f);
    fclose(f);
    return file_buffer;
}

void file_free_buffer(void* file) {
    if (!file) return;
    free(file);
}
