




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
struct node {
    LL p, d;
    bool operator < (const node &T) const {
        return d > T.d;
    }
};

int T;
LL n, m, k;
LL r1, r2, r3;
vector<pair<LL, LL>> v[100005];
LL dis[100005][25];
bool firm[100005][25];
LL dp[100005], ed[100005];

PQ<node> pq;
deque<int> dq;

void solve(int CASE) {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> r1 >> r2 >> r3;
        v[r1].push_back({r2, r3});
        v[r2].push_back({r1, r3});
    }
    memset(firm, 0, sizeof(firm));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dis[i][j] = 1e18;
        }
    }
    dis[1][0] = 0;
    for (int lay = 0; lay <= k; lay++) {
        while (pq.size()) pq.pop();
        for (int j = 1; j <= n; j++) {
            pq.push({j, dis[j][lay]});
        }
        while (pq.size()) {
            node t = pq.top();
            pq.pop();
            if (dis[t.p][lay] < t.d) continue;
            if (firm[t.p][lay]) continue;
            dis[t.p][lay] = t.d;
            firm[t.p][lay] = true;
            for (auto i : v[t.p]) {
                LL p = i.x;
                LL d = t.d + i.y;
                if (dis[p][lay] < d) continue;
                dis[p][lay] = d;
                pq.push({p, d});
            }
        }
        if (lay == k) continue;
        for (int i = 1; i <= n; i++) {
            dis[i][lay + 1] = dis[i][lay];
        }

        for (LL i = 1; i <= n; i++) {
            dp[i] = dis[i][lay] + i * i;
            ed[i] = 1e18;
        }

        while (dq.size()) dq.pop_back();
        dq.push_front(1);
        for (LL i = 2; i <= n; i++) {
            while (dq.size() > 1) {
                LL j = dq.front();
                dq.pop_front();
                int k = dq.front();
                if (dp[j] - dp[k] > 2 * i * (j - k)) {
                    continue;
                }
                else {
                    dq.push_front(j);
                    break;
                }
            }
            LL t = dq.front();
            

            ed[i] = min(ed[i], dp[t] - 2 * t * i);
            dq.push_back(i);
            while (dq.size() > 2) {
                LL l = dq.back();
                dq.pop_back();
                LL k = dq.back();
                dq.pop_back();
                LL j = dq.back();
                if ((long double)(dp[j] - dp[k]) * (k - l) > (long double) (j - k) * (dp[k] - dp[l])) {
                    dq.push_back(l);
                }
                else {
                    dq.push_back(k);
                    dq.push_back(l);
                    break;
                }
            }
        }

        while (dq.size()) dq.pop_back();
        dq.push_front(n);
        for (LL i = n - 1; i > 0; i--) {
            while (dq.size() > 1) {
                LL j = dq.front();
                dq.pop_front();
                int k = dq.front();
                if (dp[j] - dp[k] > 2 * i * (j - k)) {
                    continue;
                }
                else {
                    dq.push_front(j);
                    break;
                }
            }
            LL t = dq.front();
            ed[i] = min(ed[i], dp[t] - 2 * t * i);
            dq.push_back(i);
            while (dq.size() > 2) {
                LL l = dq.back();
                dq.pop_back();
                LL k = dq.back();
                dq.pop_back();
                LL j = dq.back();
                if ((long double)(dp[j] - dp[k]) * (k - l) <(long double) (j - k) * (dp[k] - dp[l])) {
                    dq.push_back(l);
                }
                else {
                    dq.push_back(k);
                    dq.push_back(l);
                    break;
                }
            }
        }
        for (LL i = 1; i <= n; i++) {
            dis[i][lay + 1] = min(dis[i][lay + 1], ed[i] + i * i);
            

        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dis[i][k] << (i == n? "\n":" ");
    }
    return;
}

int main() {
    T = 1;
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    

    

    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}
