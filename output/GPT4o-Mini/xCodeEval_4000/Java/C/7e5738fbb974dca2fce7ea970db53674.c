#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void solve() {
    char s[100001];
    int n, k;
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    
    if (k == 0) {
        printf("%s\n", s);
        return;
    }
    
    char result[100001];
    int count = 0;
    
    if (s[0] != '1') {
        result[0] = '1';
        count++;
    } else {
        result[0] = '1';
    }
    
    for (int i = 1; i < n; i++) {
        if (count >= k) {
            strcat(result, s + i);
            break;
        } else {
            if (s[i] == '0') {
                result[i] = '0';
                continue;
            } else {
                result[i] = '0';
                count++;
            }
        }
    }
    printf("%s\n", result);
}

typedef struct {
    int *parent;
    int *size;
} DSU;

DSU* createDSU(int n) {
    DSU *dsu = (DSU *)malloc(sizeof(DSU));
    dsu->parent = (int *)malloc(n * sizeof(int));
    dsu->size = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = -1;
    }
    return dsu;
}

void makeSet(DSU *dsu, int v) {
    dsu->parent[v] = v;
    dsu->size[v] = 1;
}

int findSet(DSU *dsu, int v) {
    if (v == dsu->parent[v]) return v;
    return dsu->parent[v] = findSet(dsu, dsu->parent[v]);
}

