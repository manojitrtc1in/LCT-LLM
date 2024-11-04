#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_SIZE 1<<13
#define mod 998244353
#define G 3

typedef struct {
    int* upper;
} DJSet;

typedef struct {
    char* buf;
    int ptr;
    FILE* out;
} FastWriter;

void solve();
long sum(long* a);
long* mul(long* a, long* b);
long* mul_lim(long* a, long* b, int lim);
long* id3(long* a, long* b);
long* id3_lim(long* a, long* b, int lim);
void fft(long* X, long* Y);
long* go(long* src, int n, bool inverse);
long pow_mod(long a, long n);
long invl(long a);
long C(int n, int r, int mod, int** fif);
int** id0(int n, int mod);
DJSet* createDJSet(int n);
int root(DJSet* ds, int x);
bool equiv(DJSet* ds, int x, int y);
bool unite(DJSet* ds, int x, int y);
int count(DJSet* ds);
int** toBucket(DJSet* ds);
void run();
int readByte();
bool id1(int c);
int skip();
double nd();
char nc();
char* ns();
char* ns_n(int n);
int* na(int n);
long* nal(int n);
char** nm(int n, int m);
int** nmi(int n, int m);
int ni();
long nl();
FastWriter* createFastWriter(FILE* out);
FastWriter* write(FastWriter* fw, char c);
FastWriter* write_str(FastWriter* fw, char* s);
FastWriter* write_int(FastWriter* fw, int x);
FastWriter* write_long(FastWriter* fw, long x);
FastWriter* write_double(FastWriter* fw, double x, int precision);
FastWriter* writeln(FastWriter* fw);
FastWriter* writeln_char(FastWriter* fw, char c);
FastWriter* writeln_int(FastWriter* fw, int x);
FastWriter* writeln_long(FastWriter* fw, long x);
FastWriter* writeln_double(FastWriter* fw, double x, int precision);
FastWriter* write_ints(FastWriter* fw, int* xs, int n);
FastWriter* write_longs(FastWriter* fw, long* xs, int n);
FastWriter* writeln_ints(FastWriter* fw, int* xs, int n);
FastWriter* writeln_longs(FastWriter* fw, long* xs, int n);
FastWriter* writeln_str(FastWriter* fw, char* s);
void innerflush(FastWriter* fw);
void flush(FastWriter* fw);
void trnz(int* o, int n);
void trt(long* o, int n);
void tf(bool* r, int n);
void tf2(bool** b, int n, int m);
void tf3(long** b, int n, int m);
void tf4(long* b, int n);
void tr(int* o, int n);
void tr2(int** b, int n, int m);
void tr3(long** b, int n, int m);
void tr4(long* b, int n);
void tr_str(char** o, int n);
void tr2_str(char*** b, int n, int m);
void tr3_str(char*** b, int n, int m);
void tr4_str(char** b, int n);
void tr_double(double* o, int n);
void tr2_double(double** b, int n, int m);
void tr3_double(double** b, int n, int m);
void tr4_double(double* b, int n);

int main() {
    run();
    return 0;
}

void solve() {
    int n = ni();
    bool g[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g[i][j] = false;
        }
    }
    for (int m = ni(); m > 0; m--) {
        int x = ni(), y = ni();
        g[x][y] = g[y][x] = true;
    }
    for (int i = 0; i < 10; i++) {
        g[i][i] = true;
    }

    int njs[1 << 9][10];
    for (int j = 0; j < 1 << 9; j++) {
        for (int k = 0; k < 10; k++) {
            if (j << ~k >= 0) {
                int nj = j;
                for (int l = 0; l < 10; l++) {
                    if (g[k][l]) {
                        if (k > l) {
                            nj |= 1 << l;
                        }
                    } else {
                        nj &= ~(1 << l);
                    }
                }
                njs[j][k] = nj;
            }
        }
    }

    long dp[1 << 9];
    for (int i = 0; i < 1 << 9; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long ndp[1 << 9];
        for (int j = 0; j < 1 << 9; j++) {
            ndp[j] = 0;
        }
        for (int j = 0; j < 1 << 9; j++) {
            for (int k = 0; k < 10; k++) {
                if (j << ~k >= 0) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= mod) {
                        ndp[nj] -= mod;
                    }
                }
            }
        }
        for (int j = 0; j < 1 << 9; j++) {
            dp[j] = ndp[j];
        }
    }
    long ans = sum(dp) % mod;
    writeln_long(createFastWriter(stdout), ans);
}

