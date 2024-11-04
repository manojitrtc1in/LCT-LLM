#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <fstream>
#include <limits>

using namespace std;

class Reader {
    const int BUFFER_SIZE = 1 << 16;
    ifstream din;
    char buffer[BUFFER_SIZE];
    int bufferPointer, bytesRead;

public:
    Reader() {
        din = ifstream();
        bufferPointer = bytesRead = 0;
    }

    Reader(const string& file_name) {
        din.open(file_name);
        bufferPointer = bytesRead = 0;
    }

    string readLine() {
        char buf[64];
        int cnt = 0;
        char c;
        while (din.get(c)) {
            if (c == '\n')
                break;
            buf[cnt++] = c;
        }
        return string(buf, cnt);
    }

    int nextInt() {
        int ret = 0;
        char c;
        while (din.get(c) && (c <= ' '));
        bool neg = (c == '-');
        if (neg)
            din.get(c);
        do {
            ret = ret * 10 + c - '0';
        } while (din.get(c) && (c >= '0' && c <= '9'));

        return neg ? -ret : ret;
    }

    long long nextLong() {
        long long ret = 0;
        char c;
        while (din.get(c) && (c <= ' '));
        bool neg = (c == '-');
        if (neg)
            din.get(c);
        do {
            ret = ret * 10 + c - '0';
        } while (din.get(c) && (c >= '0' && c <= '9'));
        return neg ? -ret : ret;
    }

    double nextDouble() {
        double ret = 0, div = 1;
        char c;
        while (din.get(c) && (c <= ' '));
        bool neg = (c == '-');
        if (neg)
            din.get(c);

        do {
            ret = ret * 10 + c - '0';
        } while (din.get(c) && (c >= '0' && c <= '9'));

        if (c == '.') {
            while (din.get(c) && (c >= '0' && c <= '9')) {
                ret += (c - '0') / (div *= 10);
            }
        }

        return neg ? -ret : ret;
    }

    void close() {
        if (din.is_open())
            din.close();
    }
};

