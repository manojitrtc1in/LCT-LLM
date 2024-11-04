#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100000

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    long val;
    int id;
} IDval;

typedef struct {
    int id;
    long val;
} IDvalC;

typedef struct {
    long element;
    int count;
} ElementCount;

typedef struct {
    char* identifier;
    int count;
} StringCount;

typedef struct {
    int size;
    int* parent;
    int* rank;
} DisjointSet;

typedef struct {
    int N;
    int Z;
    int nextFreeId;
    int** pointers;
    bool* end;
} Trie;

typedef struct {
    int n;
    long* original;
    long* bottomUp;
    long* topDown;
} FenwickMin;

typedef struct {
    long* d;
} FenwickSum;

typedef struct {
    int N;
    long* p;
} SegmentTree;

typedef struct {
    int y;
    int x;
} Point;

typedef struct {
    long* hashes;
    long* modifiers;
} HashedString;

typedef struct {
    long* hashes;
    long* modifiers;
} HashedStringC;

typedef struct {
    int* forw;
    int* bacw;
} StronglyConnectedComponents;

typedef struct {
    int* nodes;
    int* depths;
    int* entries;
    int pointer;
    FenwickMin* fenwick;
} LCAFinder;

typedef struct {
    int* edges[MAX_SIZE];
} Graph;

typedef struct {
    int* div;
} Primes;

typedef struct {
    long* v;
} BinomialCoefficients;

typedef struct {
    int* z;
} Zalgo;

typedef struct {
    long P;
    long M;
} StringHasher;

typedef struct {
    int bufc;
    int bufi;
    char buf[1 << 15];
    char sb[1 << 15];
} IO;

IO* new_IO() {
    IO* io = (IO*)malloc(sizeof(IO));
    io->bufc = 0;
    io->bufi = 0;
    return io;
}

void IO_fillBuf(IO* io) {
    io->bufi = 0;
    io->bufc = 0;
    while (io->bufc == 0) {
        io->bufc = fread(io->buf, sizeof(char), sizeof(io->buf), stdin);
        if (io->bufc == -1) {
            io->bufc = 0;
            return;
        }
    }
}

bool IO_pumpBuf(IO* io) {
    if (io->bufi == io->bufc) {
        IO_fillBuf(io);
    }
    return io->bufc != 0;
}

bool IO_isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

void IO_eatDelimiters(IO* io) {
    while (true) {
        if (io->bufi == io->bufc) {
            IO_fillBuf(io);
            if (io->bufc == 0) {
                return;
            }
        }

        if (!IO_isDelimiter(io->buf[io->bufi])) {
            break;
        }
        ++io->bufi;
    }
}

char* IO_next(IO* io) {
    char* sb = io->sb;
    sb[0] = '\0';

    IO_eatDelimiters(io);
    int start = io->bufi;

    while (true) {
        if (io->bufi == io->bufc) {
            int len = io->bufi - start;
            strncat(sb, io->buf + start, len);
            IO_fillBuf(io);
            start = 0;
            if (io->bufc == 0) {
                break;
            }
        }

        if (IO_isDelimiter(io->buf[io->bufi])) {
            if (io->bufi == start) {
                break;
            }
            break;
        }

        strncat(sb, io->buf + start, 1);
        ++io->bufi;
    }

    return sb;
}

int IO_nextInt(IO* io) {
    IO_eatDelimiters(io);

    bool positive = true;
    if (io->buf[io->bufi] == '-') {
        ++io->bufi;
        if (!IO_pumpBuf(io)) {
            return -1;
        }
        positive = false;
    }

    int ret = 0;
    bool first = true;
    while (true) {
        if (!IO_pumpBuf(io)) {
            break;
        }
        if (IO_isDelimiter(io->buf[io->bufi])) {
            if (first) {
                return -1;
            }
            break;
        }
        first = false;

        if (io->buf[io->bufi] >= '0' && io->buf[io->bufi] <= '9') {
            if (ret < -214748364) {
                return -1;
            }
            ret *= 10;
            ret -= (int)(io->buf[io->bufi] - '0');
            if (ret > 0) {
                return -1;
            }
        } else {
            return -1;
        }

        ++io->bufi;
    }

    if (positive) {
        if (ret == -2147483648) {
            return -1;
        }
        ret = -ret;
    }

    return ret;
}

