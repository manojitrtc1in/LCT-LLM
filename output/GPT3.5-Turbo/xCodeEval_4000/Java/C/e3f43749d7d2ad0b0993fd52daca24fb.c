#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RADIX 10
#define MOD 998244353
#define IMPOSSIBLE "IMPOSSIBLE"
#define POSSIBLE "POSSIBLE"
#define YES "YES"
#define NO "NO"

typedef struct {
    FILE* file;
    char* buffer;
    size_t buffer_size;
    char* buffer_pos;
    char* buffer_end;
} MyScanner;

typedef struct {
    FILE* file;
    char* buffer;
    size_t buffer_size;
    char* buffer_pos;
    char* buffer_end;
} MyPrintWriter;

void initIO(MyScanner* in, MyPrintWriter* out, int isFileIO) {
    if (isFileIO) {
        in->file = fopen("input.txt", "r");
        out->file = fopen("output.txt", "w");
    } else {
        in->file = stdin;
        out->file = stdout;
    }
    in->buffer_size = 1 << 16;
    in->buffer = (char*)malloc(in->buffer_size * sizeof(char));
    in->buffer_pos = in->buffer_end = in->buffer;
    out->buffer_size = 1 << 16;
    out->buffer = (char*)malloc(out->buffer_size * sizeof(char));
    out->buffer_pos = out->buffer;
}

void closeIO(MyScanner* in, MyPrintWriter* out) {
    fclose(in->file);
    fclose(out->file);
    free(in->buffer);
    free(out->buffer);
}

void readBuffer(MyScanner* in) {
    size_t count = fread(in->buffer, sizeof(char), in->buffer_size, in->file);
    in->buffer_pos = in->buffer;
    in->buffer_end = in->buffer + count;
}

char readChar(MyScanner* in) {
    if (in->buffer_pos >= in->buffer_end) {
        readBuffer(in);
    }
    return *(in->buffer_pos++);
}

int readInt(MyScanner* in) {
    char c = readChar(in);
    while (c < '0' || c > '9') {
        c = readChar(in);
    }
    int value = 0;
    while (c >= '0' && c <= '9') {
        value = value * 10 + (c - '0');
        c = readChar(in);
    }
    return value;
}

long long readLong(MyScanner* in) {
    char c = readChar(in);
    while (c < '0' || c > '9') {
        c = readChar(in);
    }
    long long value = 0;
    while (c >= '0' && c <= '9') {
        value = value * 10 + (c - '0');
        c = readChar(in);
    }
    return value;
}

double readDouble(MyScanner* in) {
    char c = readChar(in);
    while (c < '0' || c > '9') {
        c = readChar(in);
    }
    double value = 0;
    double decimal = 1;
    while (c >= '0' && c <= '9') {
        value = value * 10 + (c - '0');
        c = readChar(in);
    }
    if (c == '.') {
        c = readChar(in);
        while (c >= '0' && c <= '9') {
            decimal /= 10;
            value += (c - '0') * decimal;
            c = readChar(in);
        }
    }
    return value;
}

char* readLine(MyScanner* in) {
    char* line = (char*)malloc(1000 * sizeof(char));
    char c = readChar(in);
    int pos = 0;
    while (c != '\n') {
        line[pos++] = c;
        c = readChar(in);
    }
    line[pos] = '\0';
    return line;
}

void writeChar(MyPrintWriter* out, char c) {
    *(out->buffer_pos++) = c;
    if (out->buffer_pos >= out->buffer + out->buffer_size) {
        fwrite(out->buffer, sizeof(char), out->buffer_size, out->file);
        out->buffer_pos = out->buffer;
    }
}

void writeString(MyPrintWriter* out, char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        writeChar(out, str[i]);
    }
}

void writeInt(MyPrintWriter* out, int value) {
    char buffer[20];
    int pos = 0;
    if (value == 0) {
        writeChar(out, '0');
        return;
    }
    while (value > 0) {
        buffer[pos++] = (value % 10) + '0';
        value /= 10;
    }
    for (int i = pos - 1; i >= 0; i--) {
        writeChar(out, buffer[i]);
    }
}

void writeLong(MyPrintWriter* out, long long value) {
    char buffer[20];
    int pos = 0;
    if (value == 0) {
        writeChar(out, '0');
        return;
    }
    while (value > 0) {
        buffer[pos++] = (value % 10) + '0';
        value /= 10;
    }
    for (int i = pos - 1; i >= 0; i--) {
        writeChar(out, buffer[i]);
    }
}

void writeDouble(MyPrintWriter* out, double value, int precision) {
    long long integer = (long long)value;
    double decimal = value - integer;
    writeLong(out, integer);
    writeChar(out, '.');
    for (int i = 0; i < precision; i++) {
        decimal *= 10;
        int digit = (int)decimal;
        writeChar(out, digit + '0');
        decimal -= digit;
    }
}

void writeLine(MyPrintWriter* out, char* line) {
    int len = strlen(line);
    for (int i = 0; i < len; i++) {
        writeChar(out, line[i]);
    }
    writeChar(out, '\n');
}

void writeIntArray(MyPrintWriter* out, int* arr, int len) {
    for (int i = 0; i < len; i++) {
        writeInt(out, arr[i]);
        writeChar(out, ' ');
    }
    writeChar(out, '\n');
}

void writeLongArray(MyPrintWriter* out, long long* arr, int len) {
    for (int i = 0; i < len; i++) {
        writeLong(out, arr[i]);
        writeChar(out, ' ');
    }
    writeChar(out, '\n');
}

