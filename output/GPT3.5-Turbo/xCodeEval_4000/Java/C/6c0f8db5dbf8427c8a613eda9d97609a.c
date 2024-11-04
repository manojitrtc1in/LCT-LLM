#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define INPUT_BUFFER_SIZE 1024
#define OUTPUT_BUFFER_SIZE 65536
#define MOD 998244353

typedef struct {
    char* buffer;
    int length;
    int pointer;
} FastWriter;

FastWriter* newFastWriter() {
    FastWriter* writer = (FastWriter*)malloc(sizeof(FastWriter));
    writer->buffer = (char*)malloc(OUTPUT_BUFFER_SIZE * sizeof(char));
    writer->length = OUTPUT_BUFFER_SIZE;
    writer->pointer = 0;
    return writer;
}

void writeChar(FastWriter* writer, char c) {
    writer->buffer[writer->pointer++] = c;
    if (writer->pointer == writer->length) {
        printf("%.*s", writer->length, writer->buffer);
        writer->pointer = 0;
    }
}

void writeString(FastWriter* writer, char* s) {
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        writeChar(writer, s[i]);
    }
}

void writeInt(FastWriter* writer, int x) {
    char buffer[12];
    int pointer = 0;
    if (x == 0) {
        writeChar(writer, '0');
        return;
    }
    if (x < 0) {
        writeChar(writer, '-');
        x = -x;
    }
    while (x > 0) {
        buffer[pointer++] = '0' + (x % 10);
        x /= 10;
    }
    for (int i = pointer - 1; i >= 0; i--) {
        writeChar(writer, buffer[i]);
    }
}

void writeLong(FastWriter* writer, long long x) {
    char buffer[21];
    int pointer = 0;
    if (x == 0) {
        writeChar(writer, '0');
        return;
    }
    if (x < 0) {
        writeChar(writer, '-');
        x = -x;
    }
    while (x > 0) {
        buffer[pointer++] = '0' + (x % 10);
        x /= 10;
    }
    for (int i = pointer - 1; i >= 0; i--) {
        writeChar(writer, buffer[i]);
    }
}

void writeDouble(FastWriter* writer, double x, int precision) {
    if (x < 0) {
        writeChar(writer, '-');
        x = -x;
    }
    x += pow(10, -precision) / 2;
    writeLong(writer, (long long)x);
    writeChar(writer, '.');
    x -= (long long)x;
    for (int i = 0; i < precision; i++) {
        x *= 10;
        writeChar(writer, '0' + (int)x);
        x -= (int)x;
    }
}

void writeln(FastWriter* writer) {
    writeChar(writer, '\n');
}

void flush(FastWriter* writer) {
    printf("%.*s", writer->pointer, writer->buffer);
    writer->pointer = 0;
}

int readByte() {
    static char buffer[INPUT_BUFFER_SIZE];
    static int length = 0;
    static int pointer = 0;
    if (pointer >= length) {
        length = fread(buffer, sizeof(char), INPUT_BUFFER_SIZE, stdin);
        pointer = 0;
        if (length == 0) {
            return -1;
        }
    }
    return buffer[pointer++];
}

bool isSpaceChar(int c) {
    return !(c >= 33 && c <= 126);
}

int skip() {
    int b;
    while ((b = readByte()) != -1 && isSpaceChar(b));
    return b;
}

double readDouble() {
    int b = skip();
    bool negative = false;
    if (b == '-') {
        negative = true;
        b = readByte();
    }
    double x = 0;
    while (b >= '0' && b <= '9') {
        x = x * 10 + (b - '0');
        b = readByte();
    }
    if (b == '.') {
        double decimal = 1;
        b = readByte();
        while (b >= '0' && b <= '9') {
            decimal /= 10;
            x += (b - '0') * decimal;
            b = readByte();
        }
    }
    return negative ? -x : x;
}

int readInt() {
    int b = skip();
    bool negative = false;
    if (b == '-') {
        negative = true;
        b = readByte();
    }
    int x = 0;
    while (b >= '0' && b <= '9') {
        x = x * 10 + (b - '0');
        b = readByte();
    }
    return negative ? -x : x;
}

long long readLong() {
    int b = skip();
    bool negative = false;
    if (b == '-') {
        negative = true;
        b = readByte();
    }
    long long x = 0;
    while (b >= '0' && b <= '9') {
        x = x * 10 + (b - '0');
        b = readByte();
    }
    return negative ? -x : x;
}

void solve() {
    int n = readInt();
    int a[26];
    for (int i = 0; i < 26; i++) {
        a[i] = readInt();
    }
    long long all = 26 * 26 * pow(25, n - 2, MOD) % MOD;

    long long dp[3][n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][1][0] = 1;
    dp[1][0][1] = 1;
    dp[2][0][0] = 1;
    for (int i = 0; i < n - 1; i++) {
        long long ndp[3][n + 1][n + 1];
        memset(ndp, 0, sizeof(ndp));
        if (i == (n + 1) / 2 - 1) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[0][j + 1][k] %= MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[1][j][k + 1] %= MOD;
                    }
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 24;
                    ndp[2][j][k] %= MOD;
                }
            }
        } else {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; j + k <= n; k++) {
                    if (j + 1 <= n) {
                        ndp[0][j + 1][k] += dp[1][j][k] + dp[2][j][k] * 24;
                        ndp[0][j + 1][k] %= MOD;
                    }
                    if (k + 1 <= n) {
                        ndp[1][j][k + 1] += dp[0][j][k] + dp[2][j][k] * 24;
                        ndp[1][j][k + 1] %= MOD;
                    }
                    ndp[2][j][k] += dp[0][j][k] + dp[1][j][k] + dp[2][j][k] * 23;
                    ndp[2][j][k] %= MOD;
                }
            }
        }
        memcpy(dp, ndp, sizeof(dp));
    }

    long long sdp[n + 1];
    memset(sdp, 0, sizeof(sdp));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            sdp[i] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j] * 24;
        }
        sdp[i] %= MOD;
    }

    for (int i = 0; i < 26; i++) {
        for (int k = a[i] + 1; k <= n; k++) {
            all -= sdp[k];
        }
    }

    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            for (int k = a[i] + 1; k <= n; k++) {
                for (int l = a[j] + 1; l + k <= n; l++) {
                    all += (dp[0][k][l] + dp[1][k][l] + dp[2][k][l] * 24);
                }
            }
            all %= MOD;
        }
    }
    all %= MOD;

    if (all < 0) {
        all += MOD;
    }

    FastWriter* out = newFastWriter();
    writeLong(out, all);
    writeln(out);
    flush(out);
    free(out->buffer);
    free(out);
}

int main() {
    solve();
    return 0;
}
