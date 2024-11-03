#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <deque>
#include <iomanip>
#include <fstream>
#include <functional>
#include <numeric>
#include <random>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define trav(a, x) for(auto& a : x)
#define debug(x) cerr << #x << " = " << x << endl;
#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const ll LINF = 1e18 + 7;

template<typename T>
void read(T& x) {
    cin >> x;
}

template<typename T>
void read(vector<T>& v) {
    for(auto& i : v) {
        read(i);
    }
}

template<typename T>
void write(T x) {
    cout << x;
}

template<typename T>
void write(vector<T>& v) {
    for(auto& i : v) {
        write(i);
        cout << " ";
    }
}

template<typename T>
void writeln(T x) {
    write(x);
    cout << endl;
}

template<typename T>
void writeln(vector<T>& v) {
    write(v);
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    read(n);
    read(m);

    vi L(n), R(n), A(m), B(m), C(m), max(m), best(m);
    read(L);
    read(R);
    read(A);
    read(B);
    read(C);

    vi orderV(n), orderC(m);
    for(int i = 0; i < n; ++i) {
        orderV[i] = i;
    }
    for(int i = 0; i < m; ++i) {
        orderC[i] = i;
    }

    vi arr(2 * (n + m));
    for(int i = 0; i < n; ++i) {
        arr[2 * i] = L[i];
        arr[2 * i + 1] = R[i];
    }
    for(int i = 0; i < m; ++i) {
        arr[2 * (n + i)] = A[i];
        arr[2 * (n + i) + 1] = B[i];
    }
    sort(all(arr));
    map<int, int> map;
    int idx = 0;
    for(int i = 0; i < arr.size(); ++i) {
        if(i == 0 || arr[i] != arr[i - 1]) {
            map[arr[i]] = idx++;
        }
    }

    auto tree = [&](int n) {
        return vector<ll>(4 * n + 1);
    };

    auto update = [&](vector<ll>& array, int pos, ll x) {
        function<void(int, int, int)> update = [&](int node, int left, int right) {
            if(left == right) {
                array[node] = x;
                return;
            }
            int middle = (left + right) / 2;
            if(pos <= middle) {
                update(2 * node + 1, left, middle);
            } else {
                update(2 * node + 2, middle + 1, right);
            }
            array[node] = max(array[2 * node + 1], array[2 * node + 2]);
        };
        update(0, 0, sz(array) / 4 - 1);
    };

    auto query = [&](vector<ll>& array, int from, int to) {
        function<ll(int, int, int)> query = [&](int node, int left, int right) {
            if(left > to || right < from) {
                return 0LL;
            }
            if(left >= from && right <= to) {
                return array[node];
            }
            int middle = (left + right) / 2;
            return max(query(2 * node + 1, left, middle), query(2 * node + 2, middle + 1, right));
        };
        return query(0, 0, sz(array) / 4 - 1);
    };

    auto process1 = [&](int n, int m) {
        sort(all(orderV), [&](int a, int b) {
            return L[a] < L[b];
        });
        sort(all(orderC), [&](int a, int b) {
            return A[a] < A[b];
        });

        int v = 0, c = 0, ret = 0, idx = -1, x;
        while(v < n || c < m) {
            for(; v < n && (c == m || L[orderV[v]] <= A[orderC[c]]); ++v) {
                x = orderV[v];
                if(R[x] > ret) {
                    ret = R[x];
                    idx = x;
                }
            }
            for(; c < m && (v == n || A[orderC[c]] < L[orderV[v]]); ++c) {
                x = orderC[c];
                int length = min(ret, B[x]) - A[x];
                if(length > max[x]) {
                    max[x] = length;
                    best[x] = idx;
                }
            }
        }
    };

    auto process2 = [&](int n, int m) {
        sort(all(orderV), [&](int a, int b) {
            return R[a] < R[b];
        });
        sort(all(orderC), [&](int a, int b) {
            return B[a] < B[b];
        });

        int v = 0, c = 0;
        while(v < n || c < m) {
            for(; v < n && (c == m || R[orderV[v]] <= B[orderC[c]]); ++v) {
                int x = orderV[v];
                update(tree(sz(map)), map[L[x]], 1LL * (R[x] - L[x]) * n + x);
            }
            for(; c < m && (v == n || B[orderC[c]] < R[orderV[v]]); ++c) {
                int x = orderC[c];
                ll aux = query(tree(sz(map)), map[A[x]], map[B[x]]);
                int length = aux / n;
                int y = aux % n;
                if(length > max[x]) {
                    max[x] = length;
                    best[x] = y;
                }
            }
        }
    };

    auto process3 = [&](int n, int m) {
        int v = n - 1, c = m - 1, ret = INF, idx = -1, x;
        while(v >= 0 || c >= 0) {
            for(; v >= 0 && (c == -1 || R[orderV[v]] >= B[orderC[c]]); --v) {
                x = orderV[v];
                if(L[x] < ret) {
                    ret = L[x];
                    idx = x;
                }
            }
            for(; c >= 0 && (v == -1 || B[orderC[c]] > R[orderV[v]]); --c) {
                x = orderC[c];
                int length = B[x] - max(ret, A[x]);
                if(length > max[x]) {
                    max[x] = length;
                    best[x] = idx;
                }
            }
        }
    };

    auto solve = [&](int testNumber) {
        process1(n, m);
        process2(n, m);
        process3(n, m);
        ll ret = 0;
        int aux = -1;
        for(int i = 0; i < m; ++i) {
            ll x = 1LL * max[i] * C[i];
            if(x > ret) {
                ret = x;
                aux = i;
            }
        }
        writeln(ret);
        if(ret > 0) {
            writeln(best[aux] + 1, aux + 1);
        }
    };

    solve(1);

    return 0;
}
