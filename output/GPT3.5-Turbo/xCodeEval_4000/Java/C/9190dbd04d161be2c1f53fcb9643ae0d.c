#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INPUT_BUFFER_SIZE 1024
#define BUF_SIZE (1 << 13)
#define P 998244353
#define G 3

typedef struct {
    int* upper;
} DJSet;

typedef struct {
    char* buf;
    int ptr;
    FILE* file;
} FastWriter;

typedef struct {
    int** map;
    int n;
    int m;
} CharMap;

typedef struct {
    int** map;
    int n;
    int m;
} IntMap;

typedef struct {
    int* f;
    int* invf;
} FIF;

typedef struct {
    int* buf;
    int len;
    int ptr;
    FILE* file;
} InputStream;

void initInputStream(InputStream* stream, FILE* file) {
    stream->buf = (int*)malloc(INPUT_BUFFER_SIZE * sizeof(int));
    stream->len = 0;
    stream->ptr = 0;
    stream->file = file;
}

int readByte(InputStream* stream) {
    if (stream->len == -1) {
        return -1;
    }
    if (stream->ptr >= stream->len) {
        stream->ptr = 0;
        stream->len = fread(stream->buf, sizeof(int), INPUT_BUFFER_SIZE, stream->file);
        if (stream->len <= 0) {
            return -1;
        }
    }
    return stream->buf[stream->ptr++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip(InputStream* stream) {
    int b;
    while ((b = readByte(stream)) != -1 && isSpaceChar(b));
    return b;
}

double nd(InputStream* stream) {
    char* ns = (char*)malloc(BUF_SIZE * sizeof(char));
    int b = skip(stream);
    int p = 0;
    while (!isSpaceChar(b)) {
        ns[p++] = (char)b;
        b = readByte(stream);
    }
    ns[p] = '\0';
    double num = atof(ns);
    free(ns);
    return num;
}

char nc(InputStream* stream) {
    return (char)skip(stream);
}

char* ns(InputStream* stream) {
    int b = skip(stream);
    char* ns = (char*)malloc(BUF_SIZE * sizeof(char));
    int p = 0;
    while (!isSpaceChar(b)) {
        ns[p++] = (char)b;
        b = readByte(stream);
    }
    ns[p] = '\0';
    return ns;
}

char** nm(InputStream* stream, int n, int m) {
    char** map = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        map[i] = ns(stream);
    }
    return map;
}

int** nmi(InputStream* stream, int n, int m) {
    int** map = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        map[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            map[i][j] = ni(stream);
        }
    }
    return map;
}

int ni(InputStream* stream) {
    return (int)nl(stream);
}

long nl(InputStream* stream) {
    long num = 0;
    int b;
    bool minus = false;
    while ((b = readByte(stream)) != -1 && !((b >= '0' && b <= '9') || b == '-'));
    if (b == '-') {
        minus = true;
        b = readByte(stream);
    }
    while (true) {
        if (b >= '0' && b <= '9') {
            num = num * 10 + (b - '0');
        } else {
            return minus ? -num : num;
        }
        b = readByte(stream);
    }
}

void initFastWriter(FastWriter* writer, FILE* file) {
    writer->buf = (char*)malloc(BUF_SIZE * sizeof(char));
    writer->ptr = 0;
    writer->file = file;
}

void writeByte(FastWriter* writer, char b) {
    writer->buf[writer->ptr++] = b;
    if (writer->ptr == BUF_SIZE) {
        fwrite(writer->buf, sizeof(char), BUF_SIZE, writer->file);
        writer->ptr = 0;
    }
}

void writeChar(FastWriter* writer, char c) {
    writeByte(writer, c);
}

void writeString(FastWriter* writer, char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        writeByte(writer, s[i]);
    }
}

