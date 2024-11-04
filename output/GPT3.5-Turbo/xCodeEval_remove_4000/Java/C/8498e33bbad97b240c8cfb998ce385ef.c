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
    long long *hashes;
    long long *modifiers;
} HashedString;

typedef struct {
    char buf[MAX_SIZE];
    int bufc;
    int bufi;
} IO;

IO io;

void fillBuf() {
    io.bufi = 0;
    io.bufc = 0;
    while (io.bufc == 0) {
        io.bufc = fread(io.buf, 1, MAX_SIZE, stdin);
        if (io.bufc == 0) {
            io.bufc = 0;
            return;
        }
    }
}

bool pumpBuf() {
    if (io.bufi == io.bufc) {
        fillBuf();
    }
    return io.bufc != 0;
}

bool isDelimiter(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f';
}

void skipDelimiter() {
    while (true) {
        if (io.bufi == io.bufc) {
            fillBuf();
            if (io.bufc == 0) {
                return;
            }
        }

        if (!isDelimiter(io.buf[io.bufi])) {
            break;
        }
        ++io.bufi;
    }
}

void readString(char *s) {
    skipDelimiter();
    int start = io.bufi;

    while (true) {
        if (io.bufi == io.bufc) {
            int len = io.bufi - start;
            strncpy(s, io.buf + start, len);
            s[len] = '\0';
            fillBuf();
            start = 0;
            if (io.bufc == 0) {
                break;
            }
        }

        if (isDelimiter(io.buf[io.bufi])) {
            int len = io.bufi - start;
            strncpy(s, io.buf + start, len);
            s[len] = '\0';
            break;
        }

        ++io.bufi;
    }
}

int readInt() {
    skipDelimiter();

    bool positive = true;
    if (io.buf[io.bufi] == '-') {
        ++io.bufi;
        if (!pumpBuf()) {
            return 0;
        }
        positive = false;
    }

    int ret = 0;
    while (true) {
        if (!pumpBuf()) {
            break;
        }
        if (isDelimiter(io.buf[io.bufi])) {
            break;
        }

        if (io.buf[io.bufi] >= '0' && io.buf[io.bufi] <= '9') {
            ret *= 10;
            ret -= (int)(io.buf[io.bufi] - '0');
        } else {
            break;
        }

        ++io.bufi;
    }

    if (positive) {
        ret = -ret;
    }

    return ret;
}

long long readLong() {
    skipDelimiter();

    bool positive = true;
    if (io.buf[io.bufi] == '-') {
        ++io.bufi;
        if (!pumpBuf()) {
            return 0;
        }
        positive = false;
    }

    long long ret = 0;
    while (true) {
        if (!pumpBuf()) {
            break;
        }
        if (isDelimiter(io.buf[io.bufi])) {
            break;
        }

        if (io.buf[io.bufi] >= '0' && io.buf[io.bufi] <= '9') {
            ret *= 10;
            ret -= (long long)(io.buf[io.bufi] - '0');
        } else {
            break;
        }

        ++io.bufi;
    }

    if (positive) {
        ret = -ret;
    }

    return ret;
}

double readDouble() {
    char s[100];
    readString(s);
    return atof(s);
}

void print(const char *output) {
    printf("%s\n", output);
}

void done() {
    throw "Clean exit";
}

long long min(int count, ...) {
    long long ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, long long);
    for (int i = 1; i < count; i++) {
        long long val = va_arg(args, long long);
        ans = (val < ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

double minf(int count, ...) {
    double ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double val = va_arg(args, double);
        ans = (val < ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

int minInt(int count, ...) {
    int ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        ans = (val < ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

long long max(int count, ...) {
    long long ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, long long);
    for (int i = 1; i < count; i++) {
        long long val = va_arg(args, long long);
        ans = (val > ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

double maxf(int count, ...) {
    double ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double val = va_arg(args, double);
        ans = (val > ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

int maxInt(int count, ...) {
    int ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, int);
    for (int i = 1; i < count; i++) {
        int val = va_arg(args, int);
        ans = (val > ans) ? val : ans;
    }
    va_end(args);
    return ans;
}

long long pow(long long base, int exp) {
    if (exp == 0) {
        return 1LL;
    }
    long long x = pow(base, exp / 2);
    long long ans = x * x;
    if (exp % 2 != 0) {
        ans *= base;
    }
    return ans;
}

long long gcd(int count, ...) {
    long long ans = 0;
    va_list args;
    va_start(args, count);
    ans = va_arg(args, long long);
    for (int i = 1; i < count; i++) {
        long long val = va_arg(args, long long);
        ans = gcd(ans, val);
    }
    va_end(args);
    return ans;
}

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
}

void id5(long long *P, long long *M) {
    long long modOptions[] = {353873237LL, 353875897LL, 353878703LL, 353882671LL, 353885303LL, 353888377LL, 353893457LL};
    *P = modOptions[rand() % 7];

    long long modOptions2[] = {452940277LL, 452947687LL, 464478431LL, 468098221LL, 470374601LL, 472879717LL, 472881973LL};
    *M = modOptions2[rand() % 7];
}

HashedString hashString(char *s) {
    int n = strlen(s);
    long long *hashes = (long long *)malloc(n * sizeof(long long));
    long long *modifiers = (long long *)malloc(n * sizeof(long long));
    hashes[0] = s[0];
    modifiers[0] = 1;
    for (int i = 1; i < n; i++) {
        hashes[i] = (hashes[i - 1] * P + s[i]) % M;
        modifiers[i] = (modifiers[i - 1] * P) % M;
    }
    HashedString hashedString;
    hashedString.hashes = hashes;
    hashedString.modifiers = modifiers;
    return hashedString;
}

long long getHash(HashedString hashedString, int startIndex, int endIndex) {
    long long *hashes = hashedString.hashes;
    long long *modifiers = hashedString.modifiers;
    long long result = hashes[endIndex];
    if (startIndex > 0) {
        result -= (hashes[startIndex - 1] * modifiers[endIndex - startIndex + 1]) % M;
    }
    if (result < 0) {
        result += M;
    }
    return result;
}

HashedString *hashStrings(int count, ...) {
    HashedString *array = (HashedString *)malloc(count * sizeof(HashedString));
    int n = strlen(va_arg(args, char *));
    long long *modifiers = (long long *)malloc(n * sizeof(long long));
    modifiers[0] = 1;

    for (int j = 0; j < count; j++) {
        char *s = va_arg(args, char *);

        if (strlen(s) != n) {
            for (int i = 0; i < count; i++) {
                array[i] = hashString(va_arg(args, char *));
            }
            return array;
        }

        long long *hashes = (long long *)malloc(n * sizeof(long long));
        hashes[0] = s[0];
        array[j].hashes = hashes;
        array[j].modifiers = modifiers;
    }
    for (int i = 1; i < n; i++) {
        modifiers[i] = (modifiers[i - 1] * P) % M;
        for (int j = 0; j < count; j++) {
            char *s = va_arg(args, char *);
            long long *hashes = array[j].hashes;
            hashes[i] = (hashes[i - 1] * P + s[i]) % M;
        }
    }
    return array;
}

int main() {
    io.bufc = 0;
    io.bufi = 0;

    long long P, M;
    id5(&P, &M);

    return 0;
}
