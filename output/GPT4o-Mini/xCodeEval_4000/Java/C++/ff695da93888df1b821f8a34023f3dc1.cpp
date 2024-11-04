#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <map>

using namespace std;

class Reader {
public:
    Reader() {
        cin.tie(nullptr);
        ios::sync_with_stdio(false);
    }

    string readLine() {
        string line;
        getline(cin, line);
        return line;
    }

    int nextInt() {
        int ret;
        cin >> ret;
        return ret;
    }

    long long nextLong() {
        long long ret;
        cin >> ret;
        return ret;
    }

    double nextDouble() {
        double ret;
        cin >> ret;
        return ret;
    }
};

class DSU {
    vector<int> parent, size;

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

class FastFourierTransform {
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

public:
    vector<long long> multiply(const vector<long long>& a, const vector<long long>& b) {
        int resultSize = 1 << (int)(ceil(log2(max(a.size(), b.size())))) + 1;
        vector<double> aReal(resultSize), aImaginary(resultSize);
        vector<double> bReal(resultSize), bImaginary(resultSize);
        for (size_t i = 0; i < a.size(); i++)
            aReal[i] = a[i];
        for (size_t i = 0; i < b.size(); i++)
            bReal[i] = b[i];
        fft(aReal, aImaginary, false);
        fft(bReal, bImaginary, false);
        for (int i = 0; i < resultSize; i++) {
            double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
            aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, aImaginary, true);
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

    vector<long long> primeFactorisation(long long n) {
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

    vector<int> sieveOfEratosthenes(int n) {
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
        long long d, x, y;
        Name(long long d, long long x, long long y) : d(d), x(x), y(y) {}
    };

    Name extendedEuclid(long long a, long long b) {
        if (b == 0)
            return Name(a, 1, 0);
        Name n1 = extendedEuclid(b, a % b);
        return Name(n1.d, n1.y, n1.x - (long long)floor((double)a / b) * n1.y);
    }

    long long modularExponentiation(long long a, long long b, long long n) {
        long long d = 1L;
        string bString = bitset<64>(b).to_string();
        for (char c : bString) {
            d = (d * d) % n;
            if (c == '1')
                d = (d * a) % n;
        }
        return d;
    }
};

class SuffixArray {
    static const int ALPHABET_SZ = 256;
    int N;
    vector<int> T, lcp, sa, sa2, rank, tmp, c;

    static vector<int> toIntArray(const string& s) {
        vector<int> text(s.length());
        for (size_t i = 0; i < s.length(); i++) text[i] = s[i];
        return text;
    }

    void construct() {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < ALPHABET_SZ; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1) {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            fill(c.begin(), c.begin() + ALPHABET_SZ, 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < ALPHABET_SZ; ++i) c[i] += c[i - 1];
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
            ALPHABET_SZ = r + 1;
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

public:
    SuffixArray(const string& str) : SuffixArray(toIntArray(str)) {}

    SuffixArray(const vector<int>& text) : T(text), N(text.size()), sa(N), sa2(N), rank(N), c(max(ALPHABET_SZ, N)) {
        construct();
        kasai();
    }
};

class ZAlgorithm {
public:
    vector<int> calculateZ(const vector<char>& input) {
        vector<int> Z(input.size());
        int left = 0, right = 0;
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

class KMPAlgorithm {
public:
    vector<int> computeTemporalArray(const vector<char>& pattern) {
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

    vector<int> KMPMatcher(const vector<char>& text, const vector<char>& pattern) {
        vector<int> lps = computeTemporalArray(pattern);
        int j = 0, i = 0;
        int n = text.size(), m = pattern.size();
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
    vector<long long> computePowers(long long p, int n, long long m) {
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
        vector<long long> powers = computePowers(p, s.length(), m);
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

class MergeSortInt {
public:
    void merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<int> L(n1), R(n2);
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

class MergeSortLong {
public:
    void merge(vector<long long>& arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        vector<long long> L(n1), R(n2);
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
    int x, y;

    Node(int x, int y) : x(x), y(y) {}

    bool operator==(const Node& obj) const {
        return x == obj.x && y == obj.y;
    }

    int hashCode() const {
        return x;
    }
};

class FenwickTree {
public:
    void update(vector<long long>& fenwickTree, long long delta, int index) {
        index += 1;
        while (index < fenwickTree.size()) {
            fenwickTree[index] += delta;
            index += (index & (-index));
        }
    }

    long long prefixSum(const vector<long long>& fenwickTree, int index) {
        long long sum = 0L;
        index += 1;
        while (index > 0) {
            sum += fenwickTree[index];
            index -= (index & (-index));
        }
        return sum;
    }
};

class SegmentTree {
public:
    int nextPowerOfTwo(int num) {
        if (num == 0) return 1;
        if (num > 0 && (num & (num - 1)) == 0) return num;
        while ((num & (num - 1)) > 0) {
            num = num & (num - 1);
        }
        return num << 1;
    }

    vector<int> createSegmentTree(const vector<int>& input) {
        int np2 = nextPowerOfTwo(input.size());
        vector<int> segmentTree(np2 * 2 - 1, INT_MIN);
        constructSegmentTree(segmentTree, input, 0, input.size() - 1, 0);
        return segmentTree;
    }

private:
    void constructSegmentTree(vector<int>& segmentTree, const vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        constructSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
        constructSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

public:
    int rangeMinimumQuery(const vector<int>& segmentTree, int qlow, int qhigh, int len) {
        return rangeMinimumQuery(segmentTree, 0, len - 1, qlow, qhigh, 0);
    }

private:
    int rangeMinimumQuery(const vector<int>& segmentTree, int low, int high, int qlow, int qhigh, int pos) {
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        if (qlow > high || qhigh < low) {
            return INT_MIN;
        }
        int mid = (low + high) / 2;
        return max(rangeMinimumQuery(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                   rangeMinimumQuery(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
};

class Trie {
private:
    struct TrieNode {
        map<char, TrieNode*> children;
        bool endOfWord;
        TrieNode() : endOfWord(false) {}
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
        current->endOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                return false;
            }
            current = current->children[ch];
        }
        return current->endOfWord;
    }

    void deleteWord(const string& word) {
        deleteWord(root, word, 0);
    }

private:
    bool deleteWord(TrieNode* current, const string& word, int index) {
        if (index == word.length()) {
            if (!current->endOfWord) {
                return false;
            }
            current->endOfWord = false;
            return current->children.empty();
        }
        char ch = word[index];
        if (current->children.find(ch) == current->children.end()) {
            return false;
        }
        bool shouldDeleteCurrentNode = deleteWord(current->children[ch], word, index + 1);
        if (shouldDeleteCurrentNode) {
            delete current->children[ch];
            current->children.erase(ch);
            return current->children.empty();
        }
        return false;
    }
};

class SegmentTreeLazy {
public:
    int nextPowerOfTwo(int num) {
        if (num == 0) return 1;
        if (num > 0 && (num & (num - 1)) == 0) return num;
        while ((num & (num - 1)) > 0) {
            num = num & (num - 1);
        }
        return num << 1;
    }

    vector<int> createSegmentTree(const vector<int>& input) {
        int nextPowOfTwo = nextPowerOfTwo(input.size());
        vector<int> segmentTree(nextPowOfTwo * 2 - 1, INT_MAX);
        constructMinSegmentTree(segmentTree, input, 0, input.size() - 1, 0);
        return segmentTree;
    }

private:
    void constructMinSegmentTree(vector<int>& segmentTree, const vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        constructMinSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
        constructMinSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

public:
    void updateSegmentTreeRangeLazy(vector<int>& input, vector<int>& segmentTree, vector<int>& lazy, int startRange, int endRange, int delta) {
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, 0, input.size() - 1, 0);
    }

private:
    void updateSegmentTreeRangeLazy(vector<int>& segmentTree, vector<int>& lazy, int startRange, int endRange, int delta, int low, int high, int pos) {
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
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, low, mid, 2 * pos + 1);
        updateSegmentTreeRangeLazy(segmentTree, lazy, startRange, endRange, delta, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = min(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

public:
    int rangeMinimumQueryLazy(const vector<int>& segmentTree, const vector<int>& lazy, int qlow, int qhigh, int len) {
        return rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

private:
    int rangeMinimumQueryLazy(const vector<int>& segmentTree, const vector<int>& lazy, int qlow, int qhigh, int low, int high, int pos) {
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
        return min(rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, low, mid, 2 * pos + 1),
                   rangeMinimumQueryLazy(segmentTree, lazy, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
};

class Main {
public:
    static void main() {
        Reader in;
        long long l = in.nextLong();
        long long r = in.nextLong();
        cout << giveAns(r) - giveAns(l - 1) << endl;
    }

    static long long giveAns(long long x) {
        int numOfDigits = to_string(x).length();
        long long ans = 0L;
        for (int i = 2; i < numOfDigits; i++)
            ans += 9L * (long long)pow(10, i - 2);
        if (numOfDigits > 1)
            ans += 9;
        if (numOfDigits == 1)
            ans += x;
        else {
            int firstDigit = to_string(x)[0] - '0';
            int lastDigit = to_string(x)[numOfDigits - 1] - '0';
            ans += (firstDigit - 1) * (long long)pow(10, numOfDigits - 2);
            string s = to_string(x);
            for (int j = 1; j < numOfDigits - 1; j++) {
                long long val = 1L;
                int digit = s[j] - '0';
                val *= (1L * digit * (long long)pow(10, numOfDigits - j - 2));
                ans += val;
            }
            if (firstDigit <= lastDigit)
                ans++;
        }
        return ans;
    }
};

int main() {
    Main::main();
    return 0;
}