long sum(long* a) {
    long ret = 0;
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
        ret += a[i];
    }
    return ret;
}

long* mul(long* a, long* b) {
    int a_len = sizeof(a) / sizeof(a[0]);
    int b_len = sizeof(b) / sizeof(b[0]);
    if (a_len == 0 && b_len == 0) {
        return malloc(0);
    }
    if (a_len + b_len >= 300) {
        return id3(a, b);
    } else {
        return id3_lim(a, b, a_len + b_len - 1);
    }
}

long* mul_lim(long* a, long* b, int lim) {
    int a_len = sizeof(a) / sizeof(a[0]);
    int b_len = sizeof(b) / sizeof(b[0]);
    if (a_len + b_len >= 300) {
        return id3(a, b);
    } else {
        return id3_lim(a, b, lim);
    }
}

long* id3(long* a, long* b) {
    int a_len = sizeof(a) / sizeof(a[0]);
    int b_len = sizeof(b) / sizeof(b[0]);
    long* c = malloc((a_len + b_len - 1) * sizeof(long));
    for (int i = 0; i < a_len + b_len - 1; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < b_len; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= mod) {
                c[i + j] -= mod;
            }
        }
    }
    for (int i = 0; i < a_len + b_len - 1; i++) {
        c[i] %= mod;
    }
    return c;
}

long* id3_lim(long* a, long* b, int lim) {
    int a_len = sizeof(a) / sizeof(a[0]);
    int b_len = sizeof(b) / sizeof(b[0]);
    long* c = malloc(lim * sizeof(long));
    for (int i = 0; i < lim; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < a_len; i++) {
        for (int j = 0; j < b_len && i + j < lim; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= mod) {
                c[i + j] -= mod;
            }
        }
    }
    for (int i = 0; i < lim; i++) {
        c[i] %= mod;
    }
    return c;
}

void fft(long* X, long* Y) {
    int s = 1;
    bool eo = false;
    int n = sizeof(X) / sizeof(X[0]);
    for (int n = sizeof(X) / sizeof(X[0]); n >= 4; n /= 2) {
        int m = n / 2;
        for (int p = 0; p < m; p++) {
            long wp = wps[s * p];
            long wk = (wp << 32) / mod;
            for (int q = 0; q < s; q++) {
                long a = X[q + s * (p + 0)];
                long b = X[q + s * (p + m)];
                long ndsts = a + b;
                if (ndsts >= 2 * mod) {
                    ndsts -= 2 * mod;
                }
                long T = a - b + 2 * mod;
                long Q = wk * T >> 32;
                Y[q + s * (2 * p + 0)] = ndsts;
                Y[q + s * (2 * p + 1)] = wp * T - Q * mod & (1L << 32) - 1;
            }
        }
        s *= 2;
        eo = !eo;
        long* D = X;
        X = Y;
        Y = D;
    }
    long* z = eo ? Y : X;
    for (int q = 0; q < s; q++) {
        long a = X[q + 0];
        long b = X[q + s];
        z[q + 0] = (a + b) % mod;
        z[q + s] = (a - b + 2 * mod) % mod;
    }
}

long* go(long* src, int n, bool inverse) {
    long* dst = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
    fft(dst, malloc(n * sizeof(long)));
    if (inverse) {
        long in = invl(n);
        for (int i = 0; i < n; i++) {
            dst[i] = dst[i] * in % mod;
        }
    }
    return dst;
}

long pow_mod(long a, long n) {
    long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % mod;
        if (n << ~x < 0) {
            ret = ret * a % mod;
        }
    }
    return ret;
}

long invl(long a) {
    long b = mod;
    long p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    return p < 0 ? p + mod : p;
}

long C(int n, int r, int mod, int** fif) {
    if (n < 0 || r < 0 || r > n) {
        return 0;
    }
    return (long) fif[0][n] * fif[1][r] % mod * fif[1][n - r] % mod;
}

int** id0(int n, int mod) {
    int* f = malloc((n + 1) * sizeof(int));
    int* invf = malloc((n + 1) * sizeof(int));
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = (long) f[i - 1] * i % mod;
    }
    long a = f[n];
    long b = mod;
    long p = 1, q = 0;
    while (b > 0) {
        long c = a / b;
        long d;
        d = a;
        a = b;
        b = d % b;
        d = p;
        p = q;
        q = d - c * q;
    }
    invf[n] = p < 0 ? p + mod : p;
    for (int i = n - 1; i >= 0; i--) {
        invf[i] = (long) invf[i + 1] * (i + 1) % mod;
    }
    int** ret = malloc(2 * sizeof(int*));
    ret[0] = f;
    ret[1] = invf;
    return ret;
}

