#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define nax 1044
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, n) for(int i = 0; i < n; i++)
#define debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef unsigned int unt;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vector<int> graf[nax];
int siz[nax];
int dep[nax];
vector<pair<pii, int>> ans;
deque<int> ava;
vpii graf2[nax];
set<int> seen;
int n;

void dfs1(int x, int y, int d) {
    siz[x] = 1;
    dep[x] = d;
    for (int v : graf[x]) {
        if (v != y) {
            dfs1(v, x, d + 1);
            siz[x] += siz[v];
        }
    }
}

void dfs2(int x, int y, int d) {
    int t = ava.front();
    debug("pop %d\n", t);
    ava.pop_front();
    assert(t > d);
    ans.push_back(make_pair(make_pair(x, y), t - d));
    debug("%d %d %d %d\n", x, y, d, ans.back());
    for (int v : graf[x]) {
        if (v != y) {
            dfs2(v, x, t);
        }
    }
}

void dfs3(int x, int y, int d) {
    seen.insert(d);
    for (pii e : graf2[x]) {
        if (e.first != y) {
            dfs3(e.first, x, d + e.second);
        }
    }
}

void test_ans() {
    for (auto x : ans) {
        graf2[x.first.first].push_back(make_pair(x.first.second, x.second));
        graf2[x.first.second].push_back(make_pair(x.first.first, x.second));
    }
    FOR(i, 1, n) {
        dfs3(i);
    }
    debug("%d\n", seen.size());
    FOR(i, 1, n * n * 2 / 9) {
        assert(seen.count(i));
    }
}

int main() {
    scanf("%d", &n);
    if (n == 1) {
        return 0;
    }
    debug("%d\n", n * n * 2 / 9);
    REP(_, n - 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    dfs1(1, -1, 0);
    int M = n * 2 / 3;
    FOR(i, 1, n) {
        vector<pii> sizes = {{1, i}};
        int p = -1;
        for (int v : graf[i]) {
            if (dep[v] == dep[i] + 1) {
                sizes.push_back(make_pair(siz[v], v));
            }
            else {
                p = v;
            }
        }
        if (i != 1) {
            sizes.push_back(make_pair(n - siz[i], p));
        }
        debug("%d ", i);
        for (pii x : sizes) {
            debug("%d %d ", x.first, x.second);
        }
        debug("\n");
        bool good = true;
        for (pii x : sizes) {
            if (x.first > M) {
                good = false;
            }
        }
        if (good) {
            vpii v1, v2;
            sort(sizes.rbegin(), sizes.rend());
            int sum1 = 0, sum2 = 0;
            int whme = 0;
            debug("%d\n", sizes.size());
            for (pii c : sizes) {
                if (sum1 + c.first > M) {
                    v2.push_back(c);
                    sum2 += c.first;
                    if (c.second == i) {
                        whme = 2;
                    }
                }
                else {
                    v1.push_back(c);
                    sum1 += c.first;
                    if (c.second == i) {
                        whme = 1;
                    }
                }
                assert(sum1 <= M && sum2 <= M);
                debug("%d %d\n", sum1, sum2);
            }
            assert(sum1 * sum2 >= n * n * 2 / 9);
            assert(whme != 0);
            if (whme == 2) {
                debug("swap\n");
                swap(v1, v2);
                swap(sum1, sum2);
            }
            FOR(j, 1, sum1 - 1) {
                ava.push_back(j);
            }
            debug("%d\n", ava.size());
            debug("%d %d\n", v1.size(), v2.size());
            for (pii x : v1) {
                if (x.second != i) {
                    dfs2(x.second, i, 0);
                }
            }
            assert(ava.empty());
            REP(j, sum2) {
                ava.push_back(1 + j * sum1);
            }
            debug("%d\n", ava.size());
            for (pii x : v2) {
                dfs2(x.second, i, 0);
            }
            assert(ava.empty());
            for (auto x : ans) {
                printf("%d %d %d\n", x.first.first, x.first.second, x.second);
            }
            test_ans();
            return 0;
        }
        else {
            debug("err\n");
        }
    }
    assert(false);
}
