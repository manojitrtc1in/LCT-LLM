#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(pow(10, 9) + 7);
const int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
const int dx8[] = { -1, -1, -1, 0, 0, 1, 1, 1 }, dy8[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
const int dx9[] = { -1, -1, -1, 0, 0, 0, 1, 1, 1 }, dy9[] = { -1, 0, 1, -1, 0, 1, -1, 0, 1 };

const double eps = 1e-10;
vector<int> primeNumbers;

class Graph {
public:
    int V;
    vector<vector<int>> edges;

    Graph(int V) {
        this->V = V;
        edges.resize(V + 1);
    }

    void addEdge(int from, int to) {
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
};

class DisjointUnionSets {
    vector<int> rank, parent;
    int n;

public:
    DisjointUnionSets(int n) {
        rank.resize(n);
        parent.resize(n);
        fill(rank.begin(), rank.end(), 1);
        fill(parent.begin(), parent.end(), -1);
        this->n = n;
    }

    int find(int curr) {
        if (parent[curr] == -1)
            return curr;
        return parent[curr] = find(parent[curr]);
    }

    void unionSets(int a, int b) {
        int s1 = find(a);
        int s2 = find(b);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            } else {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

long powerMOD(long x, long y) {
    long res = 1L;
    while (y > 0) {
        if ((y & 1) != 0) {
            x %= mod;
            res %= mod;
            res = (res * x) % mod;
        }
        y = y >> 1;
        x %= mod;
        x = (x * x) % mod;
    }
    return res % mod;
}

long power(long x, long y) {
    long res = 1L;
    while (y > 0) {
        if ((y & 1) != 0) {
            res = (res * x);
        }
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

class SegmentTree {
public:
    vector<long> arr;
    vector<long> tree;

    SegmentTree(vector<long>& arr) {
        int n = arr.size();
        this->arr = arr;
        tree.resize(4 * n + 1);
    }

    void buildTree(int s, int e, int index) {
        if (s == e) {
            tree[index] = arr[s];
            return;
        }
        int mid = (s + e) / 2;
        buildTree(s, mid, 2 * index);
        buildTree(mid + 1, e, 2 * index + 1);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }

    long query(int s, int e, int qs, int qe, int index) {
        if (s >= qs && e <= qe) {
            return tree[index];
        }
        if (qe < s || qs > e) {
            return LONG_MAX;
        }
        int mid = (s + e) / 2;
        long left = query(s, mid, qs, qe, 2 * index);
        long right = query(mid + 1, e, qs, qe, 2 * index + 1);
        return min(left, right);
    }

    void updateNode(int s, int e, int i, long increment, int index) {
        if (i < s || i > e) {
            return;
        }
        if (s == e) {
            tree[index] += increment;
            return;
        }
        int mid = (s + e) / 2;
        updateNode(s, mid, i, increment, 2 * index);
        updateNode(mid + 1, e, i, increment, 2 * index + 1);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }

    void updateRange(int s, int e, int l, int r, long increment, int index) {
        if (l > e || r < s) {
            return;
        }
        if (s == e) {
            tree[index] += increment;
        }
        int mid = (s + e) / 2;
        updateRange(s, mid, l, r, increment, 2 * index);
        updateRange(mid + 1, e, l, r, increment, 2 * index);
        tree[index] = min(tree[2 * index], tree[2 * index + 1]);
    }
};

void primeSieve(int n) {
    vector<bool> bitset(n + 1, false);
    for (long i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            bitset[i] = true;
            continue;
        }
        if (bitset[i]) continue;
        primeNumbers.push_back((int)i);
        for (long j = i; j <= n; j += i)
            bitset[j] = true;
    }
}

int countDivisors(long number) {
    if (number == 1) return 1;
    vector<int> primeFactors;
    int index = 0;
    long curr = primeNumbers[index];
    while (curr * curr <= number) {
        while (number % curr == 0) {
            number = number / curr;
            primeFactors.push_back((int)curr);
        }
        index++;
        curr = primeNumbers[index];
    }

    if (number != 1) primeFactors.push_back((int)number);
    int current = primeFactors[0];
    int totalDivisors = 1;
    int currentCount = 2;
    for (int i = 1; i < primeFactors.size(); i++) {
        if (primeFactors[i] == current) {
            currentCount++;
        } else {
            totalDivisors *= currentCount;
            currentCount = 2;
            current = primeFactors[i];
        }
    }
    totalDivisors *= currentCount;
    return totalDivisors;
}

int primeExponentsCount(int n) {
    if (n <= 1)
        return 0;
    int sqrt = (int)sqrt(n);
    int remainingNumber = n;
    int result = 0;
    for (int i = 2; i <= sqrt; i++) {
        while (remainingNumber % i == 0) {
            result++;
            remainingNumber /= i;
        }
    }

    if (remainingNumber > 1) {
        result++;
    }
    return result;
}

bool next_permutation(vector<int>& p) {
    for (int a = p.size() - 2; a >= 0; --a)
        if (p[a] < p[a + 1])
            for (int b = p.size() - 1;; --b)
                if (p[b] > p[a]) {
                    swap(p[a], p[b]);
                    reverse(p.begin() + a + 1, p.end());
                    return true;
                }
    return false;
}

long getNcR(int n, int r) {
    long p = 1, k = 1;
    if (n - r < r) r = n - r;

    if (r != 0) {
        while (r > 0) {
            p *= n;
            k *= r;
            long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    } else {
        p = 1;
    }
    return p;
}

bool isVowel(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

void sort(vector<int>& a) {
    sort(a.begin(), a.end());
}

void sort(vector<long>& a) {
    sort(a.begin(), a.end());
}

int binomialCoeff(int n, int k) {
    vector<int> C(k + 1);
    C[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, k); j > 0; j--)
            C[j] = C[j] + C[j - 1];
    }
    return C[k];
}

class Pair {
public:
    int a;
    int b;
    int hashCode;

    Pair(int a, int b) : a(a), b(b), hashCode(hash<int>()(a) ^ hash<int>()(b)) {}

    bool operator==(const Pair& that) const {
        return a == that.a && b == that.b;
    }

    friend ostream& operator<<(ostream& os, const Pair& p) {
        return os << p.a << " -> " << p.b;
    }
};

class Triplet {
public:
    int a;
    int b;
    int c;

    Triplet(int a, int b, int c) : a(a), b(b), c(c) {}

    friend ostream& operator<<(ostream& os, const Triplet& t) {
        return os << t.a << " -> " << t.b;
    }
};

long lcm(long a, long b) {
    return a * (b / gcd(a, b));
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long gcd(long a, long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long __gcd(long n1, long n2) {
    long gcd = 1;
    for (int i = 1; i <= n1 && i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

void swap(vector<int>& arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void swap(vector<char>& arr, int left, int right) {
    char temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void reverse(vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        swap(arr, left, right);
        left++;
        right--;
    }
}

long expo(long a, long b, long mod) {
    long res = 1;
    while (b > 0) {
        if ((b & 1) == 1L) res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}

long mminvprime(long a, long b) {
    return expo(a, b - 2, b);
}

long mod_add(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

long mod_sub(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

long mod_mul(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}

long mod_div(long a, long b, long m) {
    a = a % m;
    b = b % m;
    return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}

long nCr(long N, long K, long mod) {
    long upper = 1L;
    long lower = 1L;
    long lowerr = 1L;

    for (long i = 1; i <= N; i++) {
        upper = mod_mul(upper, i, mod);
    }

    for (long i = 1; i <= K; i++) {
        lower = mod_mul(lower, i, mod);
    }

    for (long i = 1; i <= (N - K); i++) {
        lowerr = mod_mul(lowerr, i, mod);
    }

    long answer = mod_mul(lower, lowerr, mod);
    answer = mod_div(upper, answer, mod);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    vector<char> inp(str.begin(), str.end());
    int n = str.length();

    string pos[] = {"00", "25", "50", "75"};
    int count = 0;

    if (inp.size() == 1) {
        if (inp[0] == '0' || inp[0] == 'X' || inp[0] == '_') count++;
    } else {
        for (const string& cstr : pos) {
            int X = -1;
            int idx = 0;
            bool possible = true;
            for (int i = n - 2; i < n; i++) {
                char curr = inp[i];
                char strcurr = cstr[idx++];
                
                if (curr == '_') continue;
                else if (curr == 'X') {
                    if (X == -1) {
                        X = (strcurr - '0');
                    } else {
                        if (X != strcurr - '0') {
                            possible = false;
                            break;
                        }
                    }
                } else {
                    if (curr != strcurr) {
                        possible = false;
                        break;
                    }
                }
            }

            if (!possible) continue;

            if (str.length() == 2) {
                if (cstr[0] == '0') continue;
                count++;
                continue;
            }

            vector<char> ninp(inp);
            int cntX = count(inp.begin(), inp.end(), 'X');

            if (X != -1 || cntX == 0) {
                if (X != -1) {
                    for (int k = 0; k < str.length(); k++) {
                        ninp[k] = (inp[k] == 'X') ? (char)(X + '0') : inp[k];
                    }
                }

                if (ninp[0] == '0') continue;
                int counter = 1;
                for (int k = 0; k < str.length() - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter *= 9;
                        } else {
                            counter *= 10;
                        }
                    }
                }

                count += counter;
            } else {
                if (ninp[0] == '0') continue;

                int counter = 1;
                for (int k = 0; k < str.length() - 2; k++) {
                    if (ninp[k] == '_') {
                        if (k == 0) {
                            counter *= 9;
                        } else {
                            counter *= 10;
                        }
                    }
                }

                if (ninp[0] == 'X') {
                    counter *= 9;
                } else {
                    counter *= 10;
                }

                count += counter;
            }
        }
    }

    cout << count << endl;

    return 0;
}