DJSet* createDJSet(int n) {
    DJSet* ds = malloc(sizeof(DJSet));
    ds->upper = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ds->upper[i] = -1;
    }
    return ds;
}

int root(DJSet* ds, int x) {
    return ds->upper[x] < 0 ? x : (ds->upper[x] = root(ds, ds->upper[x]));
}

bool equiv(DJSet* ds, int x, int y) {
    return root(ds, x) == root(ds, y);
}

bool unite(DJSet* ds, int x, int y) {
    x = root(ds, x);
    y = root(ds, y);
    if (x != y) {
        if (ds->upper[y] < ds->upper[x]) {
            int d = x;
            x = y;
            y = d;
        }
        ds->upper[x] += ds->upper[y];
        ds->upper[y] = x;
    }
    return x == y;
}

int count(DJSet* ds) {
    int ct = 0;
    for (int i = 0; i < sizeof(ds->upper) / sizeof(ds->upper[0]); i++) {
        if (ds->upper[i] < 0) {
            ct++;
        }
    }
    return ct;
}

int** toBucket(DJSet* ds) {
    int n = sizeof(ds->upper) / sizeof(ds->upper[0]);
    int** ret = malloc(n * sizeof(int*));
    int* rp = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (ds->upper[i] < 0) {
            ret[i] = malloc(-ds->upper[i] * sizeof(int));
        }
    }
    for (int i = 0; i < n; i++) {
        int r = root(ds, i);
        ret[r][rp[r]++] = i;
    }
    return ret;
}

void run() {
    solve();
}

int readByte() {
    return getchar();
}

bool id1(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && id1(b));
    return b;
}

double nd() {
    double ret;
    scanf("%lf", &ret);
    return ret;
}

char nc() {
    return (char) skip();
}

char* ns() {
    int b = skip();
    char* sb = malloc(BUF_SIZE * sizeof(char));
    int ptr = 0;
    while (!id1(b)) {
        sb[ptr++] = b;
        b = readByte();
    }
    return sb;
}

char* ns_n(int n) {
    char* buf = malloc(n * sizeof(char));
    int b = skip();
    int p = 0;
    while (p < n && !id1(b)) {
        buf[p++] = (char) b;
        b = readByte();
    }
    return n == p ? buf : realloc(buf, p * sizeof(char));
}

int* na(int n) {
    int* a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        a[i] = ni();
    }
    return a;
}

long* nal(int n) {
    long* a = malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        a[i] = nl();
    }
    return a;
}

char** nm(int n, int m) {
    char** map = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        map[i] = ns_n(m);
    }
    return map;
}

int** nmi(int n, int m) {
    int** map = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        map[i] = na(m);
    }
    return map;
}

int ni() {
    int num;
    scanf("%d", &num);
    return num;
}

long nl() {
    long num;
    scanf("%ld", &num);
    return num;
}

FastWriter* createFastWriter(FILE* out) {
    FastWriter* fw = malloc(sizeof(FastWriter));
    fw->buf = malloc(BUF_SIZE * sizeof(char));
    fw->ptr = 0;
    fw->out = out;
    return fw;
}

FastWriter* write(FastWriter* fw, char c) {
    fw->buf[fw->ptr++] = c;
    if (fw->ptr == BUF_SIZE) {
        innerflush(fw);
    }
    return fw;
}

FastWriter* write_str(FastWriter* fw, char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        write(fw, s[i]);
    }
    return fw;
}

FastWriter* write_int(FastWriter* fw, int x) {
    if (x == -2147483648) {
        return write_str(fw, "-2147483648");
    }
    if (fw->ptr + 12 >= BUF_SIZE) {
        innerflush(fw);
    }
    if (x < 0) {
        write(fw, '-');
        x = -x;
    }
    int d = 0;
    int temp = x;
    while (temp > 0) {
        temp /= 10;
        d++;
    }
    for (int i = fw->ptr + d - 1; i >= fw->ptr; i--) {
        fw->buf[i] = '0' + x % 10;
        x /= 10;
    }
    fw->ptr += d;
    return fw;
}

