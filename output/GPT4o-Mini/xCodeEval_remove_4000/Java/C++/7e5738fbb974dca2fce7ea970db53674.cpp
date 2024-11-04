#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <numeric>
#include <cstring>
#include <queue>
#include <set>
#include <cassert>
#include <functional>

using namespace std;

class icpc {
public:
    static void main() {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        stringstream stringBuilder;

        if (k == 0) {
            cout << s << endl;
            return;
        }
        if (n == 1) {
            if (k >= 1)
                stringBuilder << 0;
            else
                stringBuilder << s;
        } else {
            int count = 0;
            if (s[0] != '1') {
                stringBuilder << 1;
                count++;
            } else
                stringBuilder << 1;
            for (int i = 1; i < n; i++) {
                if (count >= k) {
                    stringBuilder << s.substr(i);
                    break;
                } else {
                    if (s[i] == '0') {
                        stringBuilder << 0;
                        continue;
                    } else {
                        stringBuilder << 0;
                        count++;
                    }
                }
            }
        }
        cout << stringBuilder.str() << endl;
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
        vector<double> aReal(resultSize), id10(resultSize), bReal(resultSize), id29(resultSize);
        for (int i = 0; i < a.size(); i++)
            aReal[i] = a[i];
        for (int i = 0; i < b.size(); i++)
            bReal[i] = b[i];
        fft(aReal, id10, false);
        fft(bReal, id29, false);
        for (int i = 0; i < resultSize; i++) {
            double real = aReal[i] * bReal[i] - id10[i] * id29[i];
            id10[i] = id10[i] * bReal[i] + id29[i] * aReal[i];
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
    bool isPrime(long n) {
        if (n < 2)
            return false;
        for (long x = 2; x * x <= n; x++) {
            if (n % x == 0)
                return false;
        }
        return true;
    }

    vector<long> id26(long n) {
        vector<long> f;
        for (long x = 2; x * x <= n; x++) {
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

    long gcd(long a, long b) {
        if (b == 0)
            return a;
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

    struct Name {
        long d;
        long x;
        long y;

        Name(long d, long x, long y) : d(d), x(x), y(y) {}
    };

    Name id21(long a, long b) {
        if (b == 0)
            return Name(a, 1, 0);
        Name n1 = id21(b, a % b);
        return Name(n1.d, n1.y, n1.x - (long)floor((double)a / b) * n1.y);
    }

    long id22(long a, long b, long n) {
        long d = 1L;
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

    static vector<int> id12(const string& s) {
        vector<int> text(s.length());
        for (int i = 0; i < s.length(); i++) text[i] = s[i];
        return text;
    }

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
                    i++;
            }
        }
        return indices;
    }
};

class Hashing {
public:
    vector<long> id8(long p, int n, long m) {
        vector<long> powers(n);
        powers[0] = 1;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * p) % m;
        }
        return powers;
    }

    long computeHash(const string& s) {
        long p = 31;
        long m = 1'000'000'009;
        long hashValue = 0L;
        vector<long> powers = id8(p, s.length(), m);
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
        }
        return hashValue;
    }
};

class BasicFunctions {
public:
    long min(const vector<long>& A) {
        return *min_element(A.begin(), A.end());
    }

    long max(const vector<long>& A) {
        return *max_element(A.begin(), A.end());
    }
};

class id25 {
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
    void merge(vector<long>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<long> L(n1);
        vector<long> R(n2);

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

    void sort(vector<long>& arr, int l, int r) {
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
    string s;
    Node(const string& s) : s(s) {}

    bool operator==(const Node& obj) const {
        return s == obj.s;
    }

    size_t hash() const {
        return s.length();
    }
};

class Reader {
private:
    const int BUFFER_SIZE = 1 << 16;
    ifstream din;
    vector<char> buffer;
    int bufferPointer, bytesRead;

public:
    Reader() : buffer(BUFFER_SIZE), bufferPointer(0), bytesRead(0) {
        din = cin;
    }

    Reader(const string& file_name) : buffer(BUFFER_SIZE), bufferPointer(0), bytesRead(0) {
        din.open(file_name);
    }

    string readLine() {
        string line;
        getline(din, line);
        return line;
    }

    int nextInt() {
        int ret;
        din >> ret;
        return ret;
    }

    long nextLong() {
        long ret;
        din >> ret;
        return ret;
    }

    double nextDouble() {
        double ret;
        din >> ret;
        return ret;
    }

    void close() {
        if (din.is_open())
            din.close();
    }
};

class id28 {
public:
    void update(vector<long>& id24, long delta, int index) {
        index += 1;
        while (index < id24.size()) {
            id24[index] += delta;
            index += (index & (-index));
        }
    }

    long prefixSum(const vector<long>& id24, int index) {
        long sum = 0L;
        index += 1;
        while (index > 0) {
            sum += id24[index];
            index -= (index & (-index));
        }
        return sum;
    }
};

class SegmentTree {
public:
    int id23(int num) {
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
        int np2 = id23(input.size());
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
        deleteWord(root, word, 0);
    }

private:
    bool deleteWord(TrieNode* current, const string& word, int index) {
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
        bool shouldDelete = deleteWord(current->children[ch], word, index + 1);
        if (shouldDelete) {
            delete current->children[ch];
            current->children.erase(ch);
            return current->children.empty();
        }
        return false;
    }
};

class id15 {
public:
    int id23(int num) {
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
        int id20 = id23(input.size());
        vector<int> segmentTree(id20 * 2 - 1, INT_MAX);
        for (int i = 0; i < segmentTree.size(); i++) {
            segmentTree[i] = INT_MAX;
        }
        id0(segmentTree, input, 0, input.size() - 1, 0);
        return segmentTree;
    }

private:
    void id0(vector<int>& segmentTree, const vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        id0(segmentTree, input, low, mid, 2 * pos + 1);
        id0(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

    void id9(const vector<int>& input, vector<int>& segmentTree, vector<int>& lazy, int startRange, int endRange, int delta) {
        id9(segmentTree, lazy, startRange, endRange, delta, 0, input.size() - 1, 0);
    }

private:
    void id9(vector<int>& segmentTree, vector<int>& lazy, int startRange, int endRange, int delta, int low, int high, int pos) {
        if (low > high) {
            return;
        }
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if (startRange > high || endRange < low) {
            return;
        }

        if (startRange <= low && endRange >= high) {
            segmentTree[pos] += delta;
            if (low != high) {
                lazy[2 * pos + 1] += delta;
                lazy[2 * pos + 2] += delta;
            }
            return;
        }

        int mid = (low + high) / 2;
        id9(segmentTree, lazy, startRange, endRange, delta, low, mid, 2 * pos + 1);
        id9(segmentTree, lazy, startRange, endRange, delta, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

    int id27(const vector<int>& segmentTree, const vector<int>& lazy, int qlow, int qhigh, int len) {
        return id27(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

private:
    int id27(const vector<int>& segmentTree, const vector<int>& lazy, int qlow, int qhigh, int low, int high, int pos) {
        if (low > high) {
            return INT_MAX;
        }
        if (lazy[pos] != 0) {
            segmentTree[pos] += lazy[pos];
            if (low != high) {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if (qlow > high || qhigh < low) {
            return INT_MAX;
        }

        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }

        int mid = (low + high) / 2;
        return min(id27(segmentTree, lazy, qlow, qhigh, low, mid, 2 * pos + 1), id27(segmentTree, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
};
