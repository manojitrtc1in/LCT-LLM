#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <set>
#include <utility>
#include <vector>
#include <list>
#include <algorithm>
#include <regex>
#include <cmath>
#include <map>
#include <iterator>
#include <climits>
#include <numeric>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <array>
#include <valarray>
#include <complex>
#include <random>
#include <functional>
#include <cassert>
#include <chrono>
#include <memory>

using namespace std;





#define double long double
#define int long long
typedef long long ll;
typedef unsigned long long ull;
template<typename T> void __read(T &a) { cin >> a; }
template<typename T, typename ... Args> void __read(T &a, Args &... args) { cin >> a; __read(args...); }
#define make(t, ...) t __VA_ARGS__; __read(__VA_ARGS__)
#define makev(a, n) VI a(n); for(auto& v : a) cin >> v
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define FORIT(p) for(auto it = p.begin(); it != p.end(); it++)
#define FOR(b) for(signed i = 0; i <(b); i++)
#define FORE(i, l, r) for(int i = (l); i < (r); i++)
#define NFOR(i, n) for(int i = (((int)n) - 1); i >= 0; i--)
#define pb push_back
#define Cs(x) cout << x << ' '
#define Cn(x) cout << x << '\n'
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
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
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
        cout << "/////Test #" << i << "/////\n";
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
            cout << "/////Test #" << i << "/////\n";
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