FastWriter* write_long(FastWriter* fw, long x) {
    if (x == -9223372036854775807L - 1) {
        return write_str(fw, "-9223372036854775808");
    }
    if (fw->ptr + 21 >= BUF_SIZE) {
        innerflush(fw);
    }
    if (x < 0) {
        write(fw, '-');
        x = -x;
    }
    int d = 0;
    long temp = x;
    while (temp > 0) {
        temp /= 10;
        d++;
    }
    for (int i = fw->ptr + d - 1; i >= fw->ptr; i--) {
        fw->buf[i] = '0' + x % 10;
        x /= 10;
    }
    fw->ptr += d;
    return fw;
}

FastWriter* write_double(FastWriter* fw, double x, int precision) {
    if (x < 0) {
        write(fw, '-');
        x = -x;
    }
    x += pow(10, -precision) / 2;

    write_long(fw, (long) x);
    write(fw, '.');
    x -= (long) x;
    for (int i = 0; i < precision; i++) {
        x *= 10;
        write(fw, '0' + (int) x);
        x -= (int) x;
    }
    return fw;
}

FastWriter* writeln(FastWriter* fw) {
    return write(fw, '\n');
}

FastWriter* writeln_char(FastWriter* fw, char c) {
    return write(fw, c)->writeln(fw);
}

FastWriter* writeln_int(FastWriter* fw, int x) {
    return write_int(fw, x)->writeln(fw);
}

FastWriter* writeln_long(FastWriter* fw, long x) {
    return write_long(fw, x)->writeln(fw);
}

FastWriter* writeln_double(FastWriter* fw, double x, int precision) {
    return write_double(fw, x, precision)->writeln(fw);
}

FastWriter* write_ints(FastWriter* fw, int* xs, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            write(fw, ' ');
        }
        write_int(fw, xs[i]);
    }
    return fw;
}

FastWriter* write_longs(FastWriter* fw, long* xs, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            write(fw, ' ');
        }
        write_long(fw, xs[i]);
    }
    return fw;
}

FastWriter* writeln_ints(FastWriter* fw, int* xs, int n) {
    return write_ints(fw, xs, n)->writeln(fw);
}

FastWriter* writeln_longs(FastWriter* fw, long* xs, int n) {
    return write_longs(fw, xs, n)->writeln(fw);
}

FastWriter* writeln_str(FastWriter* fw, char* s) {
    return write_str(fw, s)->writeln(fw);
}

void innerflush(FastWriter* fw) {
    fwrite(fw->buf, sizeof(char), fw->ptr, fw->out);
    fw->ptr = 0;
}

void flush(FastWriter* fw) {
    innerflush(fw);
    fflush(fw->out);
}

void trnz(int* o, int n) {
    for (int i = 0; i < n; i++) {
        if (o[i] != 0) {
            printf("%d:%d ", i, o[i]);
        }
    }
    printf("\n");
}

void trt(long* o, int n) {
    for (int i = 0; i < n; i++) {
        long x = o[i];
        for (int j = 0; j < 64; j++) {
            printf("%d", x << ~j < 0 ? 1 : 0);
        }
        printf(" ");
    }
    printf("\n");
}

void tf(bool* r, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", r[i] ? 1 : 0);
    }
    printf("\n");
}

void tf2(bool** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", b[i][j] ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n");
}

void tf3(long** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long x = b[i][j];
            for (int k = 0; k < 64; k++) {
                printf("%d", x << ~k < 0 ? 1 : 0);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

void tf4(long* b, int n) {
    for (int i = 0; i < n; i++) {
        long x = b[i];
        for (int j = 0; j < 64; j++) {
            printf("%d", x << ~j < 0 ? 1 : 0);
        }
        printf(" ");
    }
    printf("\n");
}

void tr(int* o, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", o[i]);
    }
    printf("\n");
}

void tr2(int** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr3(long** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%ld ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr4(long* b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%ld ", b[i]);
    }
    printf("\n");
}

void tr_str(char** o, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", o[i]);
    }
    printf("\n");
}

void tr2_str(char*** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%s ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr3_str(char*** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%s ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr4_str(char** b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", b[i]);
    }
    printf("\n");
}

void tr_double(double* o, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", o[i]);
    }
    printf("\n");
}

void tr2_double(double** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr3_double(double** b, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%f ", b[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void tr4_double(double* b, int n) {
    for (int i = 0; i < n; i++) {
        printf("%f ", b[i]);
    }
    printf("\n");
}
