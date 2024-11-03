#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

const long long mod = 1000000007;
const long long mod2 = 998244353;

struct FastReader {
    char* buf;
    int ptr;
    FastReader() {
        buf = new char[1 << 20];
        fread(buf, 1, 1 << 20, stdin);
        ptr = 0;
    }
    int nextInt() {
        int ret = 0;
        while (buf[ptr] < '0' || buf[ptr] > '9') ptr++;
        while (buf[ptr] >= '0' && buf[ptr] <= '9') {
            ret = ret * 10 + buf[ptr] - '0';
            ptr++;
        }
        return ret;
    }
    long long nextLong() {
        long long ret = 0;
        while (buf[ptr] < '0' || buf[ptr] > '9') ptr++;
        while (buf[ptr] >= '0' && buf[ptr] <= '9') {
            ret = ret * 10 + buf[ptr] - '0';
            ptr++;
        }
        return ret;
    }
};

class id0 {
    static const int MAXN = 1e5 + 5;
    FastReader inp;
    vector<long long> fact;
    vector<long long> invFact;

public:
    void main() {
        int n = inp.nextInt();
        int k = inp.nextInt();
        vector<long long> a(n);
        input(a, n);
        sort(a.begin(), a.end(), greater<long long>());
        priority_queue<long long> pq;
        for (int i = 0; i <= k; i++) {
            pq.push(0);
        }
        long long gg = 0;
        for (int i = 0; i < n; i++) {
            long long cur = pq.top();
            pq.pop();
            gg += cur;
            cur += a[i];
            pq.push(cur);
        }
        cout << gg << endl;
    }

    void sort(vector<int>& a) {
        sort(a.begin(), a.end());
    }

    void sort(vector<long long>& a) {
        sort(a.begin(), a.end());
    }

    void id1(vector<int>& a) {
        srand(time(NULL));
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            swap(a[i], a[j]);
        }
        sort(a);
    }

    void id1(vector<long long>& a) {
        srand(time(NULL));
        int n = a.size();
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            swap(a[i], a[j]);
        }
        sort(a);
    }

    void input(vector<long long>& a, int n) {
        for (int i = 0; i < n; i++) {
            a[i] = inp.nextLong();
        }
    }

    void input(vector<int>& a, int n) {
        for (int i = 0; i < n; i++) {
            a[i] = inp.nextInt();
        }
    }

    void input(vector<string>& s, int n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    void input(vector<vector<int>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = inp.nextInt();
            }
        }
    }

    void input(vector<vector<long long>>& a, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = inp.nextLong();
            }
        }
    }

    long long mul(long long a, long long b) {
        return a * b % mod;
    }

    long long power(long long x, long long y) {
        long long gg = 1;
        while (y > 0) {
            if (y % 2 == 1) gg = mul(gg, x);
            x = mul(x, x);
            y /= 2;
        }
        return gg;
    }

    void init(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        invFact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    long long nCr(int n, int r) {
        if (n < r || r < 0) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    long long add(long long a, long long b) {
        return (a + b) % mod;
    }

    static long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void print(vector<int>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) cout << a[i] << " ";
    }

    void print(vector<long long>& a) {
        int n = a.size();
        for (int i = 0; i < n; i++) cout << a[i] << " ";
    }
};

int main() {
    id0 g;
    g.main();
    return 0;
}