void writeInt(FastWriter* writer, int x) {
    char* str = (char*)malloc(BUF_SIZE * sizeof(char));
    int p = 0;
    if (x == 0) {
        str[p++] = '0';
    } else {
        if (x < 0) {
            writeByte(writer, '-');
            x = -x;
        }
        while (x > 0) {
            str[p++] = (char)((x % 10) + '0');
            x /= 10;
        }
    }
    for (int i = p - 1; i >= 0; i--) {
        writeByte(writer, str[i]);
    }
    free(str);
}

void writeLong(FastWriter* writer, long x) {
    char* str = (char*)malloc(BUF_SIZE * sizeof(char));
    int p = 0;
    if (x == 0) {
        str[p++] = '0';
    } else {
        if (x < 0) {
            writeByte(writer, '-');
            x = -x;
        }
        while (x > 0) {
            str[p++] = (char)((x % 10) + '0');
            x /= 10;
        }
    }
    for (int i = p - 1; i >= 0; i--) {
        writeByte(writer, str[i]);
    }
    free(str);
}

void writeDouble(FastWriter* writer, double x, int precision) {
    if (x < 0) {
        writeByte(writer, '-');
        x = -x;
    }
    x += pow(10, -precision) / 2;
    writeLong(writer, (long)x);
    writeByte(writer, '.');
    x -= (long)x;
    for (int i = 0; i < precision; i++) {
        x *= 10;
        writeByte(writer, (char)('0' + (int)x));
        x -= (int)x;
    }
}

void writeln(FastWriter* writer) {
    writeByte(writer, '\n');
}

void writelnChar(FastWriter* writer, char c) {
    writeChar(writer, c);
    writeln(writer);
}

void writelnInt(FastWriter* writer, int x) {
    writeInt(writer, x);
    writeln(writer);
}

void writelnLong(FastWriter* writer, long x) {
    writeLong(writer, x);
    writeln(writer);
}

void writelnDouble(FastWriter* writer, double x, int precision) {
    writeDouble(writer, x, precision);
    writeln(writer);
}

void writeIntArray(FastWriter* writer, int* xs, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            writeByte(writer, ' ');
        }
        writeInt(writer, xs[i]);
    }
}

void writeLongArray(FastWriter* writer, long* xs, int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            writeByte(writer, ' ');
        }
        writeLong(writer, xs[i]);
    }
}

void writelnIntArray(FastWriter* writer, int* xs, int n) {
    writeIntArray(writer, xs, n);
    writeln(writer);
}

void writelnLongArray(FastWriter* writer, long* xs, int n) {
    writeLongArray(writer, xs, n);
    writeln(writer);
}

void writelnCharArray(FastWriter* writer, char* line) {
    writeString(writer, line);
    writeln(writer);
}

void writelnCharMap(FastWriter* writer, CharMap* map) {
    for (int i = 0; i < map->n; i++) {
        writelnCharArray(writer, map->map[i]);
    }
}

void writelnIntMap(FastWriter* writer, IntMap* map) {
    for (int i = 0; i < map->n; i++) {
        writelnIntArray(writer, map->map[i], map->m);
    }
}

void writelnString(FastWriter* writer, char* s) {
    writeString(writer, s);
    writeln(writer);
}

void innerflush(FastWriter* writer) {
    fwrite(writer->buf, sizeof(char), writer->ptr, writer->file);
    writer->ptr = 0;
}

void flush(FastWriter* writer) {
    innerflush(writer);
    fflush(writer->file);
}

void initDJSet(DJSet* set, int n) {
    set->upper = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        set->upper[i] = -1;
    }
}

int root(DJSet* set, int x) {
    return set->upper[x] < 0 ? x : (set->upper[x] = root(set, set->upper[x]));
}

bool equiv(DJSet* set, int x, int y) {
    return root(set, x) == root(set, y);
}

bool unite(DJSet* set, int x, int y) {
    x = root(set, x);
    y = root(set, y);
    if (x != y) {
        if (set->upper[y] < set->upper[x]) {
            int d = x;
            x = y;
            y = d;
        }
        set->upper[x] += set->upper[y];
        set->upper[y] = x;
    }
    return x == y;
}

