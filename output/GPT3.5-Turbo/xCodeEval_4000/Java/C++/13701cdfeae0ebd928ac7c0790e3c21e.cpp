#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}

int pow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int a) {
    return pow(a, MOD - 2);
}

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int findMinPrimitiveRoot(int p) {
    vector<int> factors;
    int phi = p - 1;
    int x = phi;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            factors.push_back(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        factors.push_back(x);
    }
    for (int res = 2; res <= p; res++) {
        bool ok = true;
        for (int factor : factors) {
            if (pow(res, phi / factor) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return res;
        }
    }
    return -1;
}

void dft(vector<int>& a, int g) {
    int n = a.size();
    int h = __builtin_ctz(n);
    vector<int> rev(n);
    for (int i = 0; i < n; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (h - 1));
        if (i < rev[i]) {
            swap(a[i], a[rev[i]]);
        }
    }
    for (int len = 2; len <= n; len <<= 1) {
        int wlen = pow(g, (MOD - 1) / len);
        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i + j];
                int v = mul(a[i + j + len / 2], w);
                a[i + j] = add(u, v);
                a[i + j + len / 2] = add(u, MOD - v);
                w = mul(w, wlen);
            }
        }
    }
}

void idft(vector<int>& a, int g) {
    int n = a.size();
    dft(a, inv(g));
    int inv_n = inv(n);
    for (int& x : a) {
        x = mul(x, inv_n);
    }
}

void multiply(vector<int>& a, vector<int>& b) {
    int n = 1;
    while (n < a.size() + b.size()) {
        n <<= 1;
    }
    a.resize(n);
    b.resize(n);
    int g = findMinPrimitiveRoot(MOD);
    dft(a, g);
    dft(b, g);
    for (int i = 0; i < n; i++) {
        a[i] = mul(a[i], b[i]);
    }
    idft(a, g);
    while (!a.empty() && a.back() == 0) {
        a.pop_back();
    }
}

int solve(int n, int k, vector<int>& allow) {
    vector<int> p(10);
    for (int i = 0; i < k; i++) {
        p[allow[i]] = 1;
    }
    vector<int> last = p;
    int m = n / 2;
    int g = findMinPrimitiveRoot(MOD);
    vector<vector<int>> lists;
    while (m > 1) {
        if (m & 1) {
            lists.push_back(last);
        }
        vector<int> next(last.size());
        for (int i = 0; i < last.size(); i++) {
            for (int j = 0; j < last.size(); j++) {
                next[(i + j) % last.size()] = add(next[(i + j) % last.size()], mul(last[i], last[j]));
            }
        }
        last = next;
        m >>= 1;
    }
    lists.push_back(last);
    vector<int> prod(last.size());
    for (int i = 0; i < lists.size(); i++) {
        for (int j = 0; j < lists[i].size(); j++) {
            prod[j] = add(prod[j], lists[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < prod.size(); i++) {
        ans = add(ans, mul(prod[i], prod[i]));
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> allow(k);
    for (int i = 0; i < k; i++) {
        cin >> allow[i];
    }
    int ans = solve(n, k, allow);
    cout << ans << "\n";
    return 0;
}
