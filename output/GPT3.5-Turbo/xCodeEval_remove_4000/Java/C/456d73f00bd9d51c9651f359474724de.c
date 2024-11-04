#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    long long *d;
    int size;
} id36;

typedef struct {
    long long *size;
    long long *parent;
    int componentCount;
} id18;

typedef struct {
    int id;
    long long val;
} IDval;

typedef struct {
    char *buf;
    int bufc;
    int bufi;
} IO;

void solve();

IO *newIO();
void ioClose(IO *io);
void ioPrint(IO *io, const char *format, ...);
void ioFlush(IO *io);
char ioReadChar(IO *io);
char *ioReadString(IO *io);
int ioReadInt(IO *io);
long long ioReadLong(IO *io);
double ioReadDouble(IO *io);
void ioWriteChar(IO *io, char c);
void ioWriteString(IO *io, const char *s);
void ioWriteInt(IO *io, int n);
void ioWriteLong(IO *io, long long n);
void ioWriteDouble(IO *io, double n);
void ioWrite(IO *io, const char *format, ...);
void ioWriteLine(IO *io, const char *format, ...);
void ioWriteLineChar(IO *io, char c);
void ioWriteLineString(IO *io, const char *s);
void ioWriteLineInt(IO *io, int n);
void ioWriteLineLong(IO *io, long long n);
void ioWriteLineDouble(IO *io, double n);

int main() {
    solve();
    return 0;
}

void solve() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    if (m < n) {
        long long helper = m;
        m = n;
        n = helper;
    }

    if (n == 1) {
        printf("%lld\n", id17(m));
        return;
    }
    if (n == 2) {
        if (m < 3) printf("0\n");
        else if (m == 3) printf("4\n");
        else if (m == 7) printf("12\n");
        else printf("%lld\n", 2 * m);
        return;
    }

    printf("%lld\n", 2 * (n * m / 2));
}

long long id17(long long m) {
    long long ans = 6 * (m / 6);
    if (m % 6 == 5) ans += 4;
    else if (m % 6 == 4) ans += 2;
    return ans;
}
