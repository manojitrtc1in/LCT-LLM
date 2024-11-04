




using namespace std;








































struct matrix {
    int sz;
    LL a[105][105];
    matrix& operator = (const matrix &T) {
        sz = T.sz;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) {
                a[i][j] = T.a[i][j];
            }
        }
        return *this;
    }
    matrix operator + (const matrix &T) const {
        matrix ans;
        ans.sz = sz;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) {
                ans.a[i][j] = a[i][j] + T.a[i][j];
                ans.a[i][j] %= e;
            }
        }
        return ans;
    }
    matrix operator * (const matrix &T) const {
        matrix ans;
        ans.sz = sz;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) {
                ans.a[i][j] = 0;
                for (int k = 1; k <= sz; k++) {
                    ans.a[i][j] += a[i][k] * T.a[k][j];
                    ans.a[i][j] %= e;
                }
            }
        }
        return ans;
    }
    matrix I() {
        matrix ans;
        ans.sz = sz;
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) {
                if (i == j) ans.a[i][j] = 1;
                else ans.a[i][j] = 0;
            }
        }
        return ans;
    }
    matrix power(LL p) {
        if (p == 0) return I();
        if (p == 1) return *this;
        matrix tmp = power(p / 2);
        if (p % 2) tmp = tmp * tmp * (*this);
        else tmp = tmp * tmp;
        return tmp;
    }
    void print() {
        for (int i = 1; i <= sz; i++) {
            for (int j = 1; j <= sz; j++) {
                printf(j == sz? "%lld\n" : "%lld ", a[i][j]);
            }
        }
        return;
    }
};
struct polynomial {
    vector<Complex> v;
    int sz;
    polynomial operator * (const polynomial &T) const {
        polynomial ans;
        if (sz >= T.sz) {
            ans = *this;
            for (int i = 0; i < T.sz; i++) {
                ans.v[i] *= T.v[i];
            }
        }
        else {
            ans = T;
            for (int i = 0; i < sz; i++) {
                ans.v[i] *= v[i];
            }
        }
        return ans;
    }
};
polynomial FFT(polynomial a) {
    if (a.sz <= 1) return a;
    polynomial even, odd;
    even.sz = odd.sz = 0;
    for (int i = 0; i < a.sz; i += 2) {
        even.v.pb(a.v[i]);
        even.sz++;
    }
    for (int i = 1; i < a.sz; i += 2) {
        odd.v.pb(a.v[i]);
        odd.sz++;
    }
    polynomial Even = FFT(even);
    polynomial Odd = FFT(odd);
    polynomial ans;
    ans.sz = a.sz;
    for (int i = 0; i < ans.sz; i++) {
        ans.v.pb(0);
    }
    for (int i = 0; i < a.sz / 2; i++) {
        Complex w = polar(1.0, -2 * pi * i / a.sz) * Odd.v[i];
        ans.v[i] = Even.v[i] + w;
        ans.v[i + a.sz / 2] = Even.v[i] - w;
    }
    return ans;
}
polynomial IFFT(polynomial a) {
    for (int i = 0; i < a.sz; i++) {
        a.v[i] = conj(a.v[i]);
    }
    polynomial ans = FFT(a);
    for (int i = 0; i < a.sz; i++) {
        ans.v[i] = conj(ans.v[i]);
        ans.v[i] /= ans.sz;
    }
    return ans;
}
struct polygon {
    int n;
    pii a[1005];
    double area() {
        double d1 = 0, d2 = 0;
        for (int i = 0; i < n; i++) {
            d1 += a[i].x * a[(i + 1) % n].y;
            d2 += a[(i + 1) % n].x * a[i].y;
        }
        return (d1 - d2) / 2;
    }
    bool inside(pldld p) {
        int ct = 0;
        LD d;
        pldld p1 = a[0];
        for (int i = 1; i <= n; i++) {
            pldld p2 = a[i % n];
            if (p.y > min(p1.y, p2.y) && p.y <= max(p1.y, p2.y) && p.x <= max(p1.x, p2.x) && p1.y != p2.y) {
                d = (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
                if (p1.x == p2.x || p.x <= d) ct++;
            }
            p1 = p2;
        }
        return ct % 2;
    }
};
struct graph {
    