int count(DJSet* set) {
    int ct = 0;
    for (int i = 0; i < sizeof(set->upper) / sizeof(set->upper[0]); i++) {
        if (set->upper[i] < 0) {
            ct++;
        }
    }
    return ct;
}

int** toBucket(DJSet* set) {
    int n = sizeof(set->upper) / sizeof(set->upper[0]);
    int** ret = (int**)malloc(n * sizeof(int*));
    int* rp = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (set->upper[i] < 0) {
            ret[i] = (int*)malloc(-set->upper[i] * sizeof(int));
        }
    }
    for (int i = 0; i < n; i++) {
        int r = root(set, i);
        ret[r][rp[r]++] = i;
    }
    return ret;
}

void initFIF(FIF* fif, int n) {
    fif->f = (int*)malloc((n + 1) * sizeof(int));
    fif->invf = (int*)malloc((n + 1) * sizeof(int));
    fif->f[0] = 1;
    for (int i = 1; i <= n; i++) {
        fif->f[i] = (int)((long)fif->f[i - 1] * i % P);
    }
    long a = fif->f[n];
    long b = P;
    long p = 1;
    long q = 0;
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
    fif->invf[n] = (int)(p < 0 ? p + P : p);
    for (int i = n - 1; i >= 0; i--) {
        fif->invf[i] = (int)((long)fif->invf[i + 1] * (i + 1) % P);
    }
}

long C(FIF* fif, int n, int r) {
    if (n < 0 || r < 0 || r > n) {
        return 0;
    }
    return (long)fif->f[n] * fif->invf[r] % P * fif->invf[n - r] % P;
}

long pow(long a, long n) {
    long ret = 1;
    int x = 63 - __builtin_clzll(n);
    for (; x >= 0; x--) {
        ret = ret * ret % P;
        if (n << ~x < 0) {
            ret = ret * a % P;
        }
    }
    return ret;
}

typedef struct {
    long* wps;
} NTTStockham998244353;

void initNTTStockham998244353(NTTStockham998244353* ntt) {
    ntt->wps = (long*)malloc(300 * sizeof(long));
    long unit = pow(G, (P - 1) / 300);
    ntt->wps[0] = 1;
    for (int p = 1; p < 300; p++) {
        ntt->wps[p] = ntt->wps[p - 1] * unit % P;
    }
}

void fft(NTTStockham998244353* ntt, long* X, long* Y) {
    int s = 1;
    bool eo = false;
    for (int n = sizeof(X) / sizeof(X[0]); n >= 4; n /= 2) {
        int m = n / 2;
        for (int p = 0; p < m; p++) {
            long wp = ntt->wps[s * p];
            long wk = (wp << 32) / P;
            for (int q = 0; q < s; q++) {
                long a = X[q + s * (p + 0)];
                long b = X[q + s * (p + m)];
                long ndsts = a + b;
                if (ndsts >= 2 * P) {
                    ndsts -= 2 * P;
                }
                long T = a - b + 2 * P;
                long Q = wk * T >> 32;
                Y[q + s * (2 * p + 0)] = ndsts;
                Y[q + s * (2 * p + 1)] = wp * T - Q * P & ((1L << 32) - 1);
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
        z[q + 0] = (a + b) % P;
        z[q + s] = (a - b + 2 * P) % P;
    }
}

long* go(NTTStockham998244353* ntt, long* src, int n, bool inverse) {
    long* dst = (long*)malloc(n * sizeof(long));
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
    fft(ntt, dst, (long*)malloc(n * sizeof(long)));
    if (inverse) {
        long in = pow(n, P - 2);
        for (int i = 0; i < n; i++) {
            dst[i] = dst[i] * in % P;
        }
    }
    return dst;
}

long* convolve(NTTStockham998244353* ntt, long* a, long* b) {
    int m = 2;
    while (m < sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]) - 1) {
        m *= 2;
    }
    long* fa = go(ntt, a, m, false);
    long* fb = a == b ? fa : go(ntt, b, m, false);
    for (int i = 0; i < m; i++) {
        fa[i] = fa[i] * fb[i] % P;
    }
    fa = go(ntt, fa, m, true);
    for (int i = 1, j = m - 1; i < j; i++, j--) {
        long d = fa[i];
        fa[i] = fa[j];
        fa[j] = d;
    }
    return fa;
}

