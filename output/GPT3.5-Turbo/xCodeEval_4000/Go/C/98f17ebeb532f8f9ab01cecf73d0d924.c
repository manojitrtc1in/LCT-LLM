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

int scanBytes(char* data, int atEOF, int* advance, char** token, int* err) {
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

int scanRunes(char* data, int atEOF, int* advance, char** token, int* err) {
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
    strncpy(*token, "\xEF\xBF\xBD", 4);
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

int scanLines(char* data, int atEOF, int* advance, char** token, int* err) {
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

int scanWords(char* data, int atEOF, int* advance, char** token, int* err) {
    int start = 0;
    int len = strlen(data);
    while (start < len) {
        char c = data[start];
        if (!isSpace(c)) {
            break;
        }
        start++;
    }

    int i = start;
    while (i < len) {
        char c = data[i];
        if (isSpace(c)) {
            *advance = i + 1;
            *token = malloc(i - start + 1);
            strncpy(*token, data + start, i - start);
            (*token)[i - start] = '\0';
            *err = 0;
            return 0;
        }
        i++;
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

Scanner* newScanner(char* r) {
    Scanner* s = (Scanner*)malloc(sizeof(Scanner));
    s->r = r;
    s->split = 0;
    s->maxTokenSize = MAX_TOKEN_SIZE;
    s->token = NULL;
    s->buf = NULL;
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

int scan(Scanner* s) {
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
            s->token = token;
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
            if (strlen(s->buf) >= s->maxTokenSize || strlen(s->buf) > INT_MAX / 2) {
                setErr(s, -4);
                return 0;
            }
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
            int n = fread(s->buf + s->end, 1, strlen(s->buf) - s->end, s->r);
            s->end += n;
            if (n > 0) {
                s->empties = 0;
                break;
            }
            loop++;
            if (loop > 10) {
                setErr(s, -5);
                break;
            }
        }
    }
}

void printf(char* format, ...) {
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
    return fgets(s->buf, MAX_TOKEN_SIZE, s->r);
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
            return NULL;
        }
        if (!advance(s, advance)) {
            return NULL;
        }
        s->token = token;
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
            return token;
        }
        if (nextLine(s) == NULL) {
            return NULL;
        }
    }
}

int nextInt(Scanner* s) {
    int res = atoi(nextWord(s));
    if (s->err != 0) {
        printf("Error converting to int\n");
        exit(1);
    }
    return res;
}

long long nextInt64(Scanner* s) {
    long long res = atoll(nextWord(s));
    if (s->err != 0) {
        printf("Error converting to int64\n");
        exit(1);
    }
    return res;
}

double nextFloat64(Scanner* s) {
    double res = atof(nextWord(s));
    if (s->err != 0) {
        printf("Error converting to float64\n");
        exit(1);
    }
    return res;
}

int main() {
    char** board = (char**)malloc(8 * sizeof(char*));
    for (int i = 0; i < 8; i++) {
        board[i] = nextWord();
    }
    int total = 0;
    for (int i = 0; i < 8; i++) {
        int count = 0;
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'B') {
                count++;
            }
        }
        if (count == 8) {
            for (int j = 0; j < 8; j++) {
                board[i][j] = 'A';
            }
            total++;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[j][i] == 'B') {
                total++;
                break;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}