    int n;
    vi v[SZ];
    int vis[SZ], low[SZ], t;
    int indeg[SZ];
    stack<int> st;
    int top = 0;
    bool instack[SZ];
    int to[SZ];
    void tarjanDFS(int x) {
        vis[x] = low[x] = ++t;
        st.push(x);
        instack[x] = true;
        for (auto i : v[x]) {
            if (!vis[i]) tarjanDFS(i);
            if (instack[i]) { 

                low[x] = min(low[x], low[i]);
            }
        }
        if (vis[x] == low[x]) { 

            int i;
            do {
                i = st.top();
                st.pop();
                instack[i] = false;
                to[i] = x;
            } while (i != x);
        }
    }
    void tarjan() {
        memset(vis, 0, sizeof(vis));
        t = 0;
        for (int i = 1; i <= n; i++) { 

            if (!vis[i]) tarjanDFS(i);
        }
        return;
    }
    void calIndeg() {
        for (int i = 1; i <= n; i++) { 

            for (auto j : v[i]) indeg[j]++;
        }
        return;
    }
};
struct id0 {
    int l, r, mid;
    LL val = 0, lazy = 0;
    id0 *lc, *rc;
    id0(int L, int R) {
        l = L;
        r = R;
        mid = (l + r) / 2;
        if (l != r) {
            lc = new id0(l, mid);
            rc = new id0(mid + 1, r);
        }
    }
    void apply(LL X) {
        val += X;
        

        lazy += X;
    }
    void push() {
        if (l == r) return;
        lc->apply(lazy);
        rc->apply(lazy);
        lazy = 0;
    }
    void update(int L, int R, LL X) {
        push();
        if (l == L && r == R) {
            apply(X);
            return;
        }
        else if (R <= mid) lc->update(L, R, X);
        else if (L >= mid + 1) rc->update(L, R, X);
        else {
            lc->update(L, mid, X);
            rc->update(mid + 1, R, X);
        }
        val = min(lc->val, rc->val);
        

    }
    LL query(int L, int R) {
        push();
        if (l == L && r == R) return val;
        else if (R <= mid) return lc->query(L, R);
        else if (L >= mid + 1) return rc->query(L, R);
        else {
            return min(lc->query(L, mid), rc->query(mid + 1, R));
            

        }
    }
    

} *segroot;
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
    uniform_int_distribution<int> uni(l, r);
    return uni(rng);
}
vl fac, inv;
LL power(LL a, LL p) {
    LL ans = 1;
    while (p) {
        if (p & 1) ans = ans * a % MOD;
        p >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
vl inverse(int n) {
    vl ans(n + 1);
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[MOD % i] * (MOD - MOD / i) % MOD;
    }
    return ans;
}
vl factorial(int n) {
    vl ans(n + 1);
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = ans[i - 1] * i % MOD;
    }
    return ans;
}
vl id1(int n) {
    vl inv = inverse(n);
    vl ans(n + 1);
    ans[0] = ans[1] = 1;
    for (int i = 2; i <= n; i++) {
        ans[i] = inv[i] * ans[i - 1] % MOD;
    }
    return ans;
}
LL ncr(int n, int r) {
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}
void id2(int n) {
    fac = factorial(n);
    inv = id1(n);
    return;
}
struct query {
    LL sx, sy, ex, ey, slay, elay, id;
};

bool coms(query q1, query q2) {
    return q1.slay < q2.slay;
}

bool come(query q1, query q2) {
    return q1.elay < q2.elay;
}

int T;
LL n, m;
pair<LL, LL> da[100005];
pair<LL, LL> db[100005];
LL sx, sy, ex, ey;
query Q[200005];
LL ans[200005];
LL dis[100005][20][2][2];

