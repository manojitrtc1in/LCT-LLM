#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 128 * 1024
#define MOD 1000000007

typedef struct {
    long *data;
    size_t size;
} LongArray;

typedef struct {
    char *data;
    size_t size;
} StringBuilder;

void initStringBuilder(StringBuilder *sb) {
    sb->data = (char *)malloc(MAX_SIZE);
    sb->size = 0;
}

void append(StringBuilder *sb, const char *str) {
    size_t len = strlen(str);
    memcpy(sb->data + sb->size, str, len);
    sb->size += len;
}

void appendLong(StringBuilder *sb, long value) {
    char buffer[20];
    sprintf(buffer, "%ld ", value);
    append(sb, buffer);
}

void appendNewLine(StringBuilder *sb) {
    append(sb, "\n");
}

void freeStringBuilder(StringBuilder *sb) {
    free(sb->data);
}

long min(long a, long b) {
    return a < b ? a : b;
}

void solver() {
    long n;
    scanf("%ld", &n);
    
    long ar[3], br[3];
    for (int i = 0; i < 3; i++) {
        scanf("%ld", &ar[i]);
    }
    for (int i = 0; i < 3; i++) {
        scanf("%ld", &br[i]);
    }

    long mxWins = 0;
    long id19 = 0;
    for (int i = 0; i < 3; i++) {
        mxWins += min(ar[i], br[(i + 1) % 3]);
        long mxLose = min(br[i], ar[(i + 1) % 3]);
        long mxDraw = min(br[i], ar[i]);
        id19 += min(br[i], mxLose + mxDraw);
    }

    StringBuilder out;
    initStringBuilder(&out);
    appendLong(&out, n - id19);
    appendLong(&out, mxWins);
    appendNewLine(&out);
    printf("%s", out.data);
    freeStringBuilder(&out);
}

int main() {
    solver();
    return 0;
}
