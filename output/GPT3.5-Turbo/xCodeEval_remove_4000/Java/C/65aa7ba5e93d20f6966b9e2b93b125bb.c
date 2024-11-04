#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

typedef struct {
    char* data;
    int length;
} String;

typedef struct {
    FILE* file;
    char* buffer;
    int bufferIndex;
    int bufferSize;
} FastReader;

void initFastReader(FastReader* reader) {
    reader->file = stdin;
    reader->buffer = malloc(4096 * sizeof(char));
    reader->bufferIndex = 0;
    reader->bufferSize = 0;
}

char readChar(FastReader* reader) {
    if (reader->bufferIndex >= reader->bufferSize) {
        reader->bufferSize = fread(reader->buffer, sizeof(char), 4096, reader->file);
        reader->bufferIndex = 0;
    }
    return reader->buffer[reader->bufferIndex++];
}

String readString(FastReader* reader) {
    String str;
    str.data = malloc(16 * sizeof(char));
    str.length = 0;
    char c = readChar(reader);
    while (c != ' ' && c != '\n') {
        str.data[str.length++] = c;
        if (str.length % 16 == 0) {
            str.data = realloc(str.data, (str.length + 16) * sizeof(char));
        }
        c = readChar(reader);
    }
    str.data[str.length] = '\0';
    return str;
}

int readInt(FastReader* reader) {
    int num = 0;
    int sign = 1;
    char c = readChar(reader);
    if (c == '-') {
        sign = -1;
        c = readChar(reader);
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = readChar(reader);
    }
    return num * sign;
}

long long readLong(FastReader* reader) {
    long long num = 0;
    int sign = 1;
    char c = readChar(reader);
    if (c == '-') {
        sign = -1;
        c = readChar(reader);
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = readChar(reader);
    }
    return num * sign;
}

void printString(char* str) {
    printf("%s", str);
}

void printInt(int num) {
    printf("%d", num);
}

void printLong(long long num) {
    printf("%lld", num);
}

void flush() {
    fflush(stdout);
}

void closeFastReader(FastReader* reader) {
    free(reader->buffer);
}

void solve() {
    FastReader reader;
    initFastReader(&reader);

    String s = readString(&reader);
    String t = readString(&reader);
    int n = s.length;
    int m = t.length;
    int* pre = (int*)malloc(m * sizeof(int));
    int* suf = (int*)malloc(m * sizeof(int));
    int i, j;
    for (i = 0, j = 0; i < m; i++) {
        while (s.data[j] != t.data[i]) {
            j++;
        }
        pre[i] = j++;
    }
    for (i = m - 1, j = n - 1; i >= 0; i--) {
        while (s.data[j] != t.data[i]) {
            j--;
        }
        suf[i] = j--;
    }
    int ans = (suf[0] > (n - 1 - pre[m - 1])) ? suf[0] : (n - 1 - pre[m - 1]);
    for (i = 0; i < m - 1; i++) {
        int diff = suf[i + 1] - 1 - pre[i];
        if (diff > ans) {
            ans = diff;
        }
    }
    printInt(ans);
    printString("\n");

    closeFastReader(&reader);
    free(s.data);
    free(t.data);
    free(pre);
    free(suf);
}

int main() {
    int test = 1;
    while (test-- > 0) {
        solve();
    }
    flush();
    return 0;
}