void solve(int CASE) {
    rl(n);
    for (int i = 1; i < n; i++) {
        rll(da[i].x, da[i].y);
        rll(db[i].x, db[i].y);
    }
    for (int i = 1; i < n; i++) {
        dis[i][0][0][0] = 1 + abs(da[i].y - da[i + 1].y);
        dis[i][0][0][1] = 1 + abs((da[i].x + 1) - db[i + 1].x) + abs(da[i].y - db[i + 1].y);
        dis[i][0][1][0] = 1 + abs((db[i].y + 1) - da[i + 1].y) + abs(db[i].x - da[i + 1].x);
        dis[i][0][1][1] = 1 + abs(db[i].x - db[i + 1].x);
    }
    for (int i = 1; i <= 17; i++) {
        for (int j = 1; j <= n; j++) {
            LL tar = j + (1 << i);
            if (tar > n) break;
            LL nt = j + (1 << (i - 1));
            dis[j][i][0][0] = min(
                dis[j][i - 1][0][0] + dis[nt][i - 1][0][0],
                dis[j][i - 1][0][1] + dis[nt][i - 1][1][0]
            );
            dis[j][i][0][1] = min(
                dis[j][i - 1][0][0] + dis[nt][i - 1][0][1],
                dis[j][i - 1][0][1] + dis[nt][i - 1][1][1]
            );
            dis[j][i][1][0] = min(
                dis[j][i - 1][1][0] + dis[nt][i - 1][0][0],
                dis[j][i - 1][1][1] + dis[nt][i - 1][1][0]
            );
            dis[j][i][1][1] = min(
                dis[j][i - 1][1][0] + dis[nt][i - 1][0][1],
                dis[j][i - 1][1][1] + dis[nt][i - 1][1][1]
            );
        }
    }
    rl(m);
    for (int i = 1; i <= m; i++) {
        rll(sx, sy);
        rll(ex, ey);
        Q[i] = {sx, sy, ex, ey, max(sx, sy), max(ex, ey), i};
        ans[i] = 0;
        if (Q[i].slay == Q[i].elay) {
            ans[i] = abs(sx - ex) + abs(sy - ey);
            continue;
        }
        if (Q[i].slay > Q[i].elay) {
            Q[i] = {ex, ey, sx, sy, max(ex, ey), max(sx, sy), i};
            swap(sx, ex);
            swap(sy, ey);
        }
        

        LL mn = 1e18;
        LL s0 = abs(sx - da[Q[i].slay].x) + abs(sy - da[Q[i].slay].y);
        

        LL s1 = abs(sx - db[Q[i].slay].x) + abs(sy - db[Q[i].slay].y);
        LL e0 = 1 + abs(ex - (da[Q[i].elay - 1].x + 1)) + abs(ey - da[Q[i].elay - 1].y);
        LL e1 = 1 + abs(ex - db[Q[i].elay - 1].x) + abs(ey - (db[Q[i].elay - 1].y + 1));
        

        

        

        

        LL sum[2][2], tmp[2][2];
        sum[0][0] = sum[0][1] = sum[1][0] = sum[1][1] = 0;
        bool once = false;
        for (int j = 17; j >= 0; j--) {
            LL add = (1 << j);
            if (Q[i].slay + add >= Q[i].elay) continue;
            if (!once) {
                once = true;
                sum[0][0] = dis[Q[i].slay][j][0][0];
                sum[0][1] = dis[Q[i].slay][j][0][1];
                sum[1][0] = dis[Q[i].slay][j][1][0];
                sum[1][1] = dis[Q[i].slay][j][1][1];
                

                

                

                

                Q[i].slay += add;
                continue;
            }
            tmp[0][0] = min(
                sum[0][0] + dis[Q[i].slay][j][0][0],
                sum[0][1] + dis[Q[i].slay][j][1][0]  
            );
            tmp[0][1] = min(
                sum[0][0] + dis[Q[i].slay][j][0][1],
                sum[0][1] + dis[Q[i].slay][j][1][1]  
            );
            tmp[1][0] = min(
                sum[1][0] + dis[Q[i].slay][j][0][0],
                sum[1][1] + dis[Q[i].slay][j][1][0]  
            );
            tmp[1][1] = min(
                sum[1][0] + dis[Q[i].slay][j][0][1],
                sum[1][1] + dis[Q[i].slay][j][1][1]  
            );
            Q[i].slay += add;
            sum[0][0] = tmp[0][0];
            sum[0][1] = tmp[0][1];
            sum[1][0] = tmp[1][0];
            sum[1][1] = tmp[1][1];
        }
        if (once) mn = min(
            min(
                s0 + sum[0][0] + e0,
                s0 + sum[0][1] + e1
            ),
            min(
                s1 + sum[1][0] + e0,
                s1 + sum[1][1] + e1
            )
        );
        else mn = min(s0 + e0, s1 + e1);
        ans[i] = mn;
    }
    for (int i = 1; i <= m; i++) {
        printl(ans[i]);
        enter;
    }
    return;
}

int main() {
    T = 1;
    

    

    

    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}