class DSU {
    vector<int> parent;
    vector<int> size;

public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n);
        fill(parent.begin(), parent.end(), -1);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int findSet(int v) {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    void unionSets(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

class id18 {
private:
    void fft(vector<double>& a, vector<double>& b, bool invert) {
        int count = a.size();
        for (int i = 1, j = 0; i < count; i++) {
            int bit = count >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j) {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
        for (int len = 2; len <= count; len <<= 1) {
            int halfLen = len >> 1;
            double angle = 2 * M_PI / len;
            if (invert)
                angle = -angle;
            double id17 = cos(angle);
            double id2 = sin(angle);
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
                    double nextWA = wA * id17 - wB * id2;
                    wB = wA * id2 + wB * id17;
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

public:
    vector<long long> multiply(vector<long long>& a, vector<long long>& b) {
        int resultSize = 1;
        while (resultSize < max(a.size(), b.size())) resultSize <<= 1;
        resultSize <<= 1;
        vector<double> aReal(resultSize);
        vector<double> id10(resultSize);
        vector<double> bReal(resultSize);
        vector<double> id30(resultSize);
        for (int i = 0; i < a.size(); i++)
            aReal[i] = a[i];
        for (int i = 0; i < b.size(); i++)
            bReal[i] = b[i];
        fft(aReal, id10, false);
        fft(bReal, id30, false);
        for (int i = 0; i < resultSize; i++) {
            double real = aReal[i] * bReal[i] - id10[i] * id30[i];
            id10[i] = id10[i] * bReal[i] + id30[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, id10, true);
        vector<long long> result(resultSize);
        for (int i = 0; i < resultSize; i++)
            result[i] = round(aReal[i]);
        return result;
    }
};

class NumberTheory {
public:
    bool isPrime(long long n) {
        if (n < 2)
            return false;
        for (long long x = 2; x * x <= n; x++) {
            if (n % x == 0)
                return false;
        }
        return true;
    }

    vector<long long> id27(long long n) {
        vector<long long> f;
        for (long long x = 2; x * x <= n; x++) {
            while (n % x == 0) {
                f.push_back(x);
                n /= x;
            }
        }
        if (n > 1)
            f.push_back(n);
        return f;
    }

    vector<int> id19(int n) {
        vector<int> sieve(n + 1);
        for (int x = 2; x * x <= n; x++) {
            if (sieve[x] != 0)
                continue;
            for (int u = x * x; u <= n; u += x) {
                if (sieve[u] == 0) {
                    sieve[u] = x;
                }
            }
        }
        return sieve;
    }

    long long gcd(long long a, long long b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    long long phi(long long n) {
        double result = n;
        for (long long p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                while (n % p == 0)
                    n /= p;
                result *= (1.0 - (1.0 / (double)p));
            }
        }
        if (n > 1)
            result *= (1.0 - (1.0 / (double)n));
        return (long long)result;
    }

    struct Name {
        long long d;
        long long x;
        long long y;

        Name(long long d, long long x, long long y) : d(d), x(x), y(y) {}
    };

    Name id21(long long a, long long b) {
        if (b == 0)
            return Name(a, 1, 0);
        Name n1 = id21(b, a % b);
        return Name(n1.d, n1.y, n1.x - (long long)floor((double)a / b) * n1.y);
    }

    long long id22(long long a, long long b, long long n) {
        long long d = 1L;
        string bString = bitset<64>(b).to_string();
        for (int i = 0; i < bString.length(); i++) {
            d = (d * d) % n;
            if (bString[i] == '1')
                d = (d * a) % n;
        }
        return d;
    }
};

class SuffixArray {
    int id6 = 256, N;
    vector<int> T, lcp, sa, sa2, rank, tmp, c;

public:
    SuffixArray(const string& str) : SuffixArray(id12(str)) {}

private:
    static vector<int> id12(const string& s) {
        vector<int> text(s.length());
        for (int i = 0; i < s.length(); i++) text[i] = s[i];
        return text;
    }

public:
    SuffixArray(const vector<int>& text) : T(text), N(text.size()), sa(N), sa2(N), rank(N), c(max(id6, N)) {
        construct();
        kasai();
    }

private:
    void construct() {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < id6; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1) {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            fill(c.begin(), c.begin() + id6, 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < id6; ++i) c[i] += c[i - 1];
            for (i = N - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
            for (sa2[sa[0]] = r = 0, i = 1; i < N; ++i) {
                if (!(rank[sa[i - 1]] == rank[sa[i]]
                    && sa[i - 1] + p < N
                    && sa[i] + p < N
                    && rank[sa[i - 1] + p] == rank[sa[i] + p])) r++;
                sa2[sa[i]] = r;
            }
            tmp = rank;
            rank = sa2;
            sa2 = tmp;
            if (r == N - 1) break;
            id6 = r + 1;
        }
    }

    void kasai() {
        lcp.resize(N);
        vector<int> inv(N);
        for (int i = 0; i < N; i++) inv[sa[i]] = i;
        for (int i = 0, len = 0; i < N; i++) {
            if (inv[i] > 0) {
                int k = sa[inv[i] - 1];
                while ((i + len < N) && (k + len < N) && T[i + len] == T[k + len]) len++;
                lcp[inv[i] - 1] = len;
                if (len > 0) len--;
            }
        }
    }
};

class ZAlgorithm {
public:
    vector<int> calculateZ(const vector<char>& input) {
        vector<int> Z(input.size());
        int left = 0;
        int right = 0;
        for (int k = 1; k < input.size(); k++) {
            if (k > right) {
                left = right = k;
                while (right < input.size() && input[right] == input[right - left]) {
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
                    while (right < input.size() && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }

    vector<int> matchPattern(const vector<char>& text, const vector<char>& pattern) {
        vector<char> newString(text.size() + pattern.size() + 1);
        int i = 0;
        for (char ch : pattern) {
            newString[i++] = ch;
        }
        newString[i++] = '$';
        for (char ch : text) {
            newString[i++] = ch;
        }
        vector<int> result;
        vector<int> Z = calculateZ(newString);

        for (i = 0; i < Z.size(); i++) {
            if (Z[i] == pattern.size()) {
                result.push_back(i - pattern.size() - 1);
            }
        }
        return result;
    }
};

class id1 {
public:
    vector<int> id5(const vector<char>& pattern) {
        vector<int> lps(pattern.size());
        int index = 0;
        for (int i = 1; i < pattern.size();) {
            if (pattern[i] == pattern[index]) {
                lps[i] = index + 1;
                index++;
                i++;
            } else {
                if (index != 0) {
                    index = lps[index - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<int> id3(const vector<char>& text, const vector<char>& pattern) {
        vector<int> lps = id5(pattern);
        int j = 0;
        int i = 0;
        int n = text.size();
        int m = pattern.size();
        vector<int> indices;
        while (i < n) {
            if (pattern[j] == text[i]) {
                i++;
                j++;
            }
            if (j == m) {
                indices.push_back(i - j);
                j = lps[j - 1];
            } else if (i < n && pattern[j] != text[i]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return indices;
    }
};

class Hashing {
public:
    vector<long long> id8(long long p, int n, long long m) {
        vector<long long> powers(n);
        powers[0] = 1;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * p) % m;
        }
        return powers;
    }

    long long computeHash(const string& s) {
        long long p = 31;
        long long m = 1'000'000'009;
        long long hashValue = 0L;
        vector<long long> powers = id8(p, s.length(), m);
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
        }
        return hashValue;
    }
};

class BasicFunctions {
public:
    long long min(const vector<long long>& A) {
        return *min_element(A.begin(), A.end());
    }

    long long max(const vector<long long>& A) {
        return *max_element(A.begin(), A.end());
    }
};

class id26 {
public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1);
        vector<int> R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0;
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

    void sort(vector<int>& arr, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

class id7 {
public:
    void merge(vector<long long>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<long long> L(n1);
        vector<long long> R(n2);

        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];

        int i = 0, j = 0;
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

    void sort(vector<long long>& arr, int l, int r) {
        if (l < r) {
            int m = (l + r) / 2;
            sort(arr, l, m);
            sort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

class Node {
public:
    int x;
    int y;

    Node(int x, int y) : x(x), y(y) {}

    bool operator==(const Node& obj) const {
        return (this->x == obj.x && this->y == obj.y);
    }

    int hashCode() const {
        return (int)this->x;
    }
};

class id29 {
public:
    void update(vector<long long>& id25, long long delta, int index) {
        index += 1;
        while (index < id25.size()) {
            id25[index] += delta;
            index += (index & (-index));
        }
    }

    long long prefixSum(const vector<long long>& id25, int index) {
        long long sum = 0L;
        index += 1;
        while (index > 0) {
            sum += id25[index];
            index -= (index & (-index));
        }
        return sum;
    }
};

class SegmentTree {
public:
    int id24(int num) {
        if (num == 0)
            return 1;
        if (num > 0 && (num & (num - 1)) == 0)
            return num;
        while ((num & (num - 1)) > 0) {
            num = num & (num - 1);
        }
        return num << 1;
    }

    vector<int> id16(const vector<int>& input) {
        int np2 = id24(input.size());
        vector<int> segmentTree(np2 * 2 - 1, INT_MIN);
        id11(segmentTree, input, 0, input.size() - 1, 0);
        return segmentTree;
    }

private:
    void id11(vector<int>& segmentTree, const vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        id11(segmentTree, input, low, mid, 2 * pos + 1);
        id11(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

public:
    int id4(const vector<int>& segmentTree, int qlow, int qhigh, int len) {
        return id4(segmentTree, 0, len - 1, qlow, qhigh, 0);
    }

private:
    int id4(const vector<int>& segmentTree, int low, int high, int qlow, int qhigh, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return INT_MIN;
        }
        int mid = (low + high) / 2;
        return max(id4(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                   id4(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
};

class Trie {
private:
    class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool id13;

        TrieNode() : id13(false) {}
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
        }
        current->id13 = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->id13;
    }

    void deleteWord(const string& word) {
        delete(root, word, 0);
    }

private:
    bool delete(TrieNode* current, const string& word, int index) {
        if (index == word.length()) {
            if (!current->id13) {
                return false;
            }
            current->id13 = false;
            return current->children.empty();
        }
        char ch = word[index];
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        bool id14 = delete(current->children[ch], word, index + 1);

        if (id14) {
            current->children.erase(ch);
            return current->children.empty();
        }
        return false;
    }
};
