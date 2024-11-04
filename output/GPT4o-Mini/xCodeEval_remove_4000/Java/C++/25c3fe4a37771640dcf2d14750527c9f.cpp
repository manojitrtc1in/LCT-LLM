#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <bitset>
#include <unordered_map>
#include <numeric>
#include <iomanip>

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

class id0 {
public:
    vector<int> rank, parent;
    int n;

    id0(int n) {
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

class segmentTree {
public:
    vector<long> arr;
    vector<long> tree;

    segmentTree(long arr[], int n) {
        this->arr.resize(n);
        for (int i = 0; i < n; i++) {
            this->arr[i] = arr[i];
        }
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

void id1(int n) {
    bitset<1000001> bitset;
    for (long i = 0; i < n; i++) {
        if (i == 0 || i == 1) {
            bitset.set((int)i);
            continue;
        }
        if (bitset.test((int)i)) continue;
        primeNumbers.push_back((int)i);
        for (long j = i; j <= n; j += i)
            bitset.set((int)j);
    }
}

int id4(long number) {
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
    int id8 = 1;
    int currentCount = 2;
    for (int i = 1; i < primeFactors.size(); i++) {
        if (primeFactors[i] == current) {
            currentCount++;
        } else {
            id8 *= currentCount;
            currentCount = 2;
            current = primeFactors[i];
        }
    }
    id8 *= currentCount;
    return id8;
}

int id10(int n) {
    if (n <= 1)
        return 0;
    int sqrtN = (int)sqrt(n);
    int remainingNumber = n;
    int result = 0;
    for (int i = 2; i <= sqrtN; i++) {
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

bool id6(int p[]) {
    for (int a = sizeof(p) / sizeof(p[0]) - 2; a >= 0; --a)
        if (p[a] < p[a + 1])
            for (int b = sizeof(p) / sizeof(p[0]) - 1;; --b)
                if (p[b] > p[a]) {
                    swap(p[a], p[b]);
                    for (++a, b = sizeof(p) / sizeof(p[0]) - 1; a < b; ++a, --b) {
                        swap(p[a], p[b]);
                    }
                    return true;
                }
    return false;
}

long id5(int n, int r) {
    long p = 1, k = 1;
    if (n - r < r) r = n - r;
    if (r != 0) {
        while (r > 0) {
            p *= n;
            k *= r;
            long m = id9(p, k);
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

bool id3(char c) {
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U');
}

void sort(int a[], int size) {
    vector<int> l(a, a + size);
    sort(l.begin(), l.end());
    for (int i = 0; i < size; i++) a[i] = l[i];
}

void sort(long a[], int size) {
    vector<long> l(a, a + size);
    sort(l.begin(), l.end());
    for (int i = 0; i < size; i++) a[i] = l[i];
}

int id7(int n, int k) {
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

    Pair(int a, int b) {
        this->a = a;
        this->b = b;
        this->hashCode = hash<int>()(a) ^ hash<int>()(b);
    }

    bool operator==(const Pair& other) const {
        return a == other.a && b == other.b;
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

    Triplet(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

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

long id9(long n1, long n2) {
    long gcd = 1;
    for (int i = 1; i <= n1 && i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

void swap(char& left, char& right) {
    char temp = left;
    left = right;
    right = temp;
}

void reverse(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        swap(arr[left], arr[right]);
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

long id2(long a, long b) {
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
    return (mod_mul(a, id2(b, m), m) + m) % m;
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

long combination(long n, long r, long m, long fact[], long ifact[]) {
    long val1 = fact[n];
    long val2 = ifact[n - r];
    long val3 = ifact[r];
    return (((val1 * val2) % m) * val3) % m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    getline(cin, str);
    int n = str.length();
    string pos[] = { "00", "25", "50", "75" };
    int count = 0;

    if (str.length() == 1) {
        if (str[0] == '0' || str[0] == 'X' || str[0] == '_') count++;
    } else {
        for (string cstr : pos) {
            int X = -1;
            int idx = 0;
            bool possible = true;
            for (int i = n - 2; i < n; i++) {
                char curr = str[i];
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

            vector<char> ninp(str.begin(), str.end());
            int cntX = count_if(str.begin(), str.end(), [](char ch) { return ch == 'X'; });

            if (X != -1 || cntX == 0) {
                if (X != -1) {
                    for (int k = 0; k < str.length(); k++) {
                        ninp[k] = (str[k] == 'X') ? (char)(X + '0') : str[k];
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
