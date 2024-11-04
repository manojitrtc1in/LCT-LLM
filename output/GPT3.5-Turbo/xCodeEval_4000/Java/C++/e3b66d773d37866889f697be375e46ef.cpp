#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <bitset>
#include <deque>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> adj[100005];
long long mod;
int notmemo[100005][2];
int k;
int a[100005];
int b[100005];
int m;
char c[100005];

struct Pair {
    int x;
    int y;
    Pair(int a, int b) {
        x = a;
        y = b;
    }
    bool operator<(const Pair& o) const {
        if (x != o.x)
            return x < o.x;
        return y < o.y;
    }
};
Pair s1[100005];
int s[100005];
unordered_set<int> set1;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(notmemo, -1, sizeof(notmemo));
    cout << dp(0, 0) << endl;

    return 0;
}

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
    int isComposite[N + 1];
    memset(isComposite, 0, sizeof(isComposite));
    vector<int> primes;

    for (int i = 2; i <= N; ++i) {
        if (isComposite[i] == 0) {
            primes.push_back(i);
            if (1l * i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    isComposite[j] = 1;
                }
            }
        }
    }
}

set<int> factors;
vector<int> primeFactors(int N) {
    vector<int> factors;

    int idx = 0, p = primes[idx];

    while (1l * p * p <= N) {
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

string y;
int nomnom[100005];
long fac[100005];

struct book {
    int idx;
    long score;

    book(int i, long s) {
        idx = i;
        score = s;
    }

    bool operator<(const book& o) const {
        return score > o.score;
    }
};

struct library {
    int numofbooks;
    int signup;
    int shiprate;
    int idx;

    library(int a, int b, int c, int idx) {
        numofbooks = a;
        signup = b;
        shiprate = c;
        this->idx = idx;
    }

    bool operator<(const library& o) const {
        if (signup == o.signup) {
            return numofbooks > o.numofbooks;
        }
        return signup < o.signup;
    }
};

bool isOn(int S, int j) {
    return (S & (1 << j)) != 0;
}

bool f = true;

class SegmentTree {
    int N;
    int* array;
    int* sTree;
    int* lazy;

public:
    SegmentTree(int* in) {
        array = in;
        N = in.size() - 1;
        sTree = new int[N << 1];
        lazy = new int[N << 1];
    }

    void build(int node, int b, int e) {
        if (b == e)
            sTree[node] = array[b];
        else {
            int mid = b + e >> 1;
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
        if (i > e || j < b)
            return;
        if (b >= i && e <= j) {
            sTree[node] += (e - b + 1) * val;
            lazy[node] += val;
        } else {
            int mid = b + e >> 1;
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
        if (i > e || j < b)
            return 0;
        if (b >= i && e <= j)
            return sTree[node];
        int mid = b + e >> 1;

        int q1 = query(node << 1, b, mid, i, j);
        int q2 = query(node << 1 | 1, mid + 1, e, i, j);
        return max(q1, q2);
    }
};

int memo[100005];

class UnionFind {
    int* p;
    int* rank;
    int* setSize;
    int numSets;
    int* max;

public:
    UnionFind(int N) {
        p = new int[numSets = N];
        rank = new int[N];
        setSize = new int[N];
        for (int i = 0; i < N; i++) {
            p[i] = i;
            setSize[i] = 1;
        }
    }

    int findSet(int i) {
        return p[i] == i ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j))
            return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            p[y] = x;
            setSize[x] += setSize[y];
        } else {
            p[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }

    int numDisjointSets() {
        return numSets;
    }

    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }
};

class incpair {
    int a;
    long b;
    int idx;

public:
    incpair(int a, long dirg, int i) {
        this->a = a;
        b = dirg;
        idx = i;
    }

    bool operator<(const incpair& e) const {
        return b < e.b;
    }
};

class decpair {
    int a;
    long b;
    int idx;

public:
    decpair(int a, long dirg, int i) {
        this->a = a;
        b = dirg;
        idx = i;
    }

    bool operator<(const decpair& e) const {
        return e.b < b;
    }
};

long allpowers[100005];

class Quad {
    int u;
    int v;
    char state;
    int turns;

public:
    Quad(int i, int j, char c, int k) {
        u = i;
        v = j;
        state = c;
        turns = k;
    }

    bool operator<(const Quad& e) const {
        return turns < e.turns;
    }
};

long dirg[100005][100005];
Edge driver[100005];

int n;

class Edge {
public:
    int node;
    long cost;

    Edge(int a, long dirg) {
        node = a;
        cost = dirg;
    }

    bool operator<(const Edge& e) const {
        return cost < e.cost;
    }
};

long manhatandistance(long x, long x2, long y, long y2) {
    return abs(x - x2) + abs(y - y2);
}

long fib[100005];

long fib(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    if (fib[n] != -1) {
        return fib[n];
    } else
        return fib[n] = ((fib(n - 2) % mod + fib(n - 1) % mod) % mod);
}

class Point {
public:
    long x, y;

    Point(long counth, long counts) {
        x = counth;
        y = counts;
    }

    bool operator<(const Point& p) const {
        return p.y * 1l * x < p.x * 1l * y;
    }
};

long comb[100005][100005];

class Triple {
    int l;
    int r;
    long cost;
    int idx;

public:
    Triple(int a, int b, long l1, int l2) {
        l = a;
        r = b;
        cost = l1;
        idx = l2;
    }

    bool operator<(const Triple& x) const {
        if (l != x.l || idx == x.idx)
            return l < x.l;
        return -idx;
    }
};

set<long> primeFactors(long N) {
    set<long> factors;

    int idx = 0, p = primes[idx];

    while (p * p <= N) {
        while (N % p == 0) {
            factors.insert(p);
            N /= p;
        }
        if (primes.size() > idx + 1)
            p = primes[++idx];
        else
            break;
    }

    if (N != 1) {
        factors.insert(N);
    }

    return factors;
}

bool visited[100005];

bool FindAllElements(int n, int k) {
    int sum = k;
    int A[k];
    memset(A, 0, sizeof(A));
    fill(A, A + k, 1);

    for (int i = k - 1; i >= 0; --i) {
        while (sum + A[i] <= n) {
            sum += A[i];
            A[i] *= 2;
        }
    }
    if (sum == n) {
        return true;
    } else
        return false;
}

bool vis2[100005];

bool f2 = false;

long matMul(long a2[][], long b[][], int p, int q, int r) {
    long C[p][r];
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < r; ++j) {
            for (int k = 0; k < q; ++k) {
                C[i][j] = (C[i][j] + (a2[i][k] % mod * b[k][j] % mod)) % mod;
                C[i][j] %= mod;
            }
        }
    }
    return C;
}

