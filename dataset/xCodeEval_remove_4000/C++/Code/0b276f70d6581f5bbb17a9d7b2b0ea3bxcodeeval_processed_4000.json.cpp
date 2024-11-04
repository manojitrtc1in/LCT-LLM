

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = pair<int, int>;

constexpr int MAXN = 30005;
constexpr int N = 6;

int n, m;
vector<vector<int> > A;
vector<vector<int> > result(MAXN, vector<int>(N));

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        decltype(A)().swap(A);
        A.resize(n + 1, vector<int>(m + 1));
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (size_t j = 0; j != m; ++j) {
                A.at(i + 1).at(j + 1) = s.at(j) - '0';
            }
        }
        int tot = 0;
        for (int i = 1; i < n - 1; ++i)
            for (int j = 1; j < m - 1; ++j)
                if (A.at(i).at(j) == 1) {
                    if (A.at(i + 1).at(j) == 1 && A.at(i + 1).at(j + 1) == 1) {
                        ++tot;
                        result.at(tot).at(0) = i;
                        result.at(tot).at(1) = j;
                        result.at(tot).at(2) = i + 1;
                        result.at(tot).at(3) = j;
                        result.at(tot).at(4) = i + 1;
                        result.at(tot).at(5) = j + 1;
                        A.at(i).at(j) = 1 - A.at(i).at(j);
                        A.at(i + 1).at(j) = 1 - A.at(i + 1).at(j);
                        A.at(i + 1).at(j + 1) = 1 - A.at(i + 1).at(j + 1);
                    } else {
                        ++tot;
                        result.at(tot).at(0) = i;
                        result.at(tot).at(1) = j;
                        result.at(tot).at(2) = i;
                        result.at(tot).at(3) = j + 1;
                        result.at(tot).at(4) = i + 1;
                        result.at(tot).at(5) = j + 1;
                        A.at(i).at(j) = 1 - A.at(i).at(j);
                        A.at(i).at(j + 1) = 1 - A.at(i).at(j + 1);
                        A.at(i + 1).at(j + 1) = 1 - A.at(i + 1).at(j + 1);
                    }
                }
        for (int i = 1; i < m - 1; ++i) {
            if (A.at(n - 1).at(i) == 0 && A.at(n).at(i) == 1) {
                ++tot;
                result.at(tot).at(0) = n;
                result.at(tot).at(1) = i;
                result.at(tot).at(2) = n - 1;
                result.at(tot).at(3) = i + 1;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = i + 1;
                A.at(n).at(i) = 0;
                A.at(n - 1).at(i + 1) = 1 - A.at(n - 1).at(i + 1);
                A.at(n).at(i + 1) = 1 - A.at(n).at(i + 1);
            } else if (A.at(n - 1).at(i) == 1 && A.at(n).at(i) == 0) {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = i;
                result.at(tot).at(2) = n - 1;
                result.at(tot).at(3) = i + 1;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = i + 1;
                A.at(n - 1).at(i) = 0;
                A.at(n - 1).at(i + 1) = 1 - A.at(n - 1).at(i + 1);
                A.at(n).at(i + 1) = 1 - A.at(n).at(i + 1);
            } else if (A.at(n - 1).at(i) == 1 && A.at(n).at(i) == 1) {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = i;
                result.at(tot).at(2) = n - 1;
                result.at(tot).at(3) = i + 1;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = i;
                A.at(n - 1).at(i) = A.at(n).at(i) = 0;
                A.at(n - 1).at(i + 1) = 1 - A.at(n - 1).at(i + 1);
            }
        }
        for (int i = 1; i < n - 1; ++i) {
            if (A.at(i).at(m - 1) == 0 && A.at(i).at(m) == 1) {
                ++tot;
                result.at(tot).at(0) = i;
                result.at(tot).at(1) = m;
                result.at(tot).at(2) = i + 1;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = i + 1;
                result.at(tot).at(5) = m - 1;
                A.at(i).at(m) = 0;
                A.at(i + 1).at(m) = 1 - A.at(i + 1).at(m);
                A.at(i + 1).at(m - 1) = 1 - A.at(i + 1).at(m - 1);
            } else if (A.at(i).at(m - 1) == 1 && A.at(i).at(m) == 0) {
                ++tot;
                result.at(tot).at(0) = i;
                result.at(tot).at(1) = m - 1;
                result.at(tot).at(2) = i + 1;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = i + 1;
                result.at(tot).at(5) = m - 1;
                A.at(i).at(m - 1) = 0;
                A.at(i + 1).at(m) = 1 - A.at(i + 1).at(m);
                A.at(i + 1).at(m - 1) = 1 - A.at(i + 1).at(m - 1);
            } else if (A.at(i).at(m - 1) == 1 && A.at(i).at(m) == 1) {
                ++tot;
                result.at(tot).at(0) = i;
                result.at(tot).at(1) = m - 1;
                result.at(tot).at(2) = i;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = i + 1;
                result.at(tot).at(5) = m - 1;
                A.at(i).at(m - 1) = A.at(i).at(m) = 0;
                A.at(i + 1).at(m - 1) = 1 - A.at(i + 1).at(m - 1);
            }
        }
        if (A.at(n - 1).at(m - 1) == 1 && A.at(n - 1).at(m) == 1 &&
            A.at(n).at(m - 1) == 1 &&
            A.at(n).at(m) == 1) {
            ++tot;
            result.at(tot).at(0) = n - 1;
            result.at(tot).at(1) = m - 1;
            result.at(tot).at(2) = n - 1;
            result.at(tot).at(3) = m;
            result.at(tot).at(4) = n;
            result.at(tot).at(5) = m - 1;
            A.at(n - 1).at(m - 1) = A.at(n - 1).at(m) = A.at(n).at(m - 1) = 0;
        }
        int situation = 0;
        for (int i = n - 1; i <= n; ++i) {
            for (int j = m - 1; j <= m; ++j) {
                situation += A.at(i).at(j);
            }
        }
        if (situation == 3) {
            int current = 0;
            ++tot;
            for (int i = n - 1; i <= n; ++i)
                for (int j = m - 1; j <= m; ++j)
                    if (A.at(i).at(j) == 1) {
                        A.at(i).at(j) = 0;
                        result.at(tot).at(current++) = i;
                        result.at(tot).at(current++) = j;
                    }
        }
        if (situation == 1) {
            if (A.at(n - 1).at(m) == 1) {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = m;
                result.at(tot).at(2) = n;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = m - 1;
                A.at(n - 1).at(m) = 0;
                A.at(n).at(m) = A.at(n).at(m - 1) = 1;
            } else if (A.at(n - 1).at(m - 1) == 1) {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = m - 1;
                result.at(tot).at(2) = n;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = m - 1;
                A.at(n - 1).at(m - 1) = 0;
                A.at(n).at(m) = A.at(n).at(m - 1) = 1;
            } else if (A.at(n).at(m - 1) == 1) {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = m - 1;
                result.at(tot).at(2) = n - 1;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = m - 1;
                A.at(n).at(m - 1) = 0;
                A.at(n - 1).at(m - 1) = A.at(n - 1).at(m) = 1;
            } else {
                ++tot;
                result.at(tot).at(0) = n - 1;
                result.at(tot).at(1) = m - 1;
                result.at(tot).at(2) = n - 1;
                result.at(tot).at(3) = m;
                result.at(tot).at(4) = n;
                result.at(tot).at(5) = m;
                A.at(n).at(m) = 0;
                A.at(n - 1).at(m - 1) = A.at(n - 1).at(m) = 1;
            }
            situation = 2;
        }
        if (situation == 2) {
            if (A.at(n).at(m - 1) == A.at(n - 1).at(m)) {
                if (A.at(n).at(m - 1) == 1) {
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n - 1;
                    result.at(tot).at(3) = m;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                } else {
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m;
                    ++tot;
                    result.at(tot).at(0) = n;
                    result.at(tot).at(1) = m;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m;
                }
            } else {
                if (A.at(n - 1).at(m - 1) == 1 && A.at(n - 1).at(m) == 1) {
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                } else if (A.at(n - 1).at(m - 1) == 1 &&
                           A.at(n).at(m - 1) == 1) {
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n - 1;
                    result.at(tot).at(3) = m;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                    ++tot;
                    result.at(tot).at(0) = n;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n - 1;
                    result.at(tot).at(3) = m;
                    result.at(tot).at(4) = n;
                    result.at(tot).at(5) = m;
                } else if (A.at(n).at(m) == 1 && A.at(n - 1).at(m) == 1) {
                    ++tot;
                    result.at(tot).at(0) = n;
                    result.at(tot).at(1) = m;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m - 1;
                    ++tot;
                    result.at(tot).at(0) = n - 1;
                    result.at(tot).at(1) = m;
                    result.at(tot).at(2) = n;
                    result.at(tot).at(3) = m - 1;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m - 1;
                } else {
                    ++tot;
                    result.at(tot).at(0) = n;
                    result.at(tot).at(1) = m;
                    result.at(tot).at(2) = n - 1;
                    result.at(tot).at(3) = m;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m - 1;
                    ++tot;
                    result.at(tot).at(0) = n;
                    result.at(tot).at(1) = m - 1;
                    result.at(tot).at(2) = n - 1;
                    result.at(tot).at(3) = m;
                    result.at(tot).at(4) = n - 1;
                    result.at(tot).at(5) = m - 1;
                }
            }
        }
        cout << tot << '\n';
        for (int i = 1; i <= tot; ++i) {
            for (int j = 0; j < 6; ++j) {
                cout << result.at(i).at(j) << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}