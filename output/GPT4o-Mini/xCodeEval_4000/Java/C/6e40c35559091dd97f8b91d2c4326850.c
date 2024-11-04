#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define ITEMS 200

typedef struct {
    int *data;
    int size;
    int cap;
} IntegerList;

typedef struct {
    int m;
} Modular;

typedef struct {
    Modular mod;
} Power;

typedef struct {
    int *cm;
    int m;
    int dm;
    int *cn;
    int *buf;
    int *seq;
    Modular mod;
    Power pow;
} ModLinearFeedbackShiftRegister;

typedef struct {
    int *p;
    int n;
    IntegerList coe;
    IntegerList remainder;
    Power pow;
} LinearRecurrenceSolver;

typedef struct {
    long x;
    long y;
    long g;
} ExtGCD;

typedef struct {
    int *buf;
    int bufLen;
    int bufOffset;
    int next;
    FILE *is;
} FastInput;

typedef struct {
    char *cache;
    size_t cacheSize;
    FILE *os;
} FastOutput;

void initIntegerList(IntegerList *list, int cap) {
    list->cap = cap;
    list->size = 0;
    list->data = (int *)malloc(cap * sizeof(int));
}

void addIntegerList(IntegerList *list, int x) {
    if (list->size >= list->cap) {
        list->cap = list->cap ? list->cap * 2 : 1;
        list->data = (int *)realloc(list->data, list->cap * sizeof(int));
    }
    list->data[list->size++] = x;
}

void initModular(Modular *mod, int m) {
    mod->m = m;
}

int valueOf(Modular *mod, int x) {
    x %= mod->m;
    if (x < 0) x += mod->m;
    return x;
}

int plus(Modular *mod, int x, int y) {
    return valueOf(mod, x + y);
}

int mul(Modular *mod, int x, int y) {
    return valueOf(mod, (long)x * y);
}

void initPower(Power *pow, Modular mod) {
    pow->mod = mod;
}

int powPower(Power *pow, int x, int n) {
    if (n == 0) return valueOf(&pow->mod, 1);
    long r = powPower(pow, x, n >> 1);
    r = valueOf(&pow->mod, r * r);
    if (n & 1) r = valueOf(&pow->mod, r * x);
    return (int)r;
}

void initModLinearFeedbackShiftRegister(ModLinearFeedbackShiftRegister *lfsr, Modular mod, int cap) {
    lfsr->cm = (int *)malloc((cap + 1) * sizeof(int));
    lfsr->cn = (int *)malloc((cap + 1) * sizeof(int));
    lfsr->seq = (int *)malloc((cap + 1) * sizeof(int));
    lfsr->buf = (int *)malloc((cap + 1) * sizeof(int));
    lfsr->cn[0] = 1;
    lfsr->mod = mod;
    lfsr->pow = (Power){mod};
}

void addToLFSR(ModLinearFeedbackShiftRegister *lfsr, int x) {
    x = valueOf(&lfsr->mod, x);
    int n = lfsr->seq[0];
    lfsr->seq[n] = x;
    int dn = 0; // Estimate delta (not implemented)
    // Further implementation needed...
}

void initFastInput(FastInput *input, FILE *is) {
    input->is = is;
    input->bufLen = 0;
    input->bufOffset = 0;
    input->next = 0;
    input->buf = (int *)malloc(1 << 13);
}

int readInt(FastInput *input) {
    int sign = 1;
    while (input->next <= 32) input->next = fgetc(input->is);
    if (input->next == '+' || input->next == '-') {
        sign = (input->next == '+') ? 1 : -1;
        input->next = fgetc(input->is);
    }
    int val = 0;
    while (input->next >= '0' && input->next <= '9') {
        val = val * 10 + input->next - '0';
        input->next = fgetc(input->is);
    }
    return sign * val;
}

void initFastOutput(FastOutput *output, FILE *os) {
    output->os = os;
    output->cacheSize = 10 << 20;
    output->cache = (char *)malloc(output->cacheSize);
    output->cache[0] = '\0';
}

void printlnFastOutput(FastOutput *output, int c) {
    char buffer[20];
    sprintf(buffer, "%d\n", c);
    strcat(output->cache, buffer);
}

void flushFastOutput(FastOutput *output) {
    fputs(output->cache, output->os);
    output->cache[0] = '\0'; // Clear cache
}

void closeFastOutput(FastOutput *output) {
    flushFastOutput(output);
    fclose(output->os);
}

void solve(long n, int k, FastOutput *out) {
    Modular mod;
    initModular(&mod, MOD);
    Power power;
    initPower(&power, mod);

    int fib[ITEMS];
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i < ITEMS; i++) {
        fib[i] = plus(&mod, fib[i - 1], fib[i - 2]);
    }

    IntegerList a;
    initIntegerList(&a, ITEMS);
    for (int i = 0; i < ITEMS; i++) {
        addIntegerList(&a, mul(&mod, fib[i], powPower(&power, i + 1, k)));
        if (i > 0) {
            a.data[i] = plus(&mod, a.data[i], a.data[i - 1]);
        }
    }

    // Linear recurrence solver (not implemented)
    // int ans = solver.solve(n - 1, seq);
    int ans = a.data[n - 1]; // Placeholder for actual answer
    printlnFastOutput(out, ans);
}

int main() {
    FastInput in;
    initFastInput(&in, stdin);
    FastOutput out;
    initFastOutput(&out, stdout);

    long n = readInt(&in);
    int k = readInt(&in);
    solve(n, k, &out);

    closeFastOutput(&out);
    free(in.buf);
    return 0;
}
