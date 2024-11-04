#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long MOD2 = MOD * MOD;

class FastReader {
    ifstream br;
    stringstream st;

public:
    FastReader() {
        br.open("input.txt");
    }

    string next() {
        while (st.str().empty() || !st.good()) {
            string line;
            getline(br, line);
            st.clear();
            st.str(line);
        }
        string token;
        st >> token;
        return token;
    }

    int nextInt() {
        return stoi(next());
    }

    double nextDouble() {
        return stod(next());
    }

    long long nextLong() {
        return stoll(next());
    }

    string nextLine() {
        string str;
        getline(br, str);
        return str;
    }
};

long long mul(long long a, long long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long add(long long a, long long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

long long sub(long long a, long long b) {
    return ((a % MOD) - (b % MOD)) % MOD;
}

long long exp(long long base, long long e) {
    if (e == 0) return 1;
    long long half = exp(base, e / 2);
    if (e % 2 == 0) return mul(half, half);
    return mul(half, mul(half, base));
}

long long modInv(long long x) {
    return exp(x, MOD - 2);
}

void solve() {
    FastReader sc;
    string s = sc.next();
    string t = sc.next();
    int n = s.length();
    int m = t.length();
    vector<int> pre(m), suf(m);
    for (int i = 0, j = 0; i < m; i++) {
        while (s[j] != t[i]) j++;
        pre[i] = j++;
    }
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (s[j] != t[i]) j--;
        suf[i] = j--;
    }
    int ans = max(suf[0], n - 1 - pre[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, suf[i + 1] - 1 - pre[i]);
    }
    cout << ans << endl;
}

int main() {
    int test = 1;
    while (test-- > 0) solve();
    return 0;
}
