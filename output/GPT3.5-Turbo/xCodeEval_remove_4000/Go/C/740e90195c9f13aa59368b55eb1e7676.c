#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 2048
#define START_BUF_SIZE 4096

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

int scanBytes(char* data, int atEOF, int* advance, char** token, int* err) {
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

int dropCR(char* data) {
    int len = strlen(data);
    if (len > 0 && data[len - 1] == '\r') {
        data[len - 1] = '\0';
    }
    return 0;
}

int scanLines(char* data, int atEOF, int* advance, char** token, int* err) {
    if (atEOF && strlen(data) == 0) {
        *advance = 0;
        *token = NULL;
        *err = 0;
        return 0;
    }
    int i = 0;
    while (data[i] != '\n' && data[i] != '\0') {
        i++;
    }
    if (data[i] == '\n') {
        *advance = i + 1;
        data[i] = '\0';
        dropCR(data);
        *token = data;
        *err = 0;
        return 0;
    }
    if (atEOF) {
        *advance = strlen(data);
        dropCR(data);
        *token = data;
        *err = 0;
        return 0;
    }
    *advance = 0;
    *token = NULL;
    *err = 0;
    return 0;
}

int isSpace(char c) {
    if (c <= '\u00FF') {
        switch (c) {
            case ' ':
            case '\t':
            case '\n':
            case '\v':
            case '\f':
            case '\r':
            case '\u0085':
            case '\u00A0':
                return 1;
            default:
                return 0;
        }
    }
    if ('\u2000' <= c && c <= '\u200a') {
        return 1;
    }
    switch (c) {
        case '\u1680':
        case '\u2028':
        case '\u2029':
        case '\u202f':
        case '\u205f':
        case '\u3000':
            return 1;
        default:
            return 0;
    }
}

int scanWords(char* data, int atEOF, int* advance, char** token, int* err) {
    int start = 0;
    int len = strlen(data);
    while (start < len && isSpace(data[start])) {
        start++;
    }
    int i = start;
    while (i < len && !isSpace(data[i])) {
        i++;
    }
    if (i < len) {
        *advance = i + 1;
        data[i] = '\0';
        *token = data + start;
        *err = 0;
        return 0;
    }
    if (atEOF && len > start) {
        *advance = len;
        *token = data + start;
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
    s->maxTokenSize = MAX_TOKEN_SIZE;
    s->token = (char*)malloc(MAX_TOKEN_SIZE);
    s->buf = (char*)malloc(START_BUF_SIZE);
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

int scan(Scanner* s, SplitFunc split, int* advance, char** token, int* err) {
    if (s->done) {
        return 0;
    }
    s->scanCalled = 1;
    while (1) {
        if (s->end > s->start || s->err != 0) {
            int adv, e;
            char* tok;
            split(s->buf + s->start, s->err != 0, &adv, &tok, &e);
            if (e != 0) {
                if (e == -1) {
                    strcpy(s->token, tok);
                    s->done = 1;
                    return 1;
                }
                setErr(s, e);
                return 0;
            }
            if (!advance(s, adv)) {
                return 0;
            }
            strcpy(s->token, tok);
            if (tok != NULL) {
                if (s->err == 0 || adv > 0) {
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
                setErr(s, -1);
                return 0;
            }
            int newSize = strlen(s->buf) * 2;
            if (newSize == 0) {
                newSize = START_BUF_SIZE;
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
            int n = strlen(s->buf + s->end);
            fgets(s->buf + s->end, n, s->r);
            s->end += strlen(s->buf + s->end);
            if (feof(s->r)) {
                setErr(s, EOF);
                break;
            }
            if (strlen(s->buf + s->end) > 0) {
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

void buffer(Scanner* s, char* buf, int max) {
    if (s->scanCalled) {
        printf("Buffer called after Scan\n");
        exit(1);
    }
    s->buf = buf;
    s->maxTokenSize = max;
}

int main() {
    Scanner* lineScanner = newScanner(stdin);
    Scanner* wordScanner = newScanner("");
    wordScanner->maxTokenSize = MAX_TOKEN_SIZE;
    wordScanner->split = scanWords;
    char format[10];
    char* line;
    char* word;
    int x, y;
    int visited[2000000];
    int i;
    for (i = 0; i < 2000000; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;
    line = nextLine(lineScanner);
    while (line != NULL) {
        word = strtok(line, " ");
        while (word != NULL) {
            if (strcmp(word, "U") == 0) {
                y--;
            } else if (strcmp(word, "D") == 0) {
                y++;
            } else if (strcmp(word, "L") == 0) {
                x--;
            } else if (strcmp(word, "R") == 0) {
                x++;
            }
            int pos = x * 1000 + y;
            if (visited[pos] == 1) {
                printf("BUG\n");
                return 0;
            }
            int count = 0;
            if (visited[(x - 1) * 1000 + y] == 1) {
                count++;
            }
            if (visited[(x + 1) * 1000 + y] == 1) {
                count++;
            }
            if (visited[x * 1000 + y - 1] == 1) {
                count++;
            }
            if (visited[x * 1000 + y + 1] == 1) {
                count++;
            }
            if (count > 1) {
                printf("BUG\n");
                return 0;
            }
            visited[pos] = 1;
            word = strtok(NULL, " ");
        }
        line = nextLine(lineScanner);
    }
    printf("OK\n");
    return 0;
}

char* nextLine(Scanner* s) {
    int advance, err;
    char* token;
    scan(s, scanLines, &advance, &token, &err);
    if (err == EOF) {
        return NULL;
    }
    return token;
}

char* nextWord(Scanner* s) {
    int advance, err;
    char* token;
    scan(s, scanWords, &advance, &token, &err);
    if (err == EOF) {
        return NULL;
    }
    return token;
}
