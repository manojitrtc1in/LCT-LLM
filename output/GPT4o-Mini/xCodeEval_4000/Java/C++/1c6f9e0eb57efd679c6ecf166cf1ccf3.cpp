#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const long long m2 = (long long)mod * mod;
const long long BIG = 8LL * m2;

class F2 {
public:
    void solve() {
        int n, m;
        cin >> n >> m;
        vector<string> oss(n);
        vector<vector<char>> ss(n);
        for (int i = 0; i < n; i++) {
            cin >> oss[i];
            ss[i] = vector<char>(oss[i].begin(), oss[i].end());
        }
        vector<int> offset(n + 1);
        offset[0] = 1;
        for (int i = 0; i < n; i++) {
            offset[i + 1] = offset[i] + ss[i].size() - 1;
        }
        int U = offset[n] - 1;

        const int D = 5;
        vector<vector<int>> M((U + 1) * D, vector<int>((U + 1) * D, 0));

        for (int i = 0; i < U + 1; i++) {
            int lb, of;
            if (i == 0) {
                lb = 0;
                of = 0;
            } else {
                lb = lower_bound(offset.begin(), offset.end(), i + 1) - offset.begin() - 1;
                of = i - offset[lb] + 1;
            }

            if (i == 0) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (k != j && oss[k].rfind(oss[j], 0) == 0) {
                            M[offset[k] + ss[j].size() - 1][0 + (U + 1) * (ss[j].size() - 1)] = 1;
                        }
                    }
                    M[0][0 + (U + 1) * (ss[j].size() - 1)] += 1;
                }
            } else {
                for (int j = 0; j < n; j++) {
                    if (oss[lb].substr(of) == oss[j]) {
                        M[0][i + (U + 1) * (oss[j].size() - 1)] += 2;
                    } else if (oss[lb].substr(of).rfind(oss[j], 0) == 0) {
                        M[i + oss[j].size()][i + (U + 1) * (oss[j].size() - 1)] += 1;
                    }
                }

                string suf = oss[lb].substr(of);
                for (int j = 0; j < n; j++) {
                    if (oss[j].rfind(suf, 0) == 0 && oss[j] != suf) {
                        M[offset[j] + suf.size() - 1][i + (U + 1) * (suf.size() - 1)] += 1;
                    }
                }
            }
        }
        for (int i = 0; i < U + 1; i++) {
            for (int j = 0; j < D - 1; j++) {
                M[i + (U + 1) * (j + 1)][i + (U + 1) * j] = 1;
            }
        }

        vector<int> v((U + 1) * D);
        v[0] = 1;
        v = pow(M, v, m);

        cout << v[0] << endl;
    }

    vector<int> pow(const vector<vector<int>>& A, vector<int> v, long long e) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= mod) v[i] %= mod;
        }
        auto MUL = A;
        for (; e > 0; e >>= 1) {
            if ((e & 1) == 1) v = mul(MUL, v);
            MUL = p2(MUL);
        }
        return v;
    }

    vector<int> mul(const vector<vector<int>>& A, const vector<int>& v) {
        int m = A.size();
        int n = v.size();
        vector<int> w(m);
        for (int i = 0; i < m; i++) {
            long long sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (long long)A[i][k] * v[k];
                if (sum >= BIG) sum -= BIG;
            }
            w[i] = (int)(sum % mod);
        }
        return w;
    }

    vector<vector<int>> p2(const vector<vector<int>>& A) {
        int n = A.size();
        vector<vector<int>> C(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            vector<long long> sum(n, 0);
            for (int k = 0; k < n; k++) {
                for (int j = 0; j < n; j++) {
                    sum[j] += (long long)A[i][k] * A[k][j];
                    if (sum[j] >= BIG) sum[j] -= BIG;
                }
            }
            for (int j = 0; j < n; j++) {
                C[i][j] = (int)(sum[j] % mod);
            }
        }
        return C;
    }

    int lower_bound(const vector<int>& a, int v) {
        return lower_bound(a.begin(), a.end(), v) - a.begin();
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        solve();
    }
};

int main() {
    F2().run();
    return 0;
}