long* mul(NTTStockham998244353* ntt, long* a, long* b, int lim) {
    int m = 2;
    while (m < sizeof(a) / sizeof(a[0]) + sizeof(b) / sizeof(b[0]) - 1) {
        m *= 2;
    }
    long* fa = go(ntt, a, m, false);
    long* fb = a == b ? fa : go(ntt, b, m, false);
    for (int i = 0; i < m; i++) {
        fa[i] = fa[i] * fb[i] % P;
    }
    fa = go(ntt, fa, m, true);
    for (int i = 1, j = m - 1; i < j; i++, j--) {
        long d = fa[i];
        fa[i] = fa[j];
        fa[j] = d;
    }
    return fa;
}

long* mulnaive(long* a, long* b) {
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    long* c = (long*)malloc((n + m - 1) * sizeof(long));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= ((long)1 << 63)) {
                c[i + j] -= ((long)1 << 63);
            }
        }
    }
    for (int i = 0; i < n + m - 1; i++) {
        c[i] %= P;
    }
    return c;
}

long* mulnaiveLim(long* a, long* b, int lim) {
    int n = sizeof(a) / sizeof(a[0]);
    int m = sizeof(b) / sizeof(b[0]);
    long* c = (long*)malloc(lim * sizeof(long));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m && i + j < lim; j++) {
            c[i + j] += a[i] * b[j];
            if (c[i + j] >= ((long)1 << 63)) {
                c[i + j] -= ((long)1 << 63);
            }
        }
    }
    for (int i = 0; i < lim; i++) {
        c[i] %= P;
    }
    return c;
}

void solve(InputStream* stream, FastWriter* writer) {
    int n = ni(stream);
    bool** g = (bool**)malloc(10 * sizeof(bool*));
    for (int i = 0; i < 10; i++) {
        g[i] = (bool*)malloc(10 * sizeof(bool));
        for (int j = 0; j < 10; j++) {
            g[i][j] = false;
        }
    }
    int m = ni(stream);
    for (int i = 0; i < m; i++) {
        int x = ni(stream);
        int y = ni(stream);
        g[x][y] = g[y][x] = true;
    }
    for (int i = 0; i < 10; i++) {
        g[i][i] = true;
    }
    int** njs = (int**)malloc((1 << 9) * sizeof(int*));
    for (int j = 0; j < (1 << 9); j++) {
        njs[j] = (int*)malloc(10 * sizeof(int));
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
    long* dp = (long*)malloc((1 << 9) * sizeof(long));
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        long* ndp = (long*)malloc((1 << 9) * sizeof(long));
        for (int j = 0; j < (1 << 9); j++) {
            for (int k = 0; k < 10; k++) {
                if (j << ~k >= 0) {
                    int nj = njs[j][k];
                    ndp[nj] += dp[j];
                    if (ndp[nj] >= P) {
                        ndp[nj] -= P;
                    }
                }
            }
        }
        dp = ndp;
    }
    long ans = 0;
    for (int i = 0; i < (1 << 9); i++) {
        ans += dp[i];
    }
    ans %= P;
    writelnLong(writer, ans);
}

int main() {
    InputStream stream;
    FastWriter writer;
    initInputStream(&stream, stdin);
    initFastWriter(&writer, stdout);
    solve(&stream, &writer);
    flush(&writer);
    return 0;
}
