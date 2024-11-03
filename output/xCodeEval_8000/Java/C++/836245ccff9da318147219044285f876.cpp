#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int mod = 1000000007;
const int mod2 = 998244353;

struct FastReader {
    FastReader() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    }
    int nextInt() {
        int x;
        cin >> x;
        return x;
    }
    long long nextLong() {
        long long x;
        cin >> x;
        return x;
    }
    double nextDouble() {
        double x;
        cin >> x;
        return x;
    }
    string nextLine() {
        string str;
        getline(cin, str);
        return str;
    }
};

struct _InVoker_ {
    long long pref[100001];

    void main() {
        int n;
        cin >> n;
        long long a[n];
        input(a, n);
        if (n > 66) {
            cout << 1 << endl;
            return;
        }
        pref[1] = a[0];
        for (int i = 1; i < n; i++) {
            pref[i + 1] = pref[i] ^ a[i];
        }
        int gg = 34;
        for (int c = 0; c < n - 1; c++) {
            for (int left = c; left >= 0; left--) {
                for (int right = c + 1; right < n; right++) {
                    if (xor(left, c) > xor(c + 1, right)) {
                        gg = min(gg, right - left - 1);
                    }
                }
            }
        }
        cout << (gg == 34 ? -1 : gg) << endl;
    }

    long long xor(int i, int j) {
        return pref[j + 1] ^ pref[i];
    }

    void sort(int a[], int n) {
        vector<int> list;
        for (int i = 0; i < n; i++) {
            list.push_back(a[i]);
        }
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) {
            a[i] = list[i];
        }
    }

    void sort(long long a[], int n) {
        vector<long long> list;
        for (int i = 0; i < n; i++) {
            list.push_back(a[i]);
        }
        sort(list.begin(), list.end());
        for (int i = 0; i < n; i++) {
            a[i] = list[i];
        }
    }

    void ruffleSort(int a[], int n) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        sort(a, n);
    }

    void ruffleSort(long long a[], int n) {
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            int j = rand() % n;
            long long temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        sort(a, n);
    }

    long long fact[100001];
    long long invFact[100001];

    void init(int n) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = mul(i, fact[i - 1]);
        }
        invFact[n] = power(fact[n], mod - 2);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = mul(invFact[i + 1], i + 1);
        }
    }

    long long modInv(long long x) {
        return power(x, mod - 2);
    }

    long long nCr(int n, int r) {
        if (n < r || r < 0) {
            return 0;
        }
        return mul(fact[n], mul(invFact[r], invFact[n - r]));
    }

    long long mul(long long a, long long b) {
        return (a * b) % mod;
    }

    long long add(long long a, long long b) {
        return (a + b) % mod;
    }

    long long power(long long x, long long y) {
        long long gg = 1;
        while (y > 0) {
            if (y % 2 == 1) {
                gg = mul(gg, x);
            }
            x = mul(x, x);
            y /= 2;
        }
        return gg;
    }

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    void print(int a[], int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void print(long long a[], int n) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    void input(long long a[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(int a[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }

    void input(string s[], int n) {
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
    }

    void input(int a[][1001], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }

    void input(long long a[][1001], int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
    }
};

int main() {
    _InVoker_ g;
    g.main();
    return 0;
}
