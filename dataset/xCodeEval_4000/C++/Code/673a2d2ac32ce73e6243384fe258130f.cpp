

#include <deque>
#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <fstream>
#include <random>
#include <queue>
#include <complex>
#include <ctime>







using namespace std;
using namespace __gnu_pbds;













#define ll long long
#define double long double
typedef complex<double> cld;

typedef tree<
        pair<int, int>,
        null_type,
        less< pair <int, int> >,
        rb_tree_tag,
        tree_order_statistics_node_update
> ordered_set;

template<typename T>
ostream &operator<<(ostream &ws, const vector<T> &v) {
    for (auto e: v) {
        ws << e << " ";
    }
    return ws;
}



const ll mod = 1000000007;




mt19937 rnd;







struct seg_tr {
    vector<int> t, p;

    void push(int v) {
        if (p[v] != 0) {
            t[v * 2] += p[v];
            t[v * 2 + 1] += p[v];
            p[v * 2] += p[v];
            p[v * 2 + 1] += p[v];
            p[v] = 0;
        }
    }

    void update(int v, int l, int r, int tl, int tr, int val) {
        if (tl >= r || tr <= l) {
            return;
        }
        if (tl >= l && tr <= r) {
            t[v] += val;
            p[v] += val;
            return;
        }

        push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, l, r, tl, tm, val);
        update(v * 2 + 1, l, r, tm, tr, val);
        t[v] = min(t[v * 2], t[v * 2 + 1]);
    }

    int quer(int v, int l, int r, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return -1;
        }
        if (tl >= l && tr <= r && t[v] >= 0) {
            return -1;
        }
        if (tl + 1 == tr) {
            return tl;
        }

        push(v);
        int tm = (tl + tr) / 2;
        int get = quer(v * 2 + 1, l, r, tm, tr);
        if (get == -1) {
            return quer(v * 2, l, r, tl, tm);
        }
        return get;
    }

    
};





struct merge_tree{
    vector < vector <int> > t;

    void build(int v, int tl, int tr, vector <int> &h){
        if(tl + 1 == tr){
            t[v].push_back(h[tl]);
            return;
        }

        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, h);
        build(v * 2 + 1, tm, tr, h);
        t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
        merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
    }

    int quer(int v, int l, int r, int tl, int tr, int x){
        if(tl >= r || tr <= l){
            return 0;
        }
        if(tl >= l && tr <= r){
            return lower_bound(t[v].begin(), t[v].end(), x) - t[v].begin();
        }

        int tm = (tl + tr) / 2;
        return quer(v * 2, l, r, tl, tm, x) + quer(v * 2 + 1, l, r, tm, tr, x);
    }
};



struct val {
    int l, r, val;
};

const double pi = 3.14159265358979323846;

int binpow(int x, int k) {
    if (k == 0) {
        return 1;
    }
    int y = binpow(x, k / 2);
    if (k % 2 == 0) {
        return (y * y) % mod;
    } else {
        return (((y * y) % mod) * x) % mod;
    }
}



struct elem {
    int l, r, g;
};

double rand_double() {
    return (double) rand() / RAND_MAX;
}





struct seg_tree {
    vector <int> t;
    


    

    void build(int v, int tl, int tr, vector <int> & h){
        if(tl + 1 == tr){
            t[v] = h[tl];
            return;
        }

        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, h);
        build(v * 2 + 1, tm, tr, h);
        

        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    void update(int v, int pos, int tl, int tr, int val) {
        if (tl > pos || tr <= pos) {
            return;
        }
        if (tl == pos && tl + 1 == tr) {
            t[v] = val;
            

            return;
        }

        

        int tm = (tl + tr) / 2;
        update(v * 2, pos, tl, tm, val);
        update(v * 2 + 1, pos, tm, tr, val);
        

        t[v] = t[v * 2] + t[v * 2 + 1];
    }

    int quer(int v, int l, int r, int tl, int tr) {
        if (tl >= r || tr <= l) {
            return 0;
        }
        if (tl >= l && tr <= r) {
            return t[v];
        }

        

        int tm = (tl + tr) / 2;
        

        return quer(v * 2, l, r, tl, tm) + quer(v * 2 + 1, l, r, tm, tr);
    }
};

