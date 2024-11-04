#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

struct Reader {
    int buffer_size;
    char* buffer;
    int buffer_pointer;
    int bytes_read;
};

struct Reader* createReader() {
    struct Reader* reader = (struct Reader*)malloc(sizeof(struct Reader));
    reader->buffer_size = 1 << 16;
    reader->buffer = (char*)malloc(reader->buffer_size * sizeof(char));
    reader->buffer_pointer = 0;
    reader->bytes_read = 0;
    return reader;
}

void fillBuffer(struct Reader* reader) {
    reader->bytes_read = fread(reader->buffer, sizeof(char), reader->buffer_size, stdin);
    if (reader->bytes_read == 0) {
        reader->buffer[0] = -1;
    }
    reader->buffer_pointer = 0;
}

char readChar(struct Reader* reader) {
    if (reader->buffer_pointer == reader->bytes_read) {
        fillBuffer(reader);
    }
    return reader->buffer[reader->buffer_pointer++];
}

int readInt(struct Reader* reader) {
    int ret = 0;
    char c = readChar(reader);
    while (c <= ' ') {
        c = readChar(reader);
    }
    bool neg = (c == '-');
    if (neg) {
        c = readChar(reader);
    }
    do {
        ret = ret * 10 + c - '0';
        c = readChar(reader);
    } while (c >= '0' && c <= '9');
    if (neg) {
        return -ret;
    }
    return ret;
}

long readLong(struct Reader* reader) {
    long ret = 0;
    char c = readChar(reader);
    while (c <= ' ') {
        c = readChar(reader);
    }
    bool neg = (c == '-');
    if (neg) {
        c = readChar(reader);
    }
    do {
        ret = ret * 10 + c - '0';
        c = readChar(reader);
    } while (c >= '0' && c <= '9');
    if (neg) {
        return -ret;
    }
    return ret;
}

double readDouble(struct Reader* reader) {
    double ret = 0, div = 1;
    char c = readChar(reader);
    while (c <= ' ') {
        c = readChar(reader);
    }
    bool neg = (c == '-');
    if (neg) {
        c = readChar(reader);
    }
    do {
        ret = ret * 10 + c - '0';
        c = readChar(reader);
    } while (c >= '0' && c <= '9');
    if (c == '.') {
        c = readChar(reader);
        while (c >= '0' && c <= '9') {
            ret += (c - '0') / (div *= 10);
            c = readChar(reader);
        }
    }
    if (neg) {
        return -ret;
    }
    return ret;
}

void closeReader(struct Reader* reader) {
    free(reader->buffer);
    free(reader);
}

struct DSU {
    int* parent;
    int* size;
    int n;
};

struct DSU* createDSU(int n) {
    struct DSU* dsu = (struct DSU*)malloc(sizeof(struct DSU));
    dsu->parent = (int*)malloc(n * sizeof(int));
    dsu->size = (int*)malloc(n * sizeof(int));
    dsu->n = n;
    for (int i = 0; i < n; i++) {
        dsu->parent[i] = -1;
        dsu->size[i] = 1;
    }
    return dsu;
}

int findSet(struct DSU* dsu, int v) {
    if (v == dsu->parent[v]) {
        return v;
    }
    return dsu->parent[v] = findSet(dsu, dsu->parent[v]);
}