long IO_nextLong(IO* io) {
    IO_eatDelimiters(io);

    bool positive = true;
    if (io->buf[io->bufi] == '-') {
        ++io->bufi;
        if (!IO_pumpBuf(io)) {
            return -1;
        }
        positive = false;
    }

    long ret = 0;
    bool first = true;
    while (true) {
        if (!IO_pumpBuf(io)) {
            break;
        }
        if (IO_isDelimiter(io->buf[io->bufi])) {
            if (first) {
                return -1;
            }
            break;
        }
        first = false;

        if (io->buf[io->bufi] >= '0' && io->buf[io->bufi] <= '9') {
            if (ret < -922337203685477580L) {
                return -1;
            }
            ret *= 10;
            ret -= (long)(io->buf[io->bufi] - '0');
            if (ret > 0) {
                return -1;
            }
        } else {
            return -1;
        }

        ++io->bufi;
    }

    if (positive) {
        if (ret == -9223372036854775808L) {
            return -1;
        }
        ret = -ret;
    }

    return ret;
}

double IO_nextDouble(IO* io) {
    return atof(IO_next(io));
}

void IO_print(IO* io, char* output) {
    printf("%s\n", output);
}

void IO_done(IO* io, char* output) {
    IO_print(io, output);
    free(io);
    exit(0);
}

long min(long* v, int size) {
    long ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmin(ans, v[i]);
    }
    return ans;
}

double min(double* v, int size) {
    double ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmin(ans, v[i]);
    }
    return ans;
}

int min(int* v, int size) {
    int ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmin(ans, v[i]);
    }
    return ans;
}

long max(long* v, int size) {
    long ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmax(ans, v[i]);
    }
    return ans;
}

double max(double* v, int size) {
    double ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmax(ans, v[i]);
    }
    return ans;
}

int max(int* v, int size) {
    int ans = v[0];
    for (int i = 1; i < size; i++) {
        ans = fmax(ans, v[i]);
    }
    return ans;
}

void initializePandM(long* P, long* M) {
    long modOptions[7] = {353873237L, 353875897L, 353878703L, 353882671L, 353885303L, 353888377L, 353893457L};
    *P = modOptions[rand() % 7];

    long modOptions2[7] = {452940277L, 452947687L, 464478431L, 468098221L, 470374601L, 472879717L, 472881973L};
    *M = modOptions2[rand() % 7];
}

HashedString* hashString(char* s, int n, long P, long M) {
    long* hashes = (long*)malloc(n * sizeof(long));
    long* modifiers = (long*)malloc(n * sizeof(long));
    hashes[0] = s[0];
    modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        hashes[i] = (hashes[i - 1] * P + s[i]) % M;
        modifiers[i] = (modifiers[i - 1] * P) % M;
    }
    HashedString* hashedString = (HashedString*)malloc(sizeof(HashedString));
    hashedString->hashes = hashes;
    hashedString->modifiers = modifiers;
    return hashedString;
}

long getHash(HashedString* hashedString, int startIndex, int endIndex, long* P, long* M) {
    long* hashes = hashedString->hashes;
    long* modifiers = hashedString->modifiers;
    long result = hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashes[startIndex - 1] * modifiers[endIndex - startIndex + 1]) % *M;
    }
    if (result < 0) {
        result += *M;
    }
    return result;
}

HashedString** hashStringArr(char** strings, int numStrings, int n, long P, long M) {
    HashedString** array = (HashedString**)malloc(numStrings * sizeof(HashedString*));
    long* modifiers = (long*)malloc(n * sizeof(long));
    modifiers[0] = 1;
    for (int j = 0; j < numStrings; j++) {
        char* s = strings[j];

        long* hashes = (long*)malloc(n * sizeof(long));
        hashes[0] = s[0];
        array[j] = (HashedString*)malloc(sizeof(HashedString));
        array[j]->hashes = hashes;
        array[j]->modifiers = modifiers;
    }
    for (int i = 1; i < n; i++) {
        modifiers[i] = (modifiers[i - 1] * P) % M;
        for (int j = 0; j < numStrings; j++) {
            char* s = strings[j];
            long* hashes = array[j]->hashes;
            hashes[i] = (hashes[i - 1] * P + s[i]) % M;
        }
    }
    return array;
}

int main() {
    IO* io = new_IO();

    // Your code here

    free(io);
    return 0;
}