void unionSets(DSU *dsu, int a, int b) {
    a = findSet(dsu, a);
    b = findSet(dsu, b);
    if (a != b) {
        if (dsu->size[a] < dsu->size[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        dsu->parent[b] = a;
        dsu->size[a] += dsu->size[b];
    }
}

void fft(double *a, double *b, int count, int invert) {
    for (int i = 1, j = 0; i < count; i++) {
        int bit = count >> 1;
        for (; j >= bit; bit >>= 1)
            j -= bit;
        j += bit;
        if (i < j) {
            double temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }
    for (int len = 2; len <= count; len <<= 1) {
        int halfLen = len >> 1;
        double angle = 2 * M_PI / len;
        if (invert)
            angle = -angle;
        double wLenA = cos(angle);
        double wLenB = sin(angle);
        for (int i = 0; i < count; i += len) {
            double wA = 1;
            double wB = 0;
            for (int j = 0; j < halfLen; j++) {
                double uA = a[i + j];
                double uB = b[i + j];
                double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                a[i + j] = uA + vA;
                b[i + j] = uB + vB;
                a[i + j + halfLen] = uA - vA;
                b[i + j + halfLen] = uB - vB;
                double nextWA = wA * wLenA - wB * wLenB;
                wB = wA * wLenB + wB * wLenA;
                wA = nextWA;
            }
        }
    }
    if (invert) {
        for (int i = 0; i < count; i++) {
            a[i] /= count;
            b[i] /= count;
        }
    }
}

long* multiply(long *a, long *b, int sizeA, int sizeB, int *resultSize) {
    int resultSizeTemp = 1 << (int)(ceil(log2(sizeA + sizeB - 1)));
    double *aReal = (double *)calloc(resultSizeTemp, sizeof(double));
    double *aImaginary = (double *)calloc(resultSizeTemp, sizeof(double));
    double *bReal = (double *)calloc(resultSizeTemp, sizeof(double));
    double *bImaginary = (double *)calloc(resultSizeTemp, sizeof(double));
    
    for (int i = 0; i < sizeA; i++)
        aReal[i] = a[i];
    for (int i = 0; i < sizeB; i++)
        bReal[i] = b[i];
    
    fft(aReal, aImaginary, resultSizeTemp, 0);
    fft(bReal, bImaginary, resultSizeTemp, 0);
    
    for (int i = 0; i < resultSizeTemp; i++) {
        double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
        aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
        aReal[i] = real;
    }
    
    fft(aReal, aImaginary, resultSizeTemp, 1);
    
    long *result = (long *)malloc(resultSizeTemp * sizeof(long));
    for (int i = 0; i < resultSizeTemp; i++)
        result[i] = round(aReal[i]);
    
    *resultSize = resultSizeTemp;
    free(aReal);
    free(aImaginary);
    free(bReal);
    free(bImaginary);
    
    return result;
}

int isPrime(long n) {
    if (n < 2) return 0;
    for (long x = 2; x * x <= n; x++) {
        if (n % x == 0) return 0;
    }
    return 1;
}

long* primeFactorisation(long n, int *size) {
    long *factors = (long *)malloc(100 * sizeof(long));
    *size = 0;
    for (long x = 2; x * x <= n; x++) {
        while (n % x == 0) {
            factors[(*size)++] = x;
            n /= x;
        }
    }
    if (n > 1) factors[(*size)++] = n;
    return factors;
}

int* sieveOfEratosthenes(int n) {
    int *sieve = (int *)calloc(n + 1, sizeof(int));
    for (int x = 2; x * x <= n; x++) {
        if (sieve[x] != 0) continue;
        for (int u = x * x; u <= n; u += x) {
            if (sieve[u] == 0) {
                sieve[u] = x;
            }
        }
    }
    return sieve;
}

long gcd(long a, long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long phi(long n) {
    double result = n;
    for (long p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result *= (1.0 - (1.0 / (double)p));
        }
    }
    if (n > 1)
        result *= (1.0 - (1.0 / (double)n));
    return (long)result;
}

typedef struct {
    long d;
    long x;
    long y;
} Name;

Name extendedEuclid(long a, long b) {
    if (b == 0) return (Name){a, 1, 0};
    Name n1 = extendedEuclid(b, a % b);
    return (Name){n1.d, n1.y, n1.x - (long)floor((double)a / b) * n1.y};
}

long modularExponentiation(long a, long b, long n) {
    long d = 1L;
    while (b > 0) {
        d = (d * d) % n;
        if (b % 2 == 1)
            d = (d * a) % n;
        b /= 2;
    }
    return d;
}

long* computePowers(long p, int n, long m) {
    long *powers = (long *)malloc(n * sizeof(long));
    powers[0] = 1;
    for (int i = 1; i < n; i++) {
        powers[i] = (powers[i - 1] * p) % m;
    }
    return powers;
}

long computeHash(char *s) {
    long p = 31;
    long m = 1_000_000_009;
    long hashValue = 0L;
    long *powers = computePowers(p, strlen(s), m);
    for (int i = 0; i < strlen(s); i++) {
        char ch = s[i];
        hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
    }
    free(powers);
    return hashValue;
}

long min(long *A, int size) {
    long minVal = LONG_MAX;
    for (int i = 0; i < size; i++) {
        minVal = fmin(minVal, A[i]);
    }
    return minVal;
}

long max(long *A, int size) {
    long maxVal = LONG_MIN;
    for (int i = 0; i < size; i++) {
        maxVal = fmax(maxVal, A[i]);
    }
    return maxVal;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void mergeLong(long arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    long *L = (long *)malloc(n1 * sizeof(long));
    long *R = (long *)malloc(n2 * sizeof(long));
    
    for (int i = 0; i < n1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSortLong(long arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSortLong(arr, l, m);
        mergeSortLong(arr, m + 1, r);
        mergeLong(arr, l, m, r);
    }
}

typedef struct {
    char *s;
} Node;

Node* createNode(char *s) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->s = strdup(s);
    return node;
}

int nodeEquals(Node *a, Node *b) {
    if (a == NULL || b == NULL) return 0;
    return strcmp(a->s, b->s) == 0;
}

int nodeHashCode(Node *node) {
    return (int)strlen(node->s);
}

typedef struct {
    char *buffer;
    int bufferSize;
    int bufferPointer;
    int bytesRead;
    FILE *file;
} Reader;

Reader* createReader() {
    Reader *reader = (Reader *)malloc(sizeof(Reader));
    reader->bufferSize = 1 << 16;
    reader->buffer = (char *)malloc(reader->bufferSize);
    reader->bufferPointer = 0;
    reader->bytesRead = 0;
    reader->file = stdin;
    return reader;
}

void closeReader(Reader *reader) {
    if (reader) {
        free(reader->buffer);
        free(reader);
    }
}

char read(Reader *reader) {
    if (reader->bufferPointer == reader->bytesRead) {
        reader->bytesRead = fread(reader->buffer, 1, reader->bufferSize, reader->file);
        reader->bufferPointer = 0;
    }
    return reader->bufferPointer < reader->bytesRead ? reader->buffer[reader->bufferPointer++] : EOF;
}

char* readLine(Reader *reader) {
    char *line = (char *)malloc(64);
    int cnt = 0;
    char c;
    while ((c = read(reader)) != EOF) {
        if (c == '\n') break;
        line[cnt++] = c;
    }
    line[cnt] = '\0';
    return line;
}

int nextInt(Reader *reader) {
    int ret = 0;
    char c = read(reader);
    while (c <= ' ') c = read(reader);
    int neg = (c == '-');
    if (neg) c = read(reader);
    do {
        ret = ret * 10 + c - '0';
    } while ((c = read(reader)) >= '0' && c <= '9');
    return neg ? -ret : ret;
}

long nextLong(Reader *reader) {
    long ret = 0;
    char c = read(reader);
    while (c <= ' ') c = read(reader);
    int neg = (c == '-');
    if (neg) c = read(reader);
    do {
        ret = ret * 10 + c - '0';
    } while ((c = read(reader)) >= '0' && c <= '9');
    return neg ? -ret : ret;
}

double nextDouble(Reader *reader) {
    double ret = 0, div = 1;
    char c = read(reader);
    while (c <= ' ') c = read(reader);
    int neg = (c == '-');
    if (neg) c = read(reader);
    do {
        ret = ret * 10 + c - '0';
    } while ((c = read(reader)) >= '0' && c <= '9');
    if (c == '.') {
        while ((c = read(reader)) >= '0' && c <= '9') {
            ret += (c - '0') / (div *= 10);
        }
    }
    return neg ? -ret : ret;
}

typedef struct {
    long *fenwickTree;
} FenwickTree;

FenwickTree* createFenwickTree(int size) {
    FenwickTree *fenwickTree = (FenwickTree *)malloc(sizeof(FenwickTree));
    fenwickTree->fenwickTree = (long *)calloc(size + 1, sizeof(long));
    return fenwickTree;
}

void updateFenwickTree(FenwickTree *fenwickTree, long delta, int index) {
    index += 1;
    while (index < sizeof(fenwickTree->fenwickTree) / sizeof(long)) {
        fenwickTree->fenwickTree[index] += delta;
        index += (index & (-index));
    }
}

long prefixSum(FenwickTree *fenwickTree, int index) {
    long sum = 0L;
    index += 1;
    while (index > 0) {
        sum += fenwickTree->fenwickTree[index];
        index -= (index & (-index));
    }
    return sum;
}

typedef struct {
    int *segmentTree;
} SegmentTree;

SegmentTree* createSegmentTree(int *input, int size) {
    SegmentTree *segmentTree = (SegmentTree *)malloc(sizeof(SegmentTree));
    int np2 = 1;
    while (np2 < size) np2 <<= 1;
    segmentTree->segmentTree = (int *)malloc(np2 * 2 * sizeof(int));
    for (int i = 0; i < np2 * 2; i++)
        segmentTree->segmentTree[i] = INT_MIN;
    constructSegmentTree(segmentTree->segmentTree, input, 0, size - 1, 0);
    return segmentTree;
}

void constructSegmentTree(int *segmentTree, int *input, int low, int high, int pos) {
    if (low == high) {
        segmentTree[pos] = input[low];
        return;
    }
    int mid = (low + high) / 2;
    constructSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
    constructSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
    segmentTree[pos] = fmax(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
}

int rangeMinimumQuery(SegmentTree *segmentTree, int qlow, int qhigh, int len) {
    return rangeMinimumQueryUtil(segmentTree->segmentTree, 0, len - 1, qlow, qhigh, 0);
}

int rangeMinimumQueryUtil(int *segmentTree, int low, int high, int qlow, int qhigh, int pos) {
    if (qlow <= low && qhigh >= high) {
        return segmentTree[pos];
    }
    if (qlow > high || qhigh < low) {
        return INT_MIN;
    }
    int mid = (low + high) / 2;
    return fmax(rangeMinimumQueryUtil(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                 rangeMinimumQueryUtil(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
}

typedef struct {
    struct TrieNode *children[256];
    int endOfWord;
} TrieNode;

typedef struct {
    TrieNode *root;
} Trie;

Trie* createTrie() {
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = (TrieNode *)calloc(1, sizeof(TrieNode));
    return trie;
}

void insert(Trie *trie, char *word) {
    TrieNode *current = trie->root;
    for (int i = 0; i < strlen(word); i++) {
        char ch = word[i];
        if (current->children[ch] == NULL) {
            current->children[ch] = (TrieNode *)calloc(1, sizeof(TrieNode));
        }
        current = current->children[ch];
    }
    current->endOfWord = 1;
}

int search(Trie *trie, char *word) {
    TrieNode *current = trie->root;
    for (int i = 0; i < strlen(word); i++) {
        char ch = word[i];
        if (current->children[ch] == NULL) {
            return 0;
        }
        current = current->children[ch];
    }
    return current->endOfWord;
}

int delete(TrieNode *current, char *word, int index) {
    if (index == strlen(word)) {
        if (!current->endOfWord) {
            return 0;
        }
        current->endOfWord = 0;
        return current->children[0] == NULL;
    }
    char ch = word[index];
    if (current->children[ch] == NULL) {
        return 0;
    }
    int shouldDeleteCurrentNode = delete(current->children[ch], word, index + 1);
    if (shouldDeleteCurrentNode) {
        free(current->children[ch]);
        current->children[ch] = NULL;
        return current->children[0] == NULL;
    }
    return 0;
}

int main() {
    solve();
    return 0;
}
