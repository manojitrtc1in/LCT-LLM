#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <climits>
#include <functional>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class icpc {
public:
    static void main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans = "";

        if (k == 0) {
            cout << s << endl;
            return;
        }

        if (n == 1) {
            if (k >= 1) {
                ans += '0';
            } else {
                ans += s;
            }
        } else {
            int count = 0;
            if (s[0] != '1') {
                ans += '1';
                count++;
            } else {
                ans += '1';
            }
            for (int i = 1; i < n; i++) {
                if (count >= k) {
                    ans += s.substr(i);
                    break;
                } else {
                    if (s[i] == '0') {
                        ans += '0';
                        continue;
                    } else {
                        ans += '0';
                        count++;
                    }
                }
            }
        }

        cout << ans << endl;
    }
};

class DSU {
public:
    vector<int> parent;
    vector<int> size;

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
            for (; j >= bit; bit >>= 1) {
                j -= bit;
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

public:
    vector<long long> multiply(vector<long long>& a, vector<long long>& b) {
        int resultSize = 1 << (32 - __builtin_clz(max(a.size(), b.size()) - 1));
        vector<double> aReal(resultSize);
        vector<double> aImaginary(resultSize);
        vector<double> bReal(resultSize);
        vector<double> bImaginary(resultSize);
        for (int i = 0; i < a.size(); i++) {
            aReal[i] = a[i];
        }
        for (int i = 0; i < b.size(); i++) {
            bReal[i] = b[i];
        }
        fft(aReal, aImaginary, false);
        fft(bReal, bImaginary, false);
        for (int i = 0; i < resultSize; i++) {
            double real = aReal[i] * bReal[i] - aImaginary[i] * bImaginary[i];
            aImaginary[i] = aImaginary[i] * bReal[i] + bImaginary[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, aImaginary, true);
        vector<long long> result(resultSize);
        for (int i = 0; i < resultSize; i++) {
            result[i] = round(aReal[i]);
        }
        return result;
    }
};

class NumberTheory {
public:
    bool isPrime(long long n) {
        if (n < 2) {
            return false;
        }
        for (long long x = 2; x * x <= n; x++) {
            if (n % x == 0) {
                return false;
            }
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
        if (n > 1) {
            f.push_back(n);
        }
        return f;
    }

    vector<int> sieveOfEratosthenes(int n) {
        vector<int> sieve(n + 1);
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

    long long gcd(long long a, long long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    long long phi(long long n) {
        double result = n;

        for (long long p = 2; p * p <= n; p++) {
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
        return (long long)result;
    }

    pair<long long, pair<long long, long long>> extendedEuclid(long long a, long long b) {
        if (b == 0) {
            return make_pair(a, make_pair(1, 0));
        }
        pair<long long, pair<long long, long long>> p = extendedEuclid(b, a % b);
        return make_pair(p.first, make_pair(p.second.second, p.second.first - (a / b) * p.second.second));
    }

    long long modularExponentiation(long long a, long long b, long long n) {
        long long d = 1L;
        string bString = bitset<64>(b).to_string();
        for (int i = 0; i < bString.length(); i++) {
            d = (d * d) % n;
            if (bString[i] == '1') {
                d = (d * a) % n;
            }
        }
        return d;
    }
};

class SuffixArray {
private:
    int ALPHABET_SZ = 256;
    int N;
    vector<int> T, lcp, sa, sa2, rank, tmp, c;

    vector<int> toIntArray(string s) {
        vector<int> text(s.length());
        for (int i = 0; i < s.length(); i++) {
            text[i] = s[i];
        }
        return text;
    }

public:
    SuffixArray(string str) {
        this->T = toIntArray(str);
        this->N = str.length();
        this->sa.resize(N);
        this->sa2.resize(N);
        this->rank.resize(N);
        this->tmp.resize(N);
        this->c.resize(max(ALPHABET_SZ, N));
        construct();
        kasai();
    }

    void construct() {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < ALPHABET_SZ; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1) {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            fill(c.begin(), c.end(), 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < ALPHABET_SZ; ++i) c[i] += c[i - 1];
            for (i = N - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
            for (sa2[sa[0]] = r = 0, i = 1; i < N; ++i) {
                if (!(rank[sa[i - 1]] == rank[sa[i]] && sa[i - 1] + p < N && sa[i] + p < N && rank[sa[i - 1] + p] == rank[sa[i] + p])) {
                    r++;
                }
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
};

class ZAlgorithm {
public:
    vector<int> calculateZ(string input) {
        int n = input.length();
        vector<int> Z(n);
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

    vector<int> matchPattern(string text, string pattern) {
        string newString = pattern + "$" + text;
        int n = newString.length();
        vector<int> result;
        vector<int> Z = calculateZ(newString);
        for (int i = 0; i < Z.size(); i++) {
            if (Z[i] == pattern.length()) {
                result.push_back(i - pattern.length() - 1);
            }
        }
        return result;
    }
};

class KMPAlgorithm {
public:
    vector<int> computeTemporalArray(string pattern) {
        int n = pattern.length();
        vector<int> lps(n);

        int index = 0;
        for (int i = 1; i < n;) {
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

    vector<int> KMPMatcher(string text, string pattern) {
        vector<int> lps = computeTemporalArray(pattern);

        int j = 0;
        int i = 0;
        int n = text.length();
        int m = pattern.length();
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
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i = i + 1;
                }
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

    long long computeHash(string s) {
        long long p = 31;
        long long m = 1'000'000'009;
        long long hashValue = 0LL;
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
    long long min(vector<long long>& A) {
        long long minVal = LLONG_MAX;
        for (int i = 0; i < A.size(); i++) {
            minVal = min(minVal, A[i]);
        }
        return minVal;
    }

    long long max(vector<long long>& A) {
        long long maxVal = LLONG_MIN;
        for (int i = 0; i < A.size(); i++) {
            maxVal = max(maxVal, A[i]);
        }
        return maxVal;
    }
};

class MergeSortInt {
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

class MergeSortLong {
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
    string s;

    Node(string s) {
        this->s = s;
    }

    bool operator==(const Node& other) const {
        return this->s == other.s;
    }

    bool operator!=(const Node& other) const {
        return !(*this == other);
    }
};

class Trie {
private:
    class TrieNode {
    public:
        map<char, TrieNode*> children;
        bool endOfWord;

        TrieNode() {
            endOfWord = false;
        }
    };

    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            TrieNode* node = current->children[ch];
            if (node == nullptr) {
                node = new TrieNode();
                current->children[ch] = node;
            }
            current = node;
        }
        current->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            TrieNode* node = current->children[ch];
            if (node == nullptr) {
                return false;
            }
            current = node;
        }
        return current->endOfWord;
    }

    void remove(string word) {
        remove(root, word, 0);
    }

    bool remove(TrieNode* current, string word, int index) {
        if (index == word.length()) {
            if (!current->endOfWord) {
                return false;
            }
            current->endOfWord = false;
            return current->children.size() == 0;
        }
        char ch = word[index];
        TrieNode* node = current->children[ch];
        if (node == nullptr) {
            return false;
        }
        bool shouldDeleteCurrentNode = remove(node, word, index + 1);

        if (shouldDeleteCurrentNode) {
            current->children.erase(ch);
            return current->children.size() == 0;
        }
        return false;
    }
};

class FenwickTree {
public:
    void update(vector<long long>& fenwickTree, long long delta, int index) {
        index += 1;
        while (index < fenwickTree.size()) {
            fenwickTree[index] += delta;
            index = index + (index & (-index));
        }
    }

    long long prefixSum(vector<long long>& fenwickTree, int index) {
        long long sum = 0LL;
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

    vector<int> createSegmentTree(vector<int>& input) {
        int np2 = nextPowerOfTwo(input.size());
        vector<int> segmentTree(np2 * 2 - 1);

        for (int i = 0; i < segmentTree.size(); i++) {
            segmentTree[i] = INT_MIN;
        }

        constructSegmentTree(segmentTree, input, 0, input.size() - 1, 0);
        return segmentTree;
    }

    void constructSegmentTree(vector<int>& segmentTree, vector<int>& input, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high) / 2;
        constructSegmentTree(segmentTree, input, low, mid, 2 * pos + 1);
        constructSegmentTree(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = max(segmentTree[2 * pos + 1], segmentTree[2 * pos + 2]);
    }

    int rangeMinimumQuery(vector<int>& segmentTree, int qlow, int qhigh, int len) {
        return rangeMinimumQuery(segmentTree, qlow, qhigh, 0, len - 1, 0);
    }

    int rangeMinimumQuery(vector<int>& segmentTree, int qlow, int qhigh, int low, int high, int pos) {
        if (qlow > high || qhigh < low) {
            return INT_MIN;
        }
        if (qlow <= low && qhigh >= high) {
            return segmentTree[pos];
        }
        int mid = (low + high) / 2;
        return max(rangeMinimumQuery(segmentTree, qlow, qhigh, low, mid, 2 * pos + 1),
            rangeMinimumQuery(segmentTree, qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
};

int main() {
    icpc::main();
    return 0;
}
