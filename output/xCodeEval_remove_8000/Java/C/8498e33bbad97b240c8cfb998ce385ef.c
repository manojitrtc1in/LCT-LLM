#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 1000000

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    long* hashes;
    long* modifiers;
} HashedString;

typedef struct {
    long P;
    long M;
} StringHasher;

typedef struct {
    char* buf;
    int bufc;
    int bufi;
} IO;

void fillBuf(IO* io) {
    io->bufi = 0;
    io->bufc = 0;
    while (io->bufc == 0) {
        io->bufc = fread(io->buf, sizeof(char), MAX_SIZE, stdin);
        if (io->bufc == -1) {
            io->bufc = 0;
            return;
        }
    }
}

bool pumpBuf(IO* io) {
    if (io->bufi == io->bufc) {
        fillBuf(io);
    }
    return io->bufc != 0;
}

bool isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

void skipDelimiters(IO* io) {
    while (true) {
        if (io->bufi == io->bufc) {
            fillBuf(io);
            if (io->bufc == 0) {
                break;
            }
        }
        if (!isDelimiter(io->buf[io->bufi])) {
            break;
        }
        io->bufi++;
    }
}

void initIO(IO* io) {
    io->buf = (char*)malloc(MAX_SIZE * sizeof(char));
    io->bufc = 0;
    io->bufi = 0;
}

void print(IO* io, const char* output) {
    printf("%s", output);
}

void done(IO* io) {
    free(io->buf);
    exit(0);
}

long min(long a, long b) {
    return a < b ? a : b;
}

double min(double a, double b) {
    return a < b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

long max(long a, long b) {
    return a > b ? a : b;
}

double max(double a, double b) {
    return a > b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

HashedString hashString(StringHasher* hasher, const char* s) {
    int n = strlen(s);
    long* hashes = (long*)malloc(n * sizeof(long));
    long* modifiers = (long*)malloc(n * sizeof(long));
    hashes[0] = s[0];
    modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        hashes[i] = (hashes[i - 1] * hasher->P + s[i]) % hasher->M;
        modifiers[i] = (modifiers[i - 1] * hasher->P) % hasher->M;
    }
    HashedString hashedString;
    hashedString.hashes = hashes;
    hashedString.modifiers = modifiers;
    return hashedString;
}

long getHash(HashedString* hashedString, int startIndex, int endIndex) {
    long* hashes = hashedString->hashes;
    long* modifiers = hashedString->modifiers;
    long result = hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashes[startIndex - 1] * modifiers[endIndex - startIndex + 1]) % hashedString->M;
    }
    if (result < 0) {
        result += hashedString->M;
    }
    return result;
}

void initStringHasher(StringHasher* hasher) {
    long POptions[] = {353873237, 353875897, 353878703, 353882671, 353885303, 353888377, 353893457};
    hasher->P = POptions[rand() % (sizeof(POptions) / sizeof(POptions[0]))];

    long MOptions[] = {452940277, 452947687, 464478431, 468098221, 470374601, 472879717, 472881973};
    hasher->M = MOptions[rand() % (sizeof(MOptions) / sizeof(MOptions[0]))];
}

int main() {
    IO io;
    initIO(&io);

    // Your code here

    done(&io);
    return 0;
}
