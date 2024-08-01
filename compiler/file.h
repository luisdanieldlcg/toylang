#ifndef FILE_H
#define FILE_H

char* file_read_whole(const char* path);
void file_free_buffer(void* file);

#endif
