#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define mod2 998244353

class InVoker {
public:
    static long mod = 1000000007;
    static long mod2 = 998244353;
    static FastReader inp;
    static PrintWriter out;

    void main() {
        int n = inp.nextInt();
        int k = inp.nextInt();
        long a[n];
        input(a, n);
        sort(a, a + n);
        for (int i = 0; i < n / 2; i++) {
            long temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - i - 1] = temp;
        }
        priority_queue<long, vector<long>, greater<long>> pq;
        while (k-- >= 0) {
            pq.push(0);
        }
        long gg = 0;
        for (int i = 0; i < n; i++) {
            long cur = pq.top();
            gg += cur;
            cur += a[i];
            pq.pop();
            pq.push(cur);
        }
        out << gg << endl;
    }

    void sort(int a[], int n) {
        vector<int> list(a, a + n);
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) {
            a[i] = list[i];
        }
    }

    void sort(long a[], int n) {
        vector<long> list(a, a + n);
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) {
            a[i] = list[i];
        }
    }

    void ruffleSort(int a[], int n) {
        random_device rd;
        mt19937 g(rd());
        for (int i = 0; i < n; i++) {
            int j = uniform_int_distribution<>(0, n - 1)(g);
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        sort(a, a + n);
    }

    void ruffleSort(long a[], int n) {
        random_device rd;
        mt19937 g(rd());
        for (int i = 0; i < n; i++) {
            int j = uniform_int_distribution<>(0, n - 1)(g);
            long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        sort(a, a + n);
    }

    class FastReader {
    public:
        istream& br;
        stringstream ss;
        string st;

        FastReader() : br(cin) {}

        string next() {
            while (ss.str().empty() || !getline(br, st)) {
                ss.clear();
                ss.str(st);
            }
            string token;
            ss >> token;
            return token;
        }

        int nextInt() {
            return stoi(next());
        }

        long nextLong() {
            return stol(next());
        }

        double nextDouble() {
            return stod(next());
        }

        string nextLine() {
            string s;
            getline(br, s);
            return s;
        }
    };

    long fact[];
    long invFact[];

    void init(int n) {
        fact = new long[n + 1];
        invFact = new long[n + 1];
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        invFact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    long nCr(int n, int r) {
        if (n < r || r < 0) return 0;
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    long add(long a, long b) {
        return (a + b) % mod;
    }

    long mul(long a, long b) {
        return (a * b) % mod;
    }

    long power(long x, long y) {
        long gg = 1;
        while (y > 0) {
            if (y % 2 == 1) gg = mul(gg, x);
            x = mul(x, x);
            y /= 2;
        }
        return gg;
    }

    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void print(int a[], int n) {
        for (int i = 0; i < n; i++) {
            out << a[i] << " ";
        }
    }

    void print(long a[], int n) {
        for (int i = 0; i < n; i++) {
            out << a[i] << " ";
        }
    }

    void input(long a[], int n) {
        for (int i = 0; i < n; i++) {
            a[i] = inp.nextLong();
        }
    }

    void input(int a[], int n) {
        for (int i = 0; i < n; i++) {
            a[i] = inp.nextInt();
        }
    }

    void input(string s[], int n) {
        for (int i = 0; i < n; i++) {
            s[i] = inp.next();
        }
    }

    void input(int a[][], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = inp.nextInt();
            }
        }
    }

    void input(long a[][], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = inp.nextLong();
            }
        }
    }
};

int main() {
    InVoker g;
    g.main();
    return 0;
}
