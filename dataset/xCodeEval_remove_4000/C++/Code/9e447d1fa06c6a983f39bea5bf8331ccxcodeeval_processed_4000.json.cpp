
































using namespace std;







typedef long long ll;
typedef unsigned long long ull;
template<typename T> void __read(T &a) { cin >> a; }
template<typename T, typename ... Args> void __read(T &a, Args &... args) { cin >> a; __read(args...); }











typedef pair<int, int> PII;
typedef pair<pair<int, int>, int> PPII;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;
constexpr ll M7 = 1000000007;
constexpr ll M9 = 1000000009ll;
constexpr ll MFFT = 998244353ll;
constexpr ll E6 = 1000000ll;
constexpr ll E9 = 1000000000ll;
constexpr ll INF = 2000000000000000000ll;
template<class T> void outv(T &a) { for (auto &x : a) cout << x << ' '; }








void solve() {
    make(int, t);
    while (t--) {
        make(int, n, m);
        VVB a(n, VB(m));
        for (int i = 0; i < n; ++i) {
            make(string, str);
            for (int j = 0; j < m; ++j) {
                a[i][j] = str[j] == '0' ? false : true;
            }
        }
        VI res;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; j += 1) {
                bool x1 = a[i][j];
                bool x2 = a[i][j + 1];
                bool x3 = a[i + 1][j];
                bool x4 = a[i + 1][j + 1];
                

                if (x1 && x2 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                }
                else if (x1 && x2 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x3 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2 && x3 && x4) {
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                

            }
        }
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; j += 1) {
                bool x1 = a[i][j];
                bool x2 = a[i][j + 1];
                bool x3 = a[i + 1][j];
                bool x4 = a[i + 1][j + 1];
                

                if (x1 && x2) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                }
                else if (x1 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i + 1][j] = false;
                }
                else if (x1 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                }
                else if (x2 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j + 1] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x3 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                

            }
        }
        for (int i = 0; i < n - 2; ++i) {
            for (int j = 0; j < m; ++j) {
                bool x1 = a[i][j];
                bool x2 = a[i + 2][j];
                bool x3 = a[i + 1][j];
                bool x4;
                if (j + 1 < m) {
                    x4 = a[i + 1][j + 1];
                    if (x1 && x2) {
                        res.pb(i);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j + 1);

                        res.pb(i + 2);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j + 1);

                        a[i][j] = false;
                        a[i + 2][j] = false;
                    }
                } else {
                    x4 = a[i + 1][j - 1];
                    if (x1 && x2) {
                        res.pb(i);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j - 1);

                        res.pb(i + 2);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j);
                        res.pb(i + 1);
                        res.pb(j - 1);

                        a[i][j] = false;
                        a[i + 2][j] = false;
                    }
                }

            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m - 2; ++j) {
                bool x1 = a[i][j];
                bool x2 = a[i][j + 2];
                bool x3 = a[i][j + 1];
                bool x4;
                if (i + 1 < n) {
                    x4 = a[i + 1][j + 1];
                    if (x1 && x2) {
                        res.pb(i);
                        res.pb(j);
                        res.pb(i);
                        res.pb(j + 1);
                        res.pb(i + 1);
                        res.pb(j + 1);

                        res.pb(i);
                        res.pb(j + 2);
                        res.pb(i);
                        res.pb(j + 1);
                        res.pb(i + 1);
                        res.pb(j + 1);

                        a[i][j] = false;
                        a[i][j + 2] = false;
                    }
                } else {
                    x4 = a[i - 1][j + 1];
                    if (x1 && x2) {
                        res.pb(i);
                        res.pb(j);
                        res.pb(i);
                        res.pb(j + 1);
                        res.pb(i - 1);
                        res.pb(j + 1);

                        res.pb(i);
                        res.pb(j + 2);
                        res.pb(i);
                        res.pb(j + 1);
                        res.pb(i - 1);
                        res.pb(j + 1);

                        a[i][j] = false;
                        a[i][j + 2] = false;
                    }
                }
            }
        }
        for (int i = 0; i < n - 1; i += 1) {
            for (int j = 0; j < m - 1; j += 1) {
                bool x1 = a[i][j];
                bool x2 = a[i][j + 1];
                bool x3 = a[i + 1][j];
                bool x4 = a[i + 1][j + 1];

                

                if (!x1 && !x2 && !x3 && !x4) {
                    continue;
                }
                else if (x1 && x2 && x3 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i + 1);
                    res.pb(j + 1);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);
                    res.pb(i);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x2 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x2 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x3 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2 && x3 && x4) {
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x2) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2 && x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x3 && x4) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x1) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x2) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x3) {
                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                else if (x4) {
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j);


                    res.pb(i);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    res.pb(i);
                    res.pb(j);
                    res.pb(i);
                    res.pb(j + 1);
                    res.pb(i + 1);
                    res.pb(j + 1);

                    a[i][j] = false;
                    a[i][j + 1] = false;
                    a[i + 1][j] = false;
                    a[i + 1][j + 1] = false;
                }
                

            }
        }
        if (n % 2 == 1 && m % 2 == 1) {
            int i = n - 2;
            int j = m - 2;
            bool x1 = a[i][j];
            bool x2 = a[i][j + 1];
            bool x3 = a[i + 1][j];
            bool x4 = a[i + 1][j + 1];

            

            if (x2 && x3 && x4) {
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                a[i][j + 1] = false;
                a[i + 1][j] = false;
                a[i + 1][j + 1] = false;
            }
            else if (x2 && x3) {
                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                a[i][j + 1] = false;
                a[i + 1][j] = false;
            }
            else if (x2 && x4) {
                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);

                res.pb(i);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                a[i][j + 1] = false;
                a[i + 1][j + 1] = false;
            }
            else if (x3 && x4) {
                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);

                a[i + 1][j] = false;
                a[i + 1][j + 1] = false;
            }
            else if (x2) {
                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);

                a[i][j + 1] = false;
            }
            else if (x3) {
                res.pb(i);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);

                a[i + 1][j] = false;
            }
            else if (x4) {
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j);


                res.pb(i);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j);
                res.pb(i + 1);
                res.pb(j + 1);

                res.pb(i);
                res.pb(j);
                res.pb(i);
                res.pb(j + 1);
                res.pb(i + 1);
                res.pb(j + 1);

                a[i + 1][j + 1] = false;
            }
            

        }



























































































































































































































































































































        Cn(res.size() / 6);
        for (int i = 0; i < res.size(); i += 6) {
            Cs(res[i] + 1);
            Cs(res[i + 1] + 1);
            Cs(res[i + 2] + 1);
            Cs(res[i + 3] + 1);
            Cs(res[i + 4] + 1);
            Cn(res[i + 5] + 1);
        }
    }
}


signed main(signed argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (argc > 1 && (string) argv[1] == "local") {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        int i = 1;
        clock_t start_time, end_time;
        cout << "/////Test 
        start_time = clock();
        solve();
        end_time = clock();
        double seconds_pass = (double) (end_time - start_time) / CLOCKS_PER_SEC;
        cout << "\n//Time: ";
        cout << setprecision(15) << seconds_pass << '\n';
        while (cin.peek() != -1) {
            ++i;
            cout << '\n';
            cout << '\n';
            cout << "/////Test 
            start_time = clock();
            solve();
            end_time = clock();
            seconds_pass = (double) (end_time - start_time) / CLOCKS_PER_SEC;
            cout << "\n//Time: ";
            cout << setprecision(15) << seconds_pass << '\n';
        }
    } else {
        solve();
    }
    return 0;
}