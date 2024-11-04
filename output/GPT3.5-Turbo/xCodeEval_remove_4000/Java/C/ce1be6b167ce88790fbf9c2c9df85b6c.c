#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 128 * 1024

typedef struct {
    char* buffer;
    int length;
    int capacity;
} StringBuilder;

void initStringBuilder(StringBuilder* sb) {
    sb->buffer = malloc(MAX_SIZE * sizeof(char));
    sb->length = 0;
    sb->capacity = MAX_SIZE;
}

void append(StringBuilder* sb, const char* str) {
    int i = 0;
    while (str[i] != '\0') {
        sb->buffer[sb->length++] = str[i++];
    }
}

void appendFormat(StringBuilder* sb, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);

    char* buffer = malloc((len + 1) * sizeof(char));
    va_start(args, format);
    vsnprintf(buffer, len + 1, format, args);
    va_end(args);

    append(sb, buffer);
    free(buffer);
}

void appendLine(StringBuilder* sb, const char* str) {
    append(sb, str);
    append(sb, "\n");
}

void closeStringBuilder(StringBuilder* sb) {
    sb->buffer[sb->length] = '\0';
    printf("%s", sb->buffer);
    free(sb->buffer);
}

typedef struct {
    FILE* file;
    char* buffer;
    int ptr;
    int buflen;
} FastScanner;

void initFastScanner(FastScanner* fs) {
    fs->file = stdin;
    fs->buffer = malloc(MAX_SIZE * sizeof(char));
    fs->ptr = 0;
    fs->buflen = 0;
}

void initFastScannerFromFile(FastScanner* fs, const char* filename) {
    fs->file = fopen(filename, "r");
    fs->buffer = malloc(MAX_SIZE * sizeof(char));
    fs->ptr = 0;
    fs->buflen = 0;
}

void closeFastScanner(FastScanner* fs) {
    if (fs->file != stdin) {
        fclose(fs->file);
    }
    free(fs->buffer);
}

int hasNext(FastScanner* fs) {
    while (fs->ptr >= fs->buflen || fs->buffer[fs->ptr] == '\0') {
        fs->ptr = 0;
        fs->buflen = fread(fs->buffer, sizeof(char), MAX_SIZE, fs->file);
        if (fs->buflen == 0) {
            return 0;
        }
    }
    return 1;
}

char* next(FastScanner* fs) {
    if (!hasNext(fs)) {
        return NULL;
    }

    StringBuilder sb;
    initStringBuilder(&sb);

    while (fs->ptr < fs->buflen && fs->buffer[fs->ptr] != '\0' && fs->buffer[fs->ptr] != ' ' && fs->buffer[fs->ptr] != '\n') {
        append(&sb, &fs->buffer[fs->ptr++]);
    }

    return sb.buffer;
}

long longNext(FastScanner* fs) {
    char* str = next(fs);
    if (str == NULL) {
        return 0;
    }
    return atol(str);
}

int intNext(FastScanner* fs) {
    long num = longNext(fs);
    if (num < INT_MIN || num > INT_MAX) {
        return 0;
    }
    return (int) num;
}

long* id23(FastScanner* fs, int n) {
    long* arr = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        arr[i] = longNext(fs);
    }
    return arr;
}

int* id12(FastScanner* fs, int n) {
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = intNext(fs);
    }
    return arr;
}

double* id21(FastScanner* fs, int n) {
    double* arr = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        arr[i] = doubleNext(fs);
    }
    return arr;
}

typedef struct {
    StringBuilder out;
    FastScanner in;
} E;

void solver(E* e) {
    long n = intNext(&e->in);
    long* ar = id23(&e->in, 3);
    long* br = id23(&e->in, 3);
    long mxWins = 0;
    long id19 = 0;
    long draws = 0;
    for (int i = 0; i < 3; i++) {
        mxWins += min(ar[i], br[(i + 1) % 3]);
        long mxLose = min(br[i], ar[(i + 1) % 3]);
        long mxDraw = min(br[i], ar[i]);
        id19 += min(br[i], mxLose + mxDraw);
    }
    appendFormat(&e->out, "%ld %ld\n", n - id19, mxWins);
}

int main() {
    E e;
    initStringBuilder(&e.out);
    initFastScanner(&e.in);
    solver(&e);
    closeStringBuilder(&e.out);
    closeFastScanner(&e.in);
    return 0;
}
