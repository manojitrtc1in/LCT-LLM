#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>

using namespace std;

long long repow(long long b, long long p) {
    long long res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res *= b;
        }
        b *= b;
        p /= 2;
    }
    return res;
}

long long repow(long long b, long long p, long long modder) {
    long long a = b % modder;
    long long res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res = (res * a) % modder;
        }
        a = (a * a) % modder;
        p /= 2;
    }
    return res;
}

long long gcd(long long c, long long d) {
    while (true) {
        long long f = c % d;
        if (f == 0) {
            return d;
        }
        c = d;
        d = f;
    }
}

long long lcm(long long c, long long d) {
    return c / gcd(c, d) * d;
}

vector<int> divList(int n) {
    vector<int> div;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) {
                div.push_back(n / i);
            }
        }
    }
    return div;
}

vector<long long> divList(long long n) {
    vector<long long> div;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i * i != n) {
                div.push_back(n / i);
            }
        }
    }
    return div;
}

unordered_map<long long, int> id9(long long x) {
    unordered_map<long long, int> mp;
    long long t = x;
    for (long long i = 2; i * i <= x && i <= t; i++) {
        if (t % i == 0) {
            int num = 0;
            while (t % i == 0) {
                t /= i;
                num++;
            }
            mp[i] = num;
        }
    }
    if (t != 1) {
        mp[t] = 1;
    }
    return mp;
}

bool iP(long long n) {
    if (n == 2) {
        return true;
    }
    if ((n & 1) == 0 || n == 1) {
        return false;
    }

    if (n > INT_MAX) {
        return id5(n);
    }
    long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d /= 2;
        s++;
    }
    int aa[] = {2, 3, 5, 7, 11, 13, 17};
    for (int i = 0; i < 7 && aa[i] < n; i++) {
        int a = aa[i];
        long long t = d;
        long long y = repow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = (y * y) % n;
            t = t << 1;
        }
        if (y != n - 1 && (t & 1) == 0) {
            return false;
        }
    }
    return true;
}

bool id5(long long n) {
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

class Scnr {
private:
    istream &ins;
public:
    Scnr(istream &in = cin) : ins(in) {}

    bool hasNext() {
        return ins.peek() != EOF;
    }

    string next() {
        string s;
        ins >> s;
        return s;
    }

    int nextInt() {
        int n;
        ins >> n;
        return n;
    }

    long long nextLong() {
        long long n;
        ins >> n;
        return n;
    }
};

Scnr sc;

void solve() {
    int n = sc.nextInt();
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(sc.nextInt());
    }
    int a = dq.front();
    dq.pop_front();
    int b = 0;
    int pre = a;
    int now;
    int cnt = 1;

    while (!dq.empty()) {
        now = 0;
        while (now <= pre && !dq.empty()) {
            now += dq.back();
            dq.pop_back();
        }
        if (now != 0) {
            b += now;
            pre = now;
            cnt++;
        }

        if (dq.empty()) {
            break;
        }

        now = 0;
        while (now <= pre && !dq.empty()) {
            now += dq.front();
            dq.pop_front();
        }
        if (now != 0) {
            a += now;
            pre = now;
            cnt++;
        }
    }
    cout << cnt << " " << a << " " << b << endl;
}

int main() {
    for (int i = sc.nextInt(); i > 0; i--) {
        solve();
    }
    return 0;
}