struct line {
    int A, B, C;
    pair <int, int> k;

    void do_line(int x1, int y1, int x2, int y2) {
        A = y1 - y2;
        B = x2 - x1;
        C = x1 * y2 - x2 * y1;

        int d = gcd(abs(A), abs(B));
        if(A == 0){
            k = {1000000000, 1000000000};
        }else{
            if(B == 0){
                k = {-1000000000, 1000000000};
            }else{
                if(A * B > 0){
                    k = {abs(A) / d, abs(B) / d};
                }else{
                    k = {-abs(A) / d, abs(B) / d};
                }
            }
        }
    }

    bool check(int x, int y) {
        return A * x + B * y + C == 0;
    }
};

void solve() {
    int n;
    cin >> n;

    vector <int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector <int> cnt(n + 1);
    vector < vector <int> > dp(n + 1, vector <int> (2, -1e9));
    for(int i = 0; i < n; ++i){
        int mx = 0, y = 0;
        cnt.assign(n + 1, 0);
        for(int j = i - 1; j >= 0; --j){
            if(a[j] == a[i]){
                int len = (i - 1) - (j + 1) + 1;
                if(len % 2 == 0){
                    if(y == a[i] || mx <= len / 2){
                        dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]) + 1);
                    }
                }else{
                    int mx1 = mx, y1 = y;
                    if(cnt[a[i]] + 1 > mx1){
                        mx1 = cnt[a[i]] + 1;
                        y1 = a[i];
                    }

                    if(y1 == a[i] || mx1 <= (len + 1) / 2){
                        dp[i][1] = max(dp[i][1], max(dp[j][0], dp[j][1]));
                    }
                }
            }
            cnt[a[j]]++;
            if(mx < cnt[a[j]]){
                mx = cnt[a[j]];
                y = a[j];
            }
            if(a[j] == a[i]){
                int len = (i - 1) - j + 1;
                if(len % 2 == 0){
                    if(y == a[i] || mx <= len / 2){
                        dp[i][0] = max(dp[i][0], dp[j][0]);
                    }
                }else{
                    int mx1 = mx, y1 = y;
                    if(cnt[a[i]] + 1 > mx1){
                        mx1 = cnt[a[i]] + 1;
                        y1 = a[i];
                    }

                    if(y1 == a[i] || mx1 <= (len + 1) / 2){
                        dp[i][1] = max(dp[i][1], dp[j][0] - 1);
                    }
                }
            }
        }

        


        int len = i;
        if(len % 2 == 0){
            if(y == a[i] || mx <= len / 2){
                dp[i][0] = max(dp[i][0], 1);
            }
        }else{
            int mx1 = mx, y1 = y;
            if(cnt[a[i]] + 1 > mx1){
                mx1 = cnt[a[i]] + 1;
                y1 = a[i];
            }

            if(y1 == a[i] || mx1 <= (len + 1) / 2){
                dp[i][1] = max(dp[i][1], 0);
            }
        }
    }

    for(int x = 1; x <= n; ++x){
        int i = n;
        a.push_back(x);
        int mx = 0, y = 0;
        cnt.assign(n + 1, 0);
        for(int j = i - 1; j >= 0; --j){
            if(a[j] == a[i]){
                int len = (i - 1) - (j + 1) + 1;
                if(len % 2 == 0){
                    if(y == a[i] || mx <= len / 2){
                        dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]));
                    }
                }
            }
            cnt[a[j]]++;
            if(mx < cnt[a[j]]){
                mx = cnt[a[j]];
                y = a[j];
            }
            if(a[j] == a[i]){
                int len = (i - 1) - j + 1;
                if(len % 2 == 0){
                    if(y == a[i] || mx <= len / 2){
                        dp[i][0] = max(dp[i][0], dp[j][0] - 1);
                    }
                }
            }
        }

        int len = i;
        if(len % 2 == 0){
            if(y == a[i] || mx <= len / 2){
                dp[i][0] = max(dp[i][0], 0);
            }
        }

        a.pop_back();
    }

    

    cout << max(0, dp[n][0]) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(20);
#ifndef DEBUG
    

    

#endif

    


    


    ll tests = 1;
    cin >> tests;
    while (tests--) {
        solve();
    }
}