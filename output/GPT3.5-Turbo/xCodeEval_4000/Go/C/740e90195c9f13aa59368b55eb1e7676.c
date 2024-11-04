#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 2048

typedef struct {
    char* r;
    int split;
    int maxTokenSize;
    char* token;
    char* buf;
    int start;
    int end;
    int err;
    int empties;
    int scanCalled;
    int done;
} Scanner;

typedef int (*SplitFunc)(char* data, int atEOF, int* advance, char** token, int* err);

int ScanBytes(char* data, int atEOF, int* advance, char** token, int* err) {
    if (atEOF && strlen(data) == 0) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }
    *advance = 1;
    *token = malloc(2);
    (*token)[0] = data[0];
    (*token)[1] = '\0';
    *err = 0;
    return 0;
}

int ScanRunes(char* data, int atEOF, int* advance, char** token, int* err) {
    if (atEOF && strlen(data) == 0) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }

    if (data[0] < 128) {
        *advance = 1;
        *token = malloc(2);
        (*token)[0] = data[0];
        (*token)[1] = '\0';
        *err = 0;
        return 0;
    }

    int width = 0;
    int i = 0;
    while (data[i] != '\0') {
        if ((data[i] & 0xC0) != 0x80) {
            break;
        }
        width++;
        i++;
    }

    if (width > 1) {
        *advance = width;
        *token = malloc(width + 1);
        strncpy(*token, data, width);
        (*token)[width] = '\0';
        *err = 0;
        return 0;
    }

    if (!atEOF && strlen(data) < width) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }

    *advance = 1;
    *token = malloc(4);
    (*token)[0] = 0xEF;
    (*token)[1] = 0xBF;
    (*token)[2] = 0xBD;
    (*token)[3] = '\0';
    *err = 0;
    return 0;
}

char* dropCR(char* data) {
    int len = strlen(data);
    if (len > 0 && data[len - 1] == '\r') {
        data[len - 1] = '\0';
    }
    return data;
}

int ScanLines(char* data, int atEOF, int* advance, char** token, int* err) {
    if (atEOF && strlen(data) == 0) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }
    char* newline = strchr(data, '\n');
    if (newline != NULL) {
        *advance = newline - data + 1;
        *token = malloc(*advance);
        strncpy(*token, data, *advance - 1);
        (*token)[*advance - 1] = '\0';
        *err = 0;
        return 0;
    }

    if (atEOF) {
        *advance = strlen(data);
        *token = malloc(*advance);
        strncpy(*token, data, *advance);
        (*token)[*advance] = '\0';
        *err = 0;
        return 0;
    }

    *advance = 0;
    *token = NULL;
    *err = 0;
    return 0;
}

int isSpace(char c) {
    if (c <= 0xFF) {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\v':
            case '\f':
            case '\r':
            case '\x85':
            case '\xA0':
                return 1;
            default:
                return 0;
        }
    }

    if (c >= 0x2000 && c <= 0x200A) {
        return 1;
    }

    switch (c) {
        case 0x1680:
        case 0x2028:
        case 0x2029:
        case 0x202F:
        case 0x205F:
        case 0x3000:
            return 1;
        default:
            return 0;
    }
}

int ScanWords(char* data, int atEOF, int* advance, char** token, int* err) {
    int start = 0;
    int len = strlen(data);
    while (start < len) {
        char c = data[start];
        if (!isSpace(c)) {
            break;
        }
        start++;
    }

    for (int i = start; i < len; i++) {
        char c = data[i];
        if (isSpace(c)) {
            *advance = i + 1;
            *token = malloc(i - start + 1);
            strncpy(*token, data + start, i - start);
            (*token)[i - start] = '\0';
            *err = 0;
            return 0;
        }
    }

    if (atEOF && len > start) {
        *advance = len;
        *token = malloc(len - start + 1);
        strncpy(*token, data + start, len - start);
        (*token)[len - start] = '\0';
        *err = 0;
        return 0;
    }

    *advance = start;
    *token = NULL;
    *err = 0;
    return 0;
}

Scanner* NewScanner(char* r) {
    Scanner* s = malloc(sizeof(Scanner));
    s->r = r;
    s->split = 0;
    s->maxTokenSize = MAX_TOKEN_SIZE;
    s->token = malloc(MAX_TOKEN_SIZE);
    s->buf = malloc(MAX_TOKEN_SIZE);
    s->start = 0;
    s->end = 0;
    s->err = 0;
    s->empties = 0;
    s->scanCalled = 0;
    s->done = 0;
    return s;
}

void setErr(Scanner* s, int err) {
    if (s->err == 0 || s->err == EOF) {
        s->err = err;
    }
}

int advance(Scanner* s, int n) {
    if (n < 0) {
        setErr(s, -1);
        return 0;
    }
    if (n > s->end - s->start) {
        setErr(s, -2);
        return 0;
    }
    s->start += n;
    return 1;
}

