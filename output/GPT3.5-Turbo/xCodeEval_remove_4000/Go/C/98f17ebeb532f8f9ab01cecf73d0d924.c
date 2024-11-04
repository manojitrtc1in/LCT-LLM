#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 2048
#define MAX_BUF_SIZE 4096

typedef struct {
    char* r;
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
    *token = data;
    *err = 0;
    return 0;
}

char errorRune[] = "\xEF\xBF\xBD";

int ScanRunes(char* data, int atEOF, int* advance, char** token, int* err) {
    if (atEOF && strlen(data) == 0) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }

    if (data[0] < 0x80) {
        *advance = 1;
        *token = data;
        *err = 0;
        return 0;
    }

    int width = 0;
    int i = 0;
    while (data[i] & 0xC0 == 0x80) {
        width++;
        i++;
    }

    if (width > 1) {
        *advance = width;
        *token = data;
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
    *token = errorRune;
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
        *token = dropCR(strndup(data, newline - data));
        *err = 0;
        return 0;
    }

    if (atEOF) {
        *advance = strlen(data);
        *token = dropCR(strdup(data));
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
        }
        return 0;
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
    }
    return 0;
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
            *token = strndup(data + start, i - start);
            *err = 0;
            return 0;
        }
    }

    if (atEOF && len > start) {
        *advance = len;
        *token = strndup(data + start, len - start);
        *err = 0;
        return 0;
    }

    *advance = start;
    *token = NULL;
    *err = 0;
    return 0;
}

Scanner* NewScanner(char* r) {
    Scanner* s = (Scanner*)malloc(sizeof(Scanner));
    s->r = r;
    s->maxTokenSize = MAX_TOKEN_SIZE;
    s->token = (char*)malloc(MAX_TOKEN_SIZE);
    s->buf = (char*)malloc(MAX_BUF_SIZE);
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
        setErr(s, -4);
        return 0;
    }
    if (n > s->end - s->start) {
        setErr(s, -5);
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
            int result = s->split(s->buf + s->start, s->err != 0, &advance, &token, &err);
            if (result != 0) {
                if (result == -1) {
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
                        printf("Scan: 100 empty tokens without progressing\n");
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
            if (strlen(s->buf) >= s->maxTokenSize || strlen(s->buf) > MAX_BUF_SIZE / 2) {
                setErr(s, -1);
                return 0;
            }
            int newSize = strlen(s->buf) * 2;
            if (newSize == 0) {
                newSize = MAX_BUF_SIZE;
            }
            if (newSize > s->maxTokenSize) {
                newSize = s->maxTokenSize;
            }
            char* newBuf = (char*)malloc(newSize);
            memcpy(newBuf, s->buf + s->start, s->end - s->start);
            free(s->buf);
            s->buf = newBuf;
            s->end -= s->start;
            s->start = 0;
            continue;
        }

        int loop = 0;
        while (1) {
            int n = fread(s->buf + s->end, 1, MAX_BUF_SIZE - s->end, s->r);
            s->end += n;
            if (n > 0) {
                s->empties = 0;
                break;
            }
            loop++;
            if (loop > 10) {
                setErr(s, -2);
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
    if (Scan(s) == 0) {
        if (s->err != 0) {
            printf("nextLine: EOF reached\n");
            exit(1);
        }
        return NULL;
    }
    return s->token;
}

char* nextWord(Scanner* s) {
    while (Scan(s) == 0) {
        if (s->err != 0) {
            printf("nextWord: EOF reached\n");
            exit(1);
        }
        char* line = nextLine(s);
        if (line == NULL) {
            return NULL;
        }
        s->split = ScanWords;
        s->start = 0;
        s->end = strlen(line);
    }
    return s->token;
}

int nextInt(Scanner* s) {
    int res = atoi(nextWord(s));
    if (res == 0 && strcmp(s->token, "0") != 0) {
        printf("Error: Invalid integer\n");
        exit(1);
    }
    return res;
}

long long id3(Scanner* s) {
    long long res = atoll(nextWord(s));
    if (res == 0 && strcmp(s->token, "0") != 0) {
        printf("Error: Invalid integer\n");
        exit(1);
    }
    return res;
}

double id6(Scanner* s) {
    double res = atof(nextWord(s));
    if (res == 0 && strcmp(s->token, "0") != 0) {
        printf("Error: Invalid float\n");
        exit(1);
    }
    return res;
}

int main() {
    Scanner* lineScanner = NewScanner(stdin);
    Scanner* wordScanner = NewScanner("");
    wordScanner->split = ScanWords;

    char* board[8];
    for (int i = 0; i < 8; i++) {
        board[i] = strdup(nextWord(wordScanner));
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
