#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "../io.h"

#define IO_READ_CHUNK_SIZE 2097152

File io_file_read(const char *path) {
    File file = {.is_valid =false};

    FILE *fp = fopen(path, "rb");
    if (!fp || ferror(fp)) {
        exit(1);
    }

    char *data = NULL;
    char *tmp;
    size_t used = 0;
    size_t size = 0;
    size_t n;

    while (true) {
        if (used + IO_READ_CHUNK_SIZE + 1 > size) {
            size = used + IO_READ_CHUNK_SIZE + 1;

            if (size <= used) {
                free(data);
                exit(1);
            }

            tmp = realloc(data, size);
            if (!tmp) {
                free(data);
                exit(1);
            }
            data = tmp;
        }

        n = fread(data + used, 1, IO_READ_CHUNK_SIZE, fp);
        if (n == 0) {
            break;
        }

        used += n;
    }

    if (ferror(fp)) {
        free(data);
        exit(1);
    }

    tmp = realloc(data, used + 1);
    if (!tmp) {
        free(data);
        exit(1);
    }

    data = tmp;
    data[used] = 0;

    file.data = data;
    file.len = used;
    file.is_valid = true;

    return file;
}

int io_file_write(void *buffer, size_t size, const char *path) {
    FILE *fp = fopen(path, "wb");
    if (!fp || ferror(fp)) {
        exit(1);
    }

    size_t chunks_written = fwrite(buffer, size, 1, fp);

    fclose(fp);

    if (chunks_written != 1) {
        exit(1);
    }
    return 0;
}