int Scan(Scanner* s) {
    if (s->done) {
        return 0;
    }
    s->scanCalled = 1;

    while (1) {
        if (s->end > s->start || s->err != 0) {
            int advance, err;
            char* token;
            s->split(s->buf + s->start, s->err != 0, &advance, &token, &err);
            if (err != 0) {
                if (err == -3) {
                    s->token = token;
                    s->done = 1;
                    return 1;
                }
                setErr(s, err);
                return 0;
            }
            if (!advance(s, advance)) {
                return 0;
            }
            strcpy(s->token, token);
            if (token != NULL) {
                if (s->err == 0 || advance > 0) {
                    s->empties = 0;
                } else {
                    s->empties++;
                    if (s->empties > 100) {
                        printf("bufio.Scan: 100 empty tokens without progressing\n");
                        exit(1);
                    }
                }
                return 1;
            }
        }

        if (s->err != 0) {
            s->start = 0;
            s->end = 0;
            return 0;
        }

        if (s->start > 0 && (s->end == strlen(s->buf) || s->start > strlen(s->buf) / 2)) {
            memmove(s->buf, s->buf + s->start, s->end - s->start);
            s->end -= s->start;
            s->start = 0;
        }

        if (s->end == strlen(s->buf)) {
            int newSize = strlen(s->buf) * 2;
            if (newSize == 0) {
                newSize = 4096;
            }
            if (newSize > s->maxTokenSize) {
                newSize = s->maxTokenSize;
            }
            char* newBuf = malloc(newSize);
            memcpy(newBuf, s->buf + s->start, s->end - s->start);
            free(s->buf);
            s->buf = newBuf;
            s->end -= s->start;
            s->start = 0;
            continue;
        }

        int loop = 0;
        while (1) {
            int n = fread(s->buf + s->end, 1, MAX_TOKEN_SIZE - s->end, s->r);
            s->end += n;
            if (n > 0) {
                s->empties = 0;
                break;
            }
            loop++;
            if (loop > 10) {
                setErr(s, -4);
                break;
            }
        }
    }
}

void printf(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

char* nextLine(Scanner* s) {
    if (s->err != 0) {
        if (s->err == EOF) {
            return NULL;
        }
        printf("nextLine: EOF reached\n");
        exit(1);
    }
    char* line = malloc(MAX_TOKEN_SIZE);
    if (fgets(line, MAX_TOKEN_SIZE, s->r) == NULL) {
        if (feof(s->r)) {
            s->err = EOF;
            return NULL;
        }
        printf("nextLine: Error reading input\n");
        exit(1);
    }
    dropCR(line);
    return line;
}

char* nextWord(Scanner* s) {
    if (s->err != 0) {
        if (s->err == EOF) {
            return NULL;
        }
        printf("nextWord: EOF reached\n");
        exit(1);
    }
    while (1) {
        int advance, err;
        char* token;
        s->split(s->buf + s->start, s->err != 0, &advance, &token, &err);
        if (err != 0) {
            if (err == -3) {
                s->token = token;
                s->done = 1;
                return token;
            }
            setErr(s, err);
            exit(1);
        }
        if (advance(s, advance)) {
            return token;
        }
    }
}

int nextInt(Scanner* s) {
    char* word = nextWord(s);
    int res = atoi(word);
    free(word);
    return res;
}

long long nextInt64(Scanner* s) {
    char* word = nextWord(s);
    long long res = atoll(word);
    free(word);
    return res;
}

double nextFloat64(Scanner* s) {
    char* word = nextWord(s);
    double res = atof(word);
    free(word);
    return res;
}

int main() {
    Scanner* lineScanner = NewScanner(stdin);
    Scanner* wordScanner = NewScanner("");
    wordScanner->split = ScanWords;

    char* path = nextWord(wordScanner);
    int x = 0, y = 0;
    int* visited = malloc(sizeof(int) * 1000000);
    memset(visited, 0, sizeof(int) * 1000000);
    visited[0] = 1;
    int len = strlen(path);
    for (int i = 0; i < len; i++) {
        char c = path[i];
        switch (c) {
            case 'U':
                y--;
                break;
            case 'D':
                y++;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
        }
        if (visited[x * 1000 + y]) {
            printf("BUG\n");
            return 0;
        }
        int count = 0;
        if (visited[(x - 1) * 1000 + y]) {
            count++;
        }
        if (visited[(x + 1) * 1000 + y]) {
            count++;
        }
        if (visited[x * 1000 + y - 1]) {
            count++;
        }
        if (visited[x * 1000 + y + 1]) {
            count++;
        }
        if (count > 1) {
            printf("BUG\n");
            return 0;
        }
        visited[x * 1000 + y] = 1;
    }
    printf("OK\n");
    return 0;
}