void unionSets(struct DSU* dsu, int a, int b) {
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

struct FastFourierTransform {
    void fft(double* a, double* b, bool invert, int count) {
        for (int i = 1, j = 0; i < count; i++) {
            int bit = count >> 1;
            while (j >= bit) {
                j -= bit;
                bit >>= 1;
            }
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
            if (invert) {
                angle = -angle;
            }
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

    long* multiply(long* a, long* b, int n) {
        int resultSize = pow(2, ceil(log2(n)) + 1);
        double* aReal = (double*)malloc(resultSize * sizeof(double));
        double* aImaginary = (double*)malloc(resultSize * sizeof(double));
        double* bReal = (double*)malloc(resultSize * sizeof(double));
        double* bImaginary = (double*)malloc(resultSize * sizeof(double));
        for (int i = 0; i < n; i++) {
            aReal[i] = a[i];
            aImaginary[i] = 0;
            bReal[i] = b[i];
            bImaginary[i] = 0;
        }
        for (int i = n; i < resultSize; i++) {
            aReal[i] = 0;
            aImaginary[i] = 0;
            bReal[i] = 0;
            bImaginary[i] = 0;
        }
        fft(aReal, aImaginary, false, resultSize);
        fft(bReal, bImaginary, false, resultSize);
        for (int i = 0; i < resultSize; i++) {
            double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
            aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, aImaginary, true, resultSize);
        long* result = (long*)malloc(resultSize * sizeof(long));
        for (int i = 0; i < resultSize; i++) {
            result[i] = round(aReal[i]);
        }
        return result;
    }
};

struct NumberTheory {
    bool isPrime(long n) {
        if (n < 2) {
            return false;
        }
        for (long x = 2; x * x <= n; x++) {
            if (n % x == 0) {
                return false;
            }
        }
        return true;
    }

    long* primeFactorisation(long n, int* size) {
        long* f = (long*)malloc(n * sizeof(long));
        int index = 0;
        for (long x = 2; x * x <= n; x++) {
            while (n % x == 0) {
                f[index++] = x;
                n /= x;
            }
        }
        if (n > 1) {
            f[index++] = n;
        }
        *size = index;
        return f;
    }

    int* sieveOfEratosthenes(int n) {
        int* sieve = (int*)malloc((n + 1) * sizeof(int));
        for (int i = 0; i <= n; i++) {
            sieve[i] = 0;
        }
        for (int x = 2; x * x <= n; x++) {
            if (sieve[x] != 0) {
                continue;
            }
            for (int u = x * x; u <= n; u += x) {
                if (sieve[u] == 0) {
                    sieve[u] = x;
                }
            }
        }
        return sieve;
    }

    long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long phi(long n) {
        double result = n;
        for (long p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0) {
                    n /= p;
                }
                result *= (1.0 - (1.0 / (double)p));
            }
        }
        if (n > 1) {
            result *= (1.0 - (1.0 / (double)n));
        }
        return (long)result;
    }

    long* extendedEuclid(long a, long b, long* d, long* x, long* y) {
        if (b == 0) {
            *d = a;
            *x = 1;
            *y = 0;
            return;
        }
        long d1, x1, y1;
        extendedEuclid(b, a % b, &d1, &x1, &y1);
        *d = d1;
        *x = y1;
        *y = x1 - floor((double)a / b) * y1;
    }

    long modularExponentiation(long a, long b, long n) {
        long d = 1;
        char* bString = (char*)malloc(65 * sizeof(char));
        sprintf(bString, "%ld", b);
        for (int i = 0; i < strlen(bString); i++) {
            d = (d * d) % n;
            if (bString[i] == '1') {
                d = (d * a) % n;
            }
        }
        return d;
    }
};

struct Name {
    long d;
    long x;
    long y;
};

struct Name* createName(long d, long x, long y) {
    struct Name* name = (struct Name*)malloc(sizeof(struct Name));
    name->d = d;
    name->x = x;
    name->y = y;
    return name;
}

struct SuffixArray {
    int ALPHABET_SZ;
    int N;
    int* T;
    int* lcp;
    int* sa;
    int* sa2;
    int* rank;
    int* tmp;
    int* c;
};

struct SuffixArray* createSuffixArray(char* str) {
    struct SuffixArray* suffixArray = (struct SuffixArray*)malloc(sizeof(struct SuffixArray));
    suffixArray->ALPHABET_SZ = 256;
    suffixArray->N = strlen(str);
    suffixArray->T = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->lcp = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->sa = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->sa2 = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->rank = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->tmp = (int*)malloc(suffixArray->N * sizeof(int));
    suffixArray->c = (int*)malloc((suffixArray->ALPHABET_SZ > suffixArray->N ? suffixArray->ALPHABET_SZ : suffixArray->N) * sizeof(int));
    for (int i = 0; i < suffixArray->N; i++) {
        suffixArray->T[i] = str[i];
    }
    constructSuffixArray(suffixArray);
    kasai(suffixArray);
    return suffixArray;
}

void constructSuffixArray(struct SuffixArray* suffixArray) {
    int i, p, r;
    for (i = 0; i < suffixArray->N; ++i) {
        suffixArray->c[suffixArray->rank[i] = suffixArray->T[i]]++;
    }
    for (i = 1; i < suffixArray->ALPHABET_SZ; ++i) {
        suffixArray->c[i] += suffixArray->c[i - 1];
    }
    for (i = suffixArray->N - 1; i >= 0; --i) {
        suffixArray->sa[--suffixArray->c[suffixArray->rank[i]]] = i;
    }
    for (p = 1; p < suffixArray->N; p <<= 1) {
        for (r = 0, i = suffixArray->N - p; i < suffixArray->N; ++i) {
            suffixArray->sa2[r++] = i;
        }
        for (i = 0; i < suffixArray->N; ++i) {
            if (suffixArray->sa[i] >= p) {
                suffixArray->sa2[r++] = suffixArray->sa[i] - p;
            }
        }
        memset(suffixArray->c, 0, suffixArray->ALPHABET_SZ * sizeof(int));
        for (i = 0; i < suffixArray->N; ++i) {
            suffixArray->c[suffixArray->rank[i]]++;
        }
        for (i = 1; i < suffixArray->ALPHABET_SZ; ++i) {
            suffixArray->c[i] += suffixArray->c[i - 1];
        }
        for (i = suffixArray->N - 1; i >= 0; --i) {
            suffixArray->sa[--suffixArray->c[suffixArray->rank[suffixArray->sa2[i]]]] = suffixArray->sa2[i];
        }
        suffixArray->tmp = suffixArray->rank;
        suffixArray->rank = suffixArray->sa2;
        suffixArray->sa2 = suffixArray->tmp;
        if (r == suffixArray->N - 1) {
            break;
        }
        suffixArray->ALPHABET_SZ = r + 1;
    }
}

void kasai(struct SuffixArray* suffixArray) {
    int* inv = (int*)malloc(suffixArray->N * sizeof(int));
    for (int i = 0; i < suffixArray->N; i++) {
        inv[suffixArray->sa[i]] = i;
    }
    for (int i = 0, len = 0; i < suffixArray->N; i++) {
        if (inv[i] > 0) {
            int k = suffixArray->sa[inv[i] - 1];
            while (i + len < suffixArray->N && k + len < suffixArray->N && suffixArray->T[i + len] == suffixArray->T[k + len]) {
                len++;
            }
            suffixArray->lcp[inv[i] - 1] = len;
            if (len > 0) {
                len--;
            }
        }
    }
}

struct ZAlgorithm {
    int* calculateZ(char* input) {
        int n = strlen(input);
        int* Z = (int*)malloc(n * sizeof(int));
        int left = 0;
        int right = 0;
        for (int k = 1; k < n; k++) {
            if (k > right) {
                left = right = k;
                while (right < n && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                int k1 = k - left;
                if (Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else {
                    left = k;
                    while (right < n && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }

    int* matchPattern(char* text, char* pattern, int* size) {
        int n = strlen(text);
        int m = strlen(pattern);
        char* newString = (char*)malloc((n + m + 1) * sizeof(char));
        int i = 0;
        for (int j = 0; j < m; j++) {
            newString[i++] = pattern[j];
        }
        newString[i++] = '$';
        for (int j = 0; j < n; j++) {
            newString[i++] = text[j];
        }
        int* result = (int*)malloc((n + m + 1) * sizeof(int));
        int* Z = calculateZ(newString);
        int index = 0;
        for (int j = 0; j < n + m + 1; j++) {
            if (Z[j] == m) {
                result[index++] = j - m - 1;
            }
        }
        *size = index;
        return result;
    }
};

struct KMPAlgorithm {
    int* computeTemporalArray(char* pattern) {
        int m = strlen(pattern);
        int* lps = (int*)malloc(m * sizeof(int));
        int index = 0;
        lps[0] = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[index]) {
                lps[i++] = ++index;
            } else {
                if (index != 0) {
                    index = lps[index - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
        return lps;
    }

    int* KMPMatcher(char* text, char* pattern, int* size) {
        int n = strlen(text);
        int m = strlen(pattern);
        int* lps = computeTemporalArray(pattern);
        int i = 0;
        int j = 0;
        int* indices = (int*)malloc(n * sizeof(int));
        int index = 0;
        while (i < n) {
            if (pattern[j] == text[i]) {
                j++;
                i++;
            }
            if (j == m) {
                indices[index++] = i - j;
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
            }
        }
        *size = index;
        return indices;
    }
};

struct Hashing {
    long* computePowers(long p, int n, long m) {
        long* powers = (long*)malloc(n * sizeof(long));
        powers[0] = 1;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * p) % m;
        }
        return powers;
    }

    long computeHash(char* s, long p, long m) {
        int n = strlen(s);
        long hashValue = 0;
        long* powers = computePowers(p, n, m);
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
        }
        return hashValue;
    }
};

struct BasicFunctions {
    long min(long* A, int size) {
        long min = __INT64_MAX__;
        for (int i = 0; i < size; i++) {
            if (A[i] < min) {
                min = A[i];
            }
        }
        return min;
    }

    long max(long* A, int size) {
        long max = __INT64_MIN__;
        for (int i = 0; i < size; i++) {
            if (A[i] > max) {
                max = A[i];
            }
        }
        return max;
    }
};

struct MergeSortInt {
    void merge(int arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = l;
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
    }

    void sort(int arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

struct MergeSortLong {
    void merge(long arr[], int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;
        long L[n1], R[n2];
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }
        int i = 0;
        int j = 0;
        int k = l;
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
    }

    void sort(long arr[], int l, int r) {
        if (l < r) {
            int m = l + (r - l) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

struct Node {
    int x;
    int y;
};

bool equals(struct Node* node1, struct Node* node2) {
    return node1->x == node2->x && node1->y == node2->y;
}

int hashCode(struct Node* node) {
    return node->x;
}

struct FenwickTree {
    void update(long* fenwickTree, long delta, int index) {
        index += 1;
        while (index < sizeof(fenwickTree) / sizeof(fenwickTree[0])) {
            fenwickTree[index] += delta;
            index = index + (index & (-index));
        }
    }

    long prefixSum(long* fenwickTree, int index) {
        long sum = 0;
        index += 1;
        while (index > 0) {
            sum += fenwickTree[index];
            index -= (index & (-index));
        }
        return sum;
    }
};

struct SegmentTree {
    int nextPowerOfTwo(int num) {
        if (num == 0) {
            return 1;
        }
        if (num > 0 && (num & (num - 1)) == 0) {
            return num;
        }
        while ((num &(num - 1)) > 0) {
            num = num & (num - 1);
        }
        return num << 1;
    }

    int* createSegmentTree(int* input, int size) {
        int np2 = nextPowerOfTwo(size);
        int* segmentTree = (int*)malloc((np2 * 2 - 1) * sizeof(int));
        for (int i = 0; i < np2 * 2 - 1; i++) {
            segmentTree[i] = INT_MIN;
        }
        constructSegmentTree(segmentTree, input, 0, size - 1, 0);
        return segmentTree;
    }

    void constructSegmentTree(int* segmentTree, int* input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        constructSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
        constructSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = fmax(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

    int rangeMinimumQuery(int* segmentTree, int qlow, int qhigh, int len) {
        return rangeMinimumQuery(segmentTree, qlow, qhigh, 0, len - 1, 0);
    }

    int rangeMinimumQuery(int* segmentTree, int qlow, int qhigh, int low, int high, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return INT_MIN;
        }
        int mid = (low + high) / 2;
        return fmax(rangeMinimumQuery(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1),
                    rangeMinimumQuery(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
};

struct TrieNode {
    struct TrieNode** children;
    bool endOfWord;
};

struct Trie {
    struct TrieNode* root;
};

struct TrieNode* createTrieNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->children = (struct TrieNode**)malloc(26 * sizeof(struct TrieNode*));
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    node->endOfWord = false;
    return node;
}

struct Trie* createTrie() {
    struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
    trie->root = createTrieNode();
    return trie;
}

void insert(struct Trie* trie, char* word) {
    struct TrieNode* current = trie->root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->endOfWord = true;
}

bool search(struct Trie* trie, char* word) {
    struct TrieNode* current = trie->root;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (current->children[index] == NULL) {
            return false;
        }
        current = current->children[index];
    }
    return current->endOfWord;
}

void delete(struct Trie* trie, char* word) {
    deleteUtil(trie->root, word, 0);
}

bool deleteUtil(struct TrieNode* current, char* word, int index) {
    if (index == strlen(word)) {
        if (!current->endOfWord) {
            return false;
        }
        current->endOfWord = false;
        return current->children == NULL;
    }
    int ch = word[index] - 'a';
    struct TrieNode* node = current->children[ch];
    if (node == NULL) {
        return false;
    }
    bool shouldDeleteCurrentNode = deleteUtil(node, word, index + 1);
    if (shouldDeleteCurrentNode) {
        free(current->children[ch]);
        current->children[ch] = NULL;
        return current->children == NULL;
    }
    return false;
}

int main() {
    struct Reader* in = createReader();

    long l = readLong(in);
    long r = readLong(in);
    printf("%ld\n", giveAns(r) - giveAns(l - 1));

    closeReader(in);
    return 0;
}

long giveAns(long x) {
    int numOfDigits = floor(log10(x)) + 1;
    long ans = 0;
    for (int i = 2; i < numOfDigits; i++) {
        ans += 9 * pow(10, i - 2);
    }
    if (numOfDigits > 1) {
        ans += 9;
    }
    if (numOfDigits == 1) {
        ans += x;
    } else {
        int firstDigit = x / pow(10, numOfDigits - 1);
        int lastDigit = x % 10;
        ans += (firstDigit - 1) * pow(10, numOfDigits - 2);
        char s[20];
        sprintf(s, "%ld", x);
        for (int j = 1; j < numOfDigits - 1; j++) {
            long val = 1;
            int digit = s[j] - '0';
            val *= (1 * digit * pow(10, numOfDigits - j - 2));
            ans += val;
        }
        if (firstDigit <= lastDigit) {
            ans++;
        }
    }
    return ans;
}
