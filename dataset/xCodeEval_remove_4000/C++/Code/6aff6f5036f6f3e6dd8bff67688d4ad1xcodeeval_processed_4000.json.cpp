




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
struct edge {
    int u, v, l;
    bool del;
    int old1, old2;
    int ans;
    bool operator < (const edge &T) const {
        return u < T.u;
    }
};

int T;
int n, m;
int r1, r2, r3, ep;
edge E[200005];
vector<pii> odd[100005], even[100005];
queue<int> q;
bool inq[100005];
bool vis[100005];
int ans;
int sum[100005];

int go(int x) {
    vis[x] = true;
    for (auto i : odd[x]) {
        if (E[i.y].del) continue;
        if (vis[i.x]) continue;
        return go(i.x);
    }
    for (auto i : even[x]) {
        if (E[i.y].del) continue;
        if (vis[i.x]) continue;
        return go(i.x);
    }
    return x;
}   

void f(int x) {
    vis[x] = true;
    for (auto i : odd[x]) {
        if (E[i.y].del) continue;
        if (!E[i.y].ans) {
            if (E[i.y].u == x) {
                E[i.y].ans = 1;
                f(E[i.y].v);
            }
            else {
                E[i.y].ans = 2;
                f(E[i.y].u);
            }
        }
    }
    for (auto i : even[x]) {
        if (E[i.y].del) continue;
        if (!E[i.y].ans) {
            if (E[i.y].u == x) {
                E[i.y].ans = 1;
                f(E[i.y].v);
            }
            else {
                E[i.y].ans = 2;
                f(E[i.y].u);
            }
        }
    }
    return;
}

void solve(int CASE) {
    rii(n, m);
    for (int i = 1; i <= m; i++) {
        riii(r1, r2, r3);
        sum[r1] += r3;
        sum[r2] += r3;
        E[i] = {r1, r2, r3, false, 0, 0, 0};
        if (r3 == 1) {
            odd[r1].pb({r2, i});
            odd[r2].pb({r1, i});
        }
        else {
            even[r1].pb({r2, i});
            even[r2].pb({r1, i});
        }
    }
    for (int i = 1; i <= n; i++) {
        if (sum[i] % 2) ans++;
    }
    ep = m;
    for (int i = 1; i <= n; i++) {
        if (odd[i].size() > 1 || even[i].size() > 1) {
            q.push(i);
            inq[i] = true;
        }
    }
    while (q.size()) {
        int tmp = q.front();
        q.pop();
        inq[tmp] = false;
        while (odd[tmp].size() >= 2) {
            pii t1 = {0, 0};
            pii t2 = {0, 0};
            t1 = odd[tmp][odd[tmp].size() - 1];
            while (E[t1.y].del) {
                odd[tmp].pop_back();
                t1 = {0, 0};
                if (!odd[tmp].size()) break;
                t1 = odd[tmp][odd[tmp].size() - 1];
            }
            if (!t1.y) break;
            odd[tmp].pop_back();
            if (odd[tmp].size()) {
                t2 = odd[tmp][odd[tmp].size() - 1];
                while (E[t2.y].del) {
                    odd[tmp].pop_back();
                    t2 = {0, 0};
                    if (!odd[tmp].size()) break;
                    t2 = odd[tmp][odd[tmp].size() - 1];
                }
            }
            if (!t2.y) {
                odd[tmp].push_back(t1);
                break;
            }
            odd[tmp].pop_back();
            E[t1.y].del = E[t2.y].del = true;
            if (t1.x == t2.x) {
                if (E[t1.y].u == E[t2.y].u) {
                    E[t1.y].ans = 1;
                    E[t2.y].ans = 2;
                }
                else {
                    E[t1.y].ans = 1;
                    E[t2.y].ans = 1;
                }
                continue;
            }
            E[++ep] = {t1.x, t2.x, 1, false, t1.y, t2.y, 0};
            

            odd[t1.x].push_back({t2.x, ep});
            odd[t2.x].push_back({t1.x, ep});
            if (odd[t1.x].size() > 1 && !inq[t1.x]) {
                q.push(t1.x);
                inq[t1.x] = true;
            }
            if (odd[t2.x].size() > 1 && !inq[t2.x]) {
                q.push(t2.x);
                inq[t2.x] = true;
            }
        }
        while (even[tmp].size() >= 2) {
            pii t1 = {0, 0};
            pii t2 = {0, 0};
            t1 = even[tmp][even[tmp].size() - 1];
            while (E[t1.y].del) {
                even[tmp].pop_back();
                t1 = {0, 0};
                if (!even[tmp].size()) break;
                t1 = even[tmp][even[tmp].size() - 1];
            }
            if (!t1.y) break;
            even[tmp].pop_back();
            if (even[tmp].size()) {
                t2 = even[tmp][even[tmp].size() - 1];
                while (E[t2.y].del) {
                    even[tmp].pop_back();
                    t2 = {0, 0};
                    if (!even[tmp].size()) break;
                    t2 = even[tmp][even[tmp].size() - 1];
                }
            }
            if (!t2.y) {
                even[tmp].push_back(t1);
                break;
            }
            even[tmp].pop_back();
            E[t1.y].del = E[t2.y].del = true;
            if (t1.x == t2.x) {
                if (E[t1.y].u == E[t2.y].u) {
                    E[t1.y].ans = 1;
                    E[t2.y].ans = 2;
                }
                else {
                    E[t1.y].ans = 1;
                    E[t2.y].ans = 1;
                }
                continue;
            }
            E[++ep] = {t1.x, t2.x, 2, false, t1.y, t2.y, 0};
            

            even[t1.x].push_back({t2.x, ep});
            even[t2.x].push_back({t1.x, ep});
            if (even[t1.x].size() > 1 && !inq[t1.x]) {
                q.push(t1.x);
                inq[t1.x] = true;
            }
            if (even[t2.x].size() > 1 && !inq[t2.x]) {
                q.push(t2.x);
                inq[t2.x] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        int st = go(i);
        f(st);
    }
    for (int i = ep; i > m; i--) {
        if (E[i].old1 != 0) {
            

            if (E[i].ans == 1) {
                if (E[E[i].old1].u == E[i].u) E[E[i].old1].ans = 1;
                else E[E[i].old1].ans = 2;
                if (E[E[i].old2].u == E[i].v) E[E[i].old2].ans = 2;
                else E[E[i].old2].ans = 1;
            }
            else {
                if (E[E[i].old1].u == E[i].u) E[E[i].old1].ans = 2;
                else E[E[i].old1].ans = 1;
                if (E[E[i].old2].u == E[i].v) E[E[i].old2].ans = 1;
                else E[E[i].old2].ans = 2;
            }
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= m; i++) {
        printf("%d", E[i].ans);
    }
    printf("\n");
    return;
}

int main() {
    T = 1;
    

    

    

    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}