void writeDoubleArray(MyPrintWriter* out, double* arr, int len, int precision) {
    for (int i = 0; i < len; i++) {
        writeDouble(out, arr[i], precision);
        writeChar(out, ' ');
    }
    writeChar(out, '\n');
}

void writeStringArray(MyPrintWriter* out, char** arr, int len) {
    for (int i = 0; i < len; i++) {
        writeString(out, arr[i]);
        writeChar(out, ' ');
    }
    writeChar(out, '\n');
}

void writeCharMatrix(MyPrintWriter* out, char** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            writeChar(out, mat[i][j]);
            writeChar(out, ' ');
        }
        writeChar(out, '\n');
    }
}

void writeIntMatrix(MyPrintWriter* out, int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            writeInt(out, mat[i][j]);
            writeChar(out, ' ');
        }
        writeChar(out, '\n');
    }
}

void writeLongMatrix(MyPrintWriter* out, long long** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            writeLong(out, mat[i][j]);
            writeChar(out, ' ');
        }
        writeChar(out, '\n');
    }
}

void writeDoubleMatrix(MyPrintWriter* out, double** mat, int rows, int cols, int precision) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            writeDouble(out, mat[i][j], precision);
            writeChar(out, ' ');
        }
        writeChar(out, '\n');
    }
}

void validate(int* u, int* v, int n, MyPrintWriter* out) {
    int RADIX = 10;
    char cmp[RADIX][RADIX];
    for (int i = 0; i < RADIX; i++) {
        for (int j = 0; j < RADIX; j++) {
            cmp[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int small = u[i] < v[i] ? u[i] : v[i];
        int large = u[i] > v[i] ? u[i] : v[i];
        cmp[small][large] = -1;
        cmp[large][small] = 1;
    }

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    int cmpFunc(const void* a, const void* b) {
        int x = *(int*)a;
        int y = *(int*)b;
        return cmp[x][y];
    }

    long long curr = 0;
    long long limit = pow(RADIX, n);
    char* sb = (char*)malloc((n + 1) * sizeof(char));
    while (curr < limit) {
        sprintf(sb, "%0*lld", n, curr);
        qsort(arr, n, sizeof(int), cmpFunc);

        char* set = (char*)malloc((n + 1) * sizeof(char));
        for (int i = 0; i < n; i++) {
            set[i] = sb[arr[i]];
        }
        set[n] = '\0';

        writeString(out, set);
        writeChar(out, '\n');

        free(set);
        curr++;
    }

    free(sb);
    free(arr);
}

long long pow(int a, int k, long long p) {
    long long m = k;
    long long ans = 1;
    long long curr = a;
    while (m > 0) {
        if (m & 1) {
            ans *= curr;
            ans %= p;
        }
        m >>= 1;
        curr *= curr;
        curr %= p;
    }
    return ans;
}

long long inverse(int a, long long p) {
    return pow(a, p - 2, p);
}

long long solve(int* u, int* v, int n) {
    int RADIX = 10;
    int m = n;
    long long dp[1 << RADIX];
    for (int j = 0; j < RADIX; j++) {
        dp[1 << j] = 1;
    }

    char cmp[RADIX][RADIX];
    for (int i = 0; i < RADIX; i++) {
        for (int j = 0; j < RADIX; j++) {
            cmp[i][j] = 1;
        }
    }
    for (int i = 0; i < m; i++) {
        int small = u[i] < v[i] ? u[i] : v[i];
        int larger = u[i] > v[i] ? u[i] : v[i];
        cmp[small][larger] = 0;
    }

    bool isValid[1 << RADIX][RADIX];
    int map[1 << RADIX][RADIX];

    for (int mask = 0; mask < (1 << RADIX); mask++) {
        for (int j = 0; j < RADIX; j++) {
            bool ok = true;
            int next = 1 << j;
            for (int k = 0; k < RADIX; k++) {
                if ((1 << k & mask) == 0) {
                    continue;
                }
                if (cmp[j][k] == 0) {
                } else if (cmp[j][k] == -1) {
                    next |= 1 << k;
                } else {
                    ok = false;
                }
            }
            isValid[mask][j] = ok;
            map[mask][j] = next;
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        long long next[1 << RADIX];
        for (int mask = 0; mask < (1 << RADIX); mask++) {
            for (int j = 0; j < RADIX; j++) {
                if (!isValid[mask][j]) {
                    continue;
                }
                int mask2 = map[mask][j];
                long long val = next[mask2] + dp[mask];
                next[mask2] = val < MOD ? val : val - MOD;
            }
        }
        memcpy(dp, next, sizeof(next));
    }

    long long sum = 0;
    for (int mask = 0; mask < (1 << RADIX); mask++) {
        sum += dp[mask];
    }

    return sum % MOD;
}

void run() {
    int isDebug = 0;
    int isFileIO = 1;
    int hasMultipleTests = 0;

    MyScanner in;
    MyPrintWriter out;
    initIO(&in, &out, isFileIO);

    int t = hasMultipleTests ? readInt(&in) : 1;

    for (int i = 1; i <= t; ++i) {
        int n = readInt(&in);
        int m = readInt(&in);
        int* uv[2];
        uv[0] = (int*)malloc(m * sizeof(int));
        uv[1] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            uv[0][j] = readInt(&in);
            uv[1][j] = readInt(&in);
        }

        if (isDebug) {
            writeString(&out, "Test ");
            writeInt(&out, i);
            writeChar(&out, '\n');
        }

        long long ans = solve(uv[0], uv[1], n);
        writeLong(&out, ans);
        writeChar(&out, '\n');

        if (isDebug) {
            fflush(out.file);
        }

        free(uv[0]);
        free(uv[1]);
    }

    closeIO(&in, &out);
}

int main() {
    run();
    return 0;
}