int memo1[100005];

bool vis[100005];
set<int> set;

long modPow(long ways, long count, long mod) {
    ways %= mod;
    long res = 1;
    while (count > 0) {
        if ((count & 1) == 1)
            res = (res * ways) % mod;
        ways = (ways * ways) % mod;
        count >>= 1;
    }
    return res % mod;
}

long gcd(long ans, long b) {
    if (b == 0) {
        return ans;
    }
    return gcd(b, ans % b);
}

int isComposite[100005];
int valid[100005];

vector<int> primes;
vector<int> l1;

set<int> primus;

void sieveLinear(int N) {
    int lp[N + 1];
    memset(lp, 0, sizeof(lp));

    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            primus.insert(i);
            lp[i] = i;
        }
        int curLP = lp[i];
        for (int p : primus)
            if (p > curLP || p * i > N)
                break;
            else
                lp[p * i] = i;
    }
}

class Scanner {
    stringstream ss;
    string nextToken;
    bool hasNextToken;
    istream& in;

public:
    Scanner(istream& in) : in(in) {}

    string next() {
        if (hasNextToken) {
            hasNextToken = false;
            return nextToken;
        }
        ss.clear();
        string s;
        getline(in, s);
        ss.str(s);
        ss >> nextToken;
        return nextToken;
    }

    int nextInt() {
        if (hasNextToken) {
            hasNextToken = false;
            return stoi(nextToken);
        }
        ss.clear();
        string s;
        getline(in, s);
        ss.str(s);
        ss >> nextToken;
        return stoi(nextToken);
    }

    long long nextLong() {
        if (hasNextToken) {
            hasNextToken = false;
            return stoll(nextToken);
        }
        ss.clear();
        string s;
        getline(in, s);
        ss.str(s);
        ss >> nextToken;
        return stoll(nextToken);
    }

    double nextDouble() {
        if (hasNextToken) {
            hasNextToken = false;
            return stod(nextToken);
        }
        ss.clear();
        string s;
        getline(in, s);
        ss.str(s);
        ss >> nextToken;
        return stod(nextToken);
    }

    bool hasNext() {
        if (hasNextToken) {
            return true;
        }
        string s;
        getline(in, s);
        ss.clear();
        ss.str(s);
        ss >> nextToken;
        hasNextToken = true;
        return !in.eof();
    }
};

int main() {
    Scanner sc(cin);
    int n = sc.nextInt();
    int a[n];
    for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
    }
    int notmemo[n][2];
    memset(notmemo, -1, sizeof(notmemo));
    cout << dp(0, 0) << endl;

    return 0;
}
