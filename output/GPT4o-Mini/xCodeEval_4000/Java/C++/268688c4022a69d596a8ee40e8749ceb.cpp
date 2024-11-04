#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

long long repow(long long b, long long p) {
    long long a = b;
    long long res = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            res *= a;
        }
        a *= a;
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

unordered_map<long long, int> pFacMap(long long x) {
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

bool isPrime(long long n) {
    if (n == 2) {
        return true;
    }
    if ((n & 1) == 0 || n == 1) {
        return false;
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

class Scnr {
    public:
        Scnr() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
        }

        int nextInt() {
            int n;
            cin >> n;
            return n;
        }

        vector<int> nextAint(int n) {
            vector<int> a(n);
            for (int i = 0; i < n; i++) {
                a[i] = nextInt();
            }
            return a;
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
    cout << cnt << " " << a << " " << b << "\n";
}

int main() {
    int t = sc.nextInt();
    while (t--) {
        solve();
    }
    return 0;
}
