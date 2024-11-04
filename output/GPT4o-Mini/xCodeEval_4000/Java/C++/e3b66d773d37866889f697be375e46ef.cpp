#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <cstring>
#include <fstream>
#include <random>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

long mod;
int n, k, m;
int a[100005], notmemo[100005][2];
char c[100005];

class Pair {
public:
    int x, y;
    Pair(int a, int b) : x(a), y(b) {}
    bool operator<(const Pair& o) const {
        if (x != o.x) return x < o.x;
        return y < o.y;
    }
};

vector<Pair> s1;
vector<int> primes;
set<int> factors;

int dp(int idx, int state) {
    if (idx == n) {
        return 0;
    }
    if (notmemo[idx][state] != -1) {
        return notmemo[idx][state];
    }
    int take = 0, leave = 0, leaveall = 0;
    if (a[idx] == 1 && (state == 1 || state == 0)) {
        take = 1 + dp(idx + 1, 1);
    }
    if (a[idx] == 0 && state == 0) {
        leave = 1 + dp(idx + 1, state);
    }
    leaveall = dp(idx + 1, state);
    return notmemo[idx][state] = max(take, max(leaveall, leave));
}

void sieve(int N) {
    vector<int> isComposite(N + 1, 0);
    isComposite[0] = isComposite[1] = 1;
    for (int i = 2; i <= N; ++i) {
        if (isComposite[i] == 0) {
            primes.push_back(i);
            if (1LL * i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    isComposite[j] = 1;
                }
            }
        }
    }
}

vector<int> primeFactors(int N) {
    vector<int> factors;
    int idx = 0, p = primes[idx];
    while (1LL * p * p <= N) {
        while (N % p == 0) {
            factors.push_back(p);
            N /= p;
        }
        p = primes[++idx];
    }
    if (N != 1) {
        factors.push_back(N);
    }
    return factors;
}

class Book {
public:
    int idx;
    long score;
    Book(int i, long s) : idx(i), score(s) {}
    bool operator<(const Book& o) const {
        return score > o.score;
    }
};

class Library {
public:
    int numofbooks, signup, shiprate, idx;
    Library(int a, int b, int c, int idx) : numofbooks(a), signup(b), shiprate(c), idx(idx) {}
    bool operator<(const Library& o) const {
        if (signup == o.signup) {
            return numofbooks > o.numofbooks;
        }
        return signup < o.signup;
    }
};

class SegmentTree {
public:
    int N;
    vector<int> array, sTree, lazy;

    SegmentTree(vector<int>& in) : array(in), N(in.size() - 1), sTree(N << 1), lazy(N << 1) {}

    void build(int node, int b, int e) {
        if (b == e) {
            sTree[node] = array[b];
        } else {
            int mid = (b + e) >> 1;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
        }
    }

    void update_point(int index, int val) {
        index += N - 1;
        sTree[index] = val;
        while (index > 1) {
            index >>= 1;
            sTree[index] = max(sTree[index << 1], sTree[index << 1 | 1]);
        }
    }

    void update_range(int i, int j, int val) {
        update_range(1, 1, N, i, j, val);
    }

    void update_range(int node, int b, int e, int i, int j, int val) {
        if (i > e || j < b) return;
        if (b >= i && e <= j) {
            sTree[node] += (e - b + 1) * val;
            lazy[node] += val;
        } else {
            int mid = (b + e) >> 1;
            propagate(node, b, mid, e);
            update_range(node << 1, b, mid, i, j, val);
            update_range(node << 1 | 1, mid + 1, e, i, j, val);
            sTree[node] = sTree[node << 1] + sTree[node << 1 | 1];
        }
    }

    void propagate(int node, int b, int mid, int e) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
        sTree[node << 1] += (mid - b + 1) * lazy[node];
        sTree[node << 1 | 1] += (e - mid) * lazy[node];
        lazy[node] = 0;
    }

    int query(int i, int j) {
        return query(1, 1, N, i, j);
    }

    int query(int node, int b, int e, int i, int j) {
        if (i > e || j < b) return 0;
        if (b >= i && e <= j) return sTree[node];
        int mid = (b + e) >> 1;
        int q1 = query(node << 1, b, mid, i, j);
        int q2 = query(node << 1 | 1, mid + 1, e, i, j);
        return max(q1, q2);
    }
};

class UnionFind {
public:
    vector<int> p, rank, setSize;
    int numSets;

    UnionFind(int N) : p(N), rank(N), setSize(N, 1), numSets(N) {
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

class Point {
public:
    long x, y;
    Point(long counth, long counts) : x(counth), y(counts) {}
    bool operator<(const Point& p) const {
        return y * x < p.x * y;
    }
};

long gcd(long ans, long b) {
    return b == 0 ? ans : gcd(b, ans % b);
}

long modPow(long ways, long count, long mod) {
    ways %= mod;
    long res = 1;
    while (count > 0) {
        if ((count & 1) == 1) res = (res * ways) % mod;
        ways = (ways * ways) % mod;
        count >>= 1;
    }
    return res % mod;
}

class Scanner {
    stringstream ss;
public:
    Scanner(istream& is) {
        string str((istreambuf_iterator<char>(is)), istreambuf_iterator<char>());
        ss.str(str);
    }

    string next() {
        string s;
        ss >> s;
        return s;
    }

    int nextInt() {
        int x;
        ss >> x;
        return x;
    }

    long long nextLong() {
        long long x;
        ss >> x;
        return x;
    }

    double nextDouble() {
        double x;
        ss >> x;
        return x;
    }

    bool ready() {
        return !ss.eof();
    }
};

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(notmemo, -1, sizeof(notmemo));
    cout << dp(0, 0) << endl;
    return 0